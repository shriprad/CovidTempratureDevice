#include <SparkFun_GridEYE_Arduino_Library.h>
#include <Wire.h>
GridEYE grideye;

#include <Arduino.h>
#include <TM1637Display.h>


#define TEST_DELAY 2000

#define CLK 2
#define DIO 3

TM1637Display display(CLK,DIO);


int ledDanger = 13;// the pin that the LED is atteched to
int ledSafe = 11;
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;
int i=0;
float k=0;
static const int buzzerPin = 12;
int buzz=1;

void setup() {
  Wire.begin();
  grideye.begin();
  
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(115200); 
  
  // put your setup code here, to run once:

}

void loop() {
  val = digitalRead(sensor);
  if(val==HIGH){
    

    
    Serial.println("Motion Detected");
    Serial.println("Temprature detection started");
    for(i=0; i<5; i++){
      k=temprature();

      while(k>=40){
        digitalWrite(ledDanger, HIGH);        
        beep();
        delay(400);
        
        
        
        }
      
      }

     Serial.println(k);
     digitalWrite(ledSafe, HIGH);

     display.setBrightness(0x0f);
     uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
     display.setSegments(data);
     display.showNumberDec(k, false, 4, 0);
     delay(TEST_DELAY);


    delay(5000);
        
    }
  else{

    digitalWrite(ledSafe, LOW);
    Serial.println("Motion Not Detected");    
    
    }

}


float temprature(){
  float testPixelValue = 0;
  float hotPixelValue = 0;
  int hotPixelIndex = 0;

  for(unsigned char i = 0; i < 64; i++){

    testPixelValue = grideye.getPixelTemperature(i);
    if(testPixelValue > hotPixelValue){

      hotPixelValue = testPixelValue;
      hotPixelIndex = i;      
      }      
    }

return hotPixelValue;  
  }



void beep(){

  tone(buzzerPin, 4000,200);

  
  
  
  }
