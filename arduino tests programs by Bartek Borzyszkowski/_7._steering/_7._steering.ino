#define m11 2
#define m12 3
#define m21 6
#define m22 7

void setup()
{
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available())
  {
    char In=Serial.read();
    Serial.print(In);
    if(In=='f' || In=='F' || In==1 || In=='1')            // Forward
    {
      digitalWrite(m11, HIGH);
      digitalWrite(m12, LOW);
      digitalWrite(m21, HIGH);
      digitalWrite(m22, LOW);
    }
    
     else if(In=='b' || In=='B' || In==2 || In=='2')            //backward
    {
      digitalWrite(m11, LOW);
      digitalWrite(m12, HIGH);
      digitalWrite(m21, LOW);
      digitalWrite(m22, HIGH);
    }

    else if(In=='l' || In=='L'|| In==3 || In=='3')     // Left
    {
      digitalWrite(m11, LOW);
      digitalWrite(m12, LOW);
      digitalWrite(m21, HIGH);
      digitalWrite(m22, LOW);
    }
    
     else if(In=='r' || In=='R'|| In==4 || In=='4')     // Right
    {
      digitalWrite(m11, HIGH);
      digitalWrite(m12, LOW);
      digitalWrite(m21, LOW);
      digitalWrite(m22, LOW);
    }
        
     else if(In=='s' || In=='S' || In==5 || In=='5')    // stop
    {
      digitalWrite(m11, LOW);
      digitalWrite(m12, LOW);
      digitalWrite(m21, LOW);
      digitalWrite(m22, LOW);
    }
    
    else
    {
      
    }
  }
}
