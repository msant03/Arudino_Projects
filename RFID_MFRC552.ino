#include <MFRC522.h>        //RFID MFRC522 Library
#include <SPI.h>            //the library for the SPI buses on the SD card and RFID

#define SS_PIN 10           //aka SDA
#define RST_PIN 9             

MFRC522 mfrc522(SS_PIN, RST_PIN);     // Create MFRC522 instance so that it can read the RFID cards

void setup() {
  SPI.begin();                        // Initiate  SPI bus
  mfrc522.PCD_Init();                 // Initiate MFRC522
  Serial.begin(9600);                 //Start Serial Monitor
  Serial.println("Scan your RFID card to begin");
}

void loop() 
{
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  if(content.substring(1) == "3C 8E 53 73")     //Change this to work with the UID of the card you are using
  {
    Serial.println("Hello Megan!");
  }
}
