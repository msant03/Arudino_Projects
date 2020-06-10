//each ultrasonic sensor has a trig and echo pin:

const int trigPin = 7;      //first utrasonic sensor. 
const int echoPin = 8;

//ultrasonic sensors work by sending and receiving waves. So, the duration measures the
//time from when these waves were sent and received. 

double duration;                  //first ultrasonic sensor
int distance;

int LED_PIN = 9;                 //these are my LEDs that alert the user about the general distance away from the ultrasonic sensor that they are at
int LED_PIN2 = 10;               //if they are closer to the sensor, only one LED will light up. As they get further away, two LEDs and then all three LEDs will light up
int LED_PIN3 = 11;  

void setup() {
  Serial.begin(9600);             //start the Serial Monitor
  pinMode(trigPin, OUTPUT);       // Set the trigPins as Outputs (sending wave)
  pinMode(echoPin, INPUT);        // Set the echoPins as Inputs (receiving wave)
  pinMode(LED_PIN, OUTPUT);       //set the LEDs as outputs
  pinMode(LED_PIN2, OUTPUT);  
  pinMode(LED_PIN3, OUTPUT);
}

void loop() 
{
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(LED_PIN, LOW);         //turn off all LEDs
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, LOW);
  
  digitalWrite(trigPin, HIGH);        //calculate the distance    
  delayMicroseconds(20);                     
  digitalWrite(trigPin, LOW);                
  duration = pulseIn(echoPin, HIGH);         
  distance= duration*0.034/2;         //in centimeters
  
  Serial.println(distance);
  
  if(distance > 5)
  {
    digitalWrite(LED_PIN, HIGH);
  }
  if(distance > 15)
  {
    digitalWrite(LED_PIN2, HIGH);
  }
  if(distance > 25)
  {
    digitalWrite(LED_PIN3, HIGH);      
  }
  delay(5000); //delay so that you can see the LEDs
}
