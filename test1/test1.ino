

int led = 13;                // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int val = 0;
void setup() {


  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600); 
  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(sensor);
  
  if(val==HIGH){

    digitalWrite(led, HIGH);
    Serial.println("Motion Detected");    
    }

  else{

    digitalWrite(led, LOW);
    Serial.println("Motion Not Detected");    
    
    }

}
