#include <QTRSensors.h>
#define EMITTER_PIN  8
#define NUM_SENSORS  8
#define maxspeed 180
#define minspeed 45
QTRSensorsAnalog qtra((unsigned char[]) {0,1,2,3,4,5,6,7}, NUM_SENSORS, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];
//void follow_line(int);
//void set_speed(int,int);
int pwm_a = 7; 
int pwm_b = 6;
int dir_a1 = 5;
int dir_a2 = 4;
int dir_b1 = 3;
int dir_b2 = 2;
float error=0;
float lastError=0;
float PV = 0;
float kp = 5;
float ki = 0.0001;
float kd = 1.5;
int m1Speed=0;
int m2Speed=0;
int integral=0; 
void setup() {
  pinMode(pwm_a, OUTPUT);
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a1, OUTPUT);
  pinMode(dir_b1, OUTPUT);
  pinMode(dir_a2, OUTPUT);
  pinMode(dir_b2, OUTPUT);
  Serial.begin(9600);
  delay(500);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);    
  for (int i = 0; i < 200; i++)  
  {
    qtra.calibrate();       
  }
  digitalWrite(13, LOW);    
  delay(1000);
}

void loop() {
  unsigned int sensors[8];
 unsigned int position = qtra.readLine(sensors);
 follow_line(position);
       digitalWrite(dir_a2, HIGH);  
       digitalWrite(dir_a1, LOW);
       analogWrite(pwm_a, m2Speed);
       digitalWrite(dir_b1, HIGH);
       digitalWrite(dir_b2, LOW);  
       analogWrite(pwm_b, m1Speed);
   
}

void follow_line(int position)
{
  error = position - 3500;
  int derivate=error-lastError;
  integral+=error;
  lastError = error;
  
  PV = kp*error+integral*ki+derivate*kd;
  PV = kp * error + kd * derivate;
  m1Speed=maxspeed+PV;
  m2Speed=maxspeed-PV;
  set_speed(m1Speed,m2Speed);
}

void set_speed(int a, int b){
  /*if(m1Speed>=maxspeed){m1Speed=maxspeed;}
  if(m1Speed<=0){m1Speed=0;}
  if(m2Speed>=maxspeed){m2Speed=maxspeed;}
  if(m2Speed<=0){m2Speed=0;}*/
  m1Speed=constrain(a,minspeed,maxspeed);
  m2Speed=constrain(b,minspeed,maxspeed); 
}


