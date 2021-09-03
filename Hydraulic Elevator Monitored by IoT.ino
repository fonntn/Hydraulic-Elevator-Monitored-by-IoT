#define BLYNK_PRINT Serial
#include <Stepper.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//char auth[] = "your char auth"; 
//char ssid["your char ssid"];
//char pass["your char pass"];

// numero de passos a cada volta
const int stepsPerRevolution = 200; 
int rede = 0;
int senha = 0;

Stepper myStepper(stepsPerRevolution, 14, 12, 13, 15);


int xVal=512;
void setup() {
   
   Serial.begin(9600);
   Serial.println("Digite o nome da rede");
   
  do {
   if (Serial.available()) {
    //char ssid[] = Serial.readString();
    rede = 1;
   }
  } while (rede = 0);
   
   Serial.println("Digite a senha da rede");

  do{
   if (Serial.available()) {
    char pass[] = Serial.readString();
    senha = 1;
   }
  } while (senha = 0);
   
   Blynk.begin(auth, ssid, pass);
}
void loop() {
  
 Blynk.run();

  if( (xVal < 500)  ){
     myStepper.step(1);
     delayMicroseconds(3000);
  }else if( xVal > 550){
     myStepper.step(-1);
     delayMicroseconds(3000);
  }

  
}
BLYNK_WRITE(V1)
{
  xVal = param[0].asInt();
 // int y = param[1].asInt();    
}
BLYNK_WRITE(V2)
{
   if( param.asInt() == 1){
        xVal = 0;
   }else{
        xVal = 512;
   }
}
BLYNK_WRITE(V3)
{
   if( param.asInt() == 1){
        xVal = 1000;
   }else{
        xVal = 512;
   }
}
