/*This code is intended to run on the Arduino
 * 
 * Monitor input from a motion detector.
 * When motion is detected, reset a timer that will control how long
 * an output stays on. For example, we will turn output on for 15
 * minutes after detecting motion. 
 * The output will turn on under cabinet LEDs.
 */

//Input from the motion detector
int motionPin = 6;
//Output to turn on LEDs
int outputPin = 7;

int sensorVal = 0;
long noMotionCount = 0;
long noMotionThresh = 10000;
bool isLEDOn = false;

void setup() 
{
  Serial.begin(9600);
  pinMode(motionPin,INPUT);
  pinMode(outputPin,OUTPUT);
}

void loop() 
{  

  sensorVal = digitalRead(motionPin);
  if(sensorVal==1)
  {
    Serial.println("Motion detected");
    Serial.print("isLEDOn=");
    Serial.println(isLEDOn);
    if(isLEDOn ==false)
    {
      digitalWrite(outputPin,HIGH);
      isLEDOn = true;
    }
    noMotionCount = 0;
  }
  else
  {    
    if(noMotionCount>noMotionThresh)
    {
      if(isLEDOn ==true)
      {
        digitalWrite(outputPin,LOW);
        isLEDOn = false;
        Serial.println("Turning LED off");
      }
    }
    else
    {
      noMotionCount++;
      if(noMotionCount%1000==0)
        Serial.println(noMotionCount);
    }
  }
  
     
}
