#include <SparkFun_GridEYE_Arduino_Library.h>
#include <Wire.h>
GridEYE grideye;

#include <Arduino.h>
#include <TM1637Display.h>


#define TEST_DELAY 2000

#define CLK 4
#define DIO 3

TM1637Display display(CLK,DIO);


int ledDanger = 12;// the pin that the LED is atteched to
int ledSafe = 13;
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;
int i=0;
float k=0;
static const int buzzerPin = 6;

void setup() {
  Wire.begin();
  grideye.begin();
  
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledDanger, OUTPUT);
  pinMode(ledSafe, OUTPUT);// initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(115200); 
  
  // put your setup code here, to run once:

}

void loop() {
  display.setBrightness(0x0f);
  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
  display.setSegments(data);
  display.showNumberDec(0000, false, 4, 2);
  delay(TEST_DELAY);
  val = digitalRead(sensor);
  if(val==HIGH){
    

    
    Serial.println("Motion Detected");
    Serial.println("Temprature detection started");
    delay(3000);
    for(i=0; i<5; i++){
      k=temprature();      
      }
      k=k+5;

      while(k>=40){
        Serial.println("Danger");
        digitalWrite(ledDanger, HIGH);        
        beep();
        delay(400);
        
        
        
        }

       k=k*100;

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
