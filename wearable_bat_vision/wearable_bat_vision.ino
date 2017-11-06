int trigpin = 8;
int echopin = 9;
float distance;
float duration;
int buzzer1 = 13;
int buzzer2 = 12;
void setup() {
  Serial.begin(9600);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
}

void loop() {
  //ultrasonic sensor
  digitalWrite(trigpin, LOW);
  delay(2000);
  digitalWrite(trigpin, HIGH);
  delay(500);
  digitalWrite(trigpin, LOW);
  duration= pulseIn(echopin, HIGH);
  distance = duration/58.2;
  Serial.println("\ndistance(in cm) = ");
  Serial.println(distance);


  
  if (distance <= 50)
  {
    Serial.println("\n CRITICAL DISTANCE....STOP\n");
digitalWrite(buzzer1, HIGH);
digitalWrite(buzzer2, HIGH);
delay(500);
digitalWrite(buzzer1, LOW);
digitalWrite(buzzer2, LOW);
delay(200);

digitalWrite(buzzer1, HIGH);
digitalWrite(buzzer2, HIGH);
delay(500);
digitalWrite(buzzer1, LOW);
digitalWrite(buzzer2, LOW);
delay(200);

digitalWrite(buzzer1, HIGH);
digitalWrite(buzzer2, HIGH);
delay(500);
digitalWrite(buzzer1, LOW);
digitalWrite(buzzer2, LOW);
delay(200);

 }
  
  else if (distance < 90 ){
  Serial.println("\n obstacle near-by\n");
 digitalWrite(buzzer1, HIGH);
digitalWrite(buzzer2, HIGH);
delay(500);
digitalWrite(buzzer1, LOW);
digitalWrite(buzzer2, LOW);
delay(500);
 }
 
  else if ( distance >= 90)
  {
  Serial.println("\n No obstacle found....SAFE PATH... \n"); 

digitalWrite(buzzer1, LOW);
digitalWrite(buzzer2, LOW);
delay(200);}
   
  }

