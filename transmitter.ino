int x;
int y;

void setup()
{
  Serial.begin(4800);
  
  pinMode(x,INPUT);
  pinMode(y,INPUT);
}

void loop()
{
  x = 100;
  y = 420;
  
  if(x<250)
   Serial.print('s');
   
  else if(x>420)
   Serial.print('w');
   
  else if(y>400)
   Serial.print('a'); 
  
  else if(y<240)
   Serial.print('d');
   
  else
  Serial.print('n');
   
   delay(100);
}

