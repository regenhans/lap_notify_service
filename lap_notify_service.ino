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
  Serial.println(".");
  Serial.println();
  if(distance < 40){
    Serial.println("lap found");
    Serial.println();
    digitalWrite(NOTIFYPIN, HIGH); 
    delay(1000);
    digitalWrite(NOTIFYPIN, LOW);
    delay(2500); //average wall return time
  }
  
  delay(50);
}