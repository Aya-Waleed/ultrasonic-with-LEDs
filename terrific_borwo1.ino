 int trigPin = 2;    // Trig pin of ultrasonic sensor
 int echoPin = 3;    // Echo pin of ultrasonic sensor
long t,d;
void setup() {
  Serial.begin(9600);
  for (int i = 4; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  
  t = pulseIn(echoPin, HIGH);
  
  d = t * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(d);
  Serial.println(" cm");
  if (d<=100){
    digitalWrite(4, HIGH);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
  }else if(d<=200){
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
  }else if(d<=300){
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, 0);
   }else if(d<=400){
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);}
  else{
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);}
  delay(400);
}