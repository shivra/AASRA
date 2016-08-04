#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

void setup()
{
    Serial.begin(9600);  
    pinMode(2,OUTPUT);//NEW
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(3,OUTPUT);
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    //digitalWrite(2,HIGH);
    uint8_t buf[12];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) 
    {

  driver.printBuffer("Got:", buf, buflen);
  if(buf[0]==97)
   {
    digitalWrite(9,LOW);
    digitalWrite(3,LOW);
    digitalWrite(7,LOW);
    digitalWrite(6,HIGH);
    //digitalWrite(2,HIGH);
    digitalWrite(2,LOW);//latest
    //delay(1000);
    }
  else if (buf[0]==102) 
   {
    //digitalWrite(2,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(3,LOW);
    digitalWrite(2,HIGH);//latest
    digitalWrite(7,HIGH);
    //delay(700);
    }
  else if (buf[0]==114)
  {
    digitalWrite(2,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(3,LOW);
    digitalWrite(9,HIGH);
    //delay(700);
    }
  else if (buf[0]==105)
  {
    digitalWrite(2,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(9,LOW);
    digitalWrite(3,HIGH);
    //delay(100);
    }
  else if (buf[0]==119)
  {
    digitalWrite(2,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(9,LOW);
    digitalWrite(3,LOW);
    //delay(700);
    }
    delay(1000);
  }
}

