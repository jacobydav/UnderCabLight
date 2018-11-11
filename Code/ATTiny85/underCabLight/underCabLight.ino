/*This code is intended to run on the ATTiny85
 * 
 * Monitor input from a motion detector using an interrupt.
 * When motion is detected, reset a timer that will control how long
 * an output stays on. For example, we will turn output on for 15
 * minutes after detecting motion. 
 * The output will turn on under cabinet LEDs.
 */

//Input from the motion detector
//IO Number 0 = Physical pin number 5
int motionPin = 0;
//Output to turn on LEDs
//IO Number 1 = Physical pin number 6
int outputPin = 1;

int sensorVal = 0;
long noMotionCount = 0L;
long noMotionThresh = 600000L;
bool isLEDOn = false;

void setup() 
{
  pinMode(motionPin,INPUT);
  pinMode(outputPin,OUTPUT);
  digitalWrite(outputPin,LOW);
}

void loop() 
{ 
  /* 
  digitalWrite(outputPin,HIGH);
  delay(10000);
  digitalWrite(outputPin,LOW);
  delay(5000);
  */
  
  sensorVal = digitalRead(motionPin);
  if(sensorVal==1)
  {
    //if(isLEDOn ==false)
    //{
      digitalWrite(outputPin,HIGH);
    //  isLEDOn = true;
    //}
    noMotionCount = 0;
  }
  else
  {    
    if(noMotionCount>noMotionThresh)
    {
      //if(isLEDOn ==true)
      //{
        digitalWrite(outputPin,LOW);
        //isLEDOn = false;
      //}
    }
    else
    {
      noMotionCount++;
    }
  }
  delay(1);
}
