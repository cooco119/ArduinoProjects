#define value = 150
#define angle_r = 255
#define angle_l = 0
#include "Adafruit_VL53L0X.h"
int E1 = 5;
int M1 = 4;
int E2 = 6;                         
int M2 = 7;                        
int array[2];
long int count = 0;
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
  
void measure_communication (void)
{
  int data_msrd;
  int data_msrd_prev;
  int data_rcvd;
  int data_rcvd_prev;
  if(count%5==0)
  {
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
  data_msrd = measure.RangeMilliMeter;
  data_rcvd = Serial.read();
  if(data_msrd>250)
  {
    data_msrd=250;
  }
  if(data_rcvd>250)
  {
    data_rcvd=250;
  }
  if( abs( data_msrd - data_msrd_prev) > 70)
  {
    data_msrd = 250;
  }
  if( abs( data_rcvd - data_rcvd_prev) > 70)
  {
    data_rcvd = 250;
  }
  data_msrd_prev = data_msrd;
  data_rcvd_prev = data_rcvd;
  array[0] = data_msrd;
  array[1] = data_rcvd;
  }
}

void handling (void)
{
  int high_value = 255 - array[0];
  int low_value  = 255 - array[1];
  if(count%30 == 0)
  {
    if(array[0]<100)
    {
      digitalWrite(M1,HIGH);   
      digitalWrite(M2,HIGH);       
      analogWrite(E1, 255);   //PWM Speed Control
      analogWrite(E2, high_value );   //PWM Speed Control
    }
    if(array[1]<100)
    {
      digitalWrite(M1,HIGH);   
      digitalWrite(M2,LOW);       
      analogWrite(E1, 255);   //PWM Speed Control
      analogWrite(E2, low_value);   //PWM Speed Control
    }
    else
    {
      digitalWrite(M1,HIGH);   
      digitalWrite(M2,HIGH);       
      analogWrite(E1, 255);   //PWM Speed Control
      analogWrite(E2, 0);   //PWM Speed Control
    }
  }
}
void setup() 
{ 
    Serial.begin(115200);
    lox.begin();
    pinMode(M1, OUTPUT);   
    pinMode(M2, OUTPUT);
}
void loop() 
{
  measure_communication();
  handling();
  count++;
  delay(10);
}

