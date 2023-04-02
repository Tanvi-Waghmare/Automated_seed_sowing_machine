#define echoPin 10 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 11 //attach pin D3 Arduino to pin Trig of HC-SR04
const int max_allowed_distance = 20;
// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
// Motor A
int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B
int enB = 3;
int in3 = 5;
int in4 = 4;
void setup()
{
 Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
Serial.println("check Ultrasonic Sensor HC-SR04 working with bot"); // print some text in Serial Monitor
  // Set all the motor control pins to outputs
              pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
}
int cal_distance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}void demoOne()
{
  // Now turn off motors
                analogWrite(enA, 150);
  analogWrite(enB, 150);
  delay(20);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void loop()
{
if (cal_distance()<max_allowed_distance)
{
  analogWrite(enA, LOW);
  analogWrite(enB, LOW);
  delay(500);

}
else
{
  delay(100);
 demoOne();
}
  
}
