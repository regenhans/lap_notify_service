#define ECHOPIN 2
#define TRIGPIN 3
#define NOTIFYPIN 8
void setup(){
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(NOTIFYPIN,OUTPUT);
  digitalWrite(ECHOPIN, HIGH);
}
void loop(){
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  int distance = pulseIn(ECHOPIN, HIGH,26000);
  distance= distance/58;
  
  if(distance < 40){
    Serial.print(distance);
    Serial.println("lap found");
    digitalWrite(NOTIFYPIN, HIGH); 
    delayMicroseconds(10);
    digitalWrite(NOTIFYPIN, LOW);
  }
  
  delay(50);
}
