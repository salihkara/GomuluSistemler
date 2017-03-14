#include <QTRSensors.h>
#define NUM_SENSORS  8
#define EMITTER_PIN 8
#define PWMa 7
#define a1 5
#define a2 4
#define PWMb 6
#define b1 3
#define b2 2

QTRSensorsAnalog qtrrc((unsigned char[]) {  A0, A1, A2, A3, A4, A5, A6,A7 } , NUM_SENSORS, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];

void setup()
{
  Serial.begin(9600);
  
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(PWMa, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(PWMb, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  
  for (int i = 0; i < 250; i++)
  {
    qtrrc.calibrate();
    digitalWrite(11,HIGH);
    delay(10);  
    digitalWrite(11,LOW);
  }
  delay(1000);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
}
void loop()
{
  unsigned int sensors[8];
  int position = qtrrc.readLine(sensors);
  
  if(position<200)
    {
   digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,90);                                                                                                                                           
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,0);
    }
  else  if(position<800)
    {
   digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,100);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,30);
    }
    else if(position<1300)
     {
   digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,110);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,60);  
    }
      else if(position<1800)
   {
     digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,120);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,80);
    }
     else if(position<2300)
  {
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,130);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,100);
   }
     else if(position<2800)
    {
   digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,140);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,120);
   }
    else if(position<3300)
  {
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,150);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,130);  
  }
  else  if(position<3800)
  { 
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,200);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,200);
  }
else if(position<4300 )
  { 
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,130);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,150);
  }
else if(position<4800 )
  { 
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,120);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,140); 
  }
else if(position<5300 )
  { 
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,100);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,130);
  } 
else if(position<5800 )
  { 
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,80);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,120); 
  }
else if(position<6300 )
  { 
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,60);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,110);
  }
else if(position<6800 )
  { 
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,30);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,100);
  }
else if(position>=6800 )
  { 
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  analogWrite(PWMa,0);
  digitalWrite(b1, HIGH);
  digitalWrite(b2, LOW);
  analogWrite(PWMb,90);
  }
}
