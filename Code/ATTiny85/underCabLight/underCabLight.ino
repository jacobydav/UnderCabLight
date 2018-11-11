/*This code is intended to run on the ATTiny85
 * 
 * Monitor input from a motion detector.
 * When motion is detected, reset a timer that will control how long
 * an output stays on. For example, we will turn output on for 15
 * minutes after detecting motion. 
 * The output will turn on under cabinet LEDs.
 */

//Input from the motion detector
//IO Number 0 = Physical pin number 5 on ATTiny85
int motionPin = 0;
//Output to turn on LEDs
//IO Number 1 = Physical pin number 6 on ATTiny85
int outputPin = 1;

int sensorVal = 0;
long noMotionCount = 0L;
//The delay in the main loop is millisecond. The value of noMotionCount will
//increment by 1 on each loop. So the value of noMotionThresh is the number
//of milliseconds with no motion that will result in turning off the LEDs.
long noMotionThresh = 600000L;

void setup() 
{
  pinMode(motionPin,INPUT);
  pinMode(outputPin,OUTPUT);
  digitalWrite(outputPin,LOW);
}

void loop() 
{ 
  //read the input pin
  sensorVal = digitalRead(motionPin);
  //if the motion sensor output is ON
  if(sensorVal==1)
  {    
      //Turn on the output which will trigger the relay
      digitalWrite(outputPin,HIGH);
      //reset the count that tracks how long its been since motion was detected    
      noMotionCount = 0;
  }
  else
  {    
    //if no motion has been detected for a certain period of time, turn off the relay
    if(noMotionCount>noMotionThresh)
    {      
        digitalWrite(outputPin,LOW);       
    }
    else
    {
      noMotionCount++;
    }
  }
  delay(1);
}
