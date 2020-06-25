#include <SparkFun_GridEYE_Arduino_Library.h>
#include <Wire.h>
GridEYE grideye;

int led = 13;                // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;
void setup() {
  Wire.begin();
  grideye.begin();

  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(115200); 
  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(sensor);
//  float testPixelValue = 0;
//  float hotPixelValue = 0;
//  int hotPixelIndex = 0;
//  while(val==HIGH){
//
//    //digitalWrite(led, HIGH);
//    //Serial.println("Motion Detected");
//    delay(1000);
//    for(unsigned char i = 0; i < 64; i++){
//
//      testPixelValue = grideye.getPixelTemperature(i);
//      if(testPixelValue > hotPixelValue){
//        hotPixelValue = testPixelValue;
//        hotPixelIndex = i;
//        
//        }     
//      }
//
//      
//
//    
//    delay(1000);
//    Serial.print("The temprature in C is");
//    Serial.print(hotPixelValue); 
//
//    val=digitalRead(sensor);
//    if(val==LOW){
//      Serial.println("Not Detected");
//      digitalWrite(led, LOW);
//      break;
//      }    
//    }
//
//  

    



  if(val==HIGH){

    digitalWrite(led, HIGH);
    Serial.println("Motion Detected");    
    }

  else{

    digitalWrite(led, LOW);
    Serial.println("Motion Not Detected");    
    
    }

}
