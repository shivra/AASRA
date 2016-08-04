/*pin 3 to receive pulse and pin 2 to send trigpulse*/
#define ECHOPIN 3
#define TRIGPIN 2

void setup() {
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

void loop() {
  /*to start range*/
  digitalWrite(TRIGPIN,LOW);
  delayMicroseconds(3);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW);

  float distance = pulseIn(ECHOPIN,HIGH);
  distance=distance/57;
  Serial.print(distance);
  Serial.println("cm");
  delay(300);
  }
