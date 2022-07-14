const int trigPin = 12;
const int echoPin = 14;
const int relay = 5;

//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(relay, OUTPUT);
}

void loop() {
  // Clears the trigPin
  float dis=0;
  for(int i=1;i<=5;i++)
  {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  dis+=distanceCm;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  
  delay(100);
  }
  dis/=5;
  Serial.print("Average Distance (cm) : ");
  Serial.println(dis);
  if(dis>=6)
  {
    digitalWrite(relay, LOW);
    Serial.println("Current Flowing");
    delay(5000);
  }
  if(dis<4)
  {
    digitalWrite(relay, HIGH);
    Serial.println("Current not Flowing");
    delay(5000);
  }
  delay(1000);
}
