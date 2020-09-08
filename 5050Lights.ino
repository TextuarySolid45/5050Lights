#define RED_LED 6
#define BLUE_LED 5
#define GREEN_LED 9


int brightness = 255;
int gBright = 0;
int rBright = 0;
int bBright = 0;
int fadeSpeed = 30;

int AnalogOutput = A0; // Connect to sensors analog output (sensor AO pin > Arduino pin A0)
int soundsensor = 3; // Connect to sensors Digital output (sensor DO pin > Arduino pin 3)
int  ledPin  =  13;   // Connect to LED  (Arduino pin 13)
float AnalogValue =  0;  // Store analog value
int DigitalValue = 0; // Store digital value

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);  // set led pin as OUTPUT
  pinMode (soundsensor,INPUT) ;  // Sets pin 3 to INPUT
  
   pinMode(GREEN_LED, OUTPUT);
   pinMode(RED_LED, OUTPUT);
   pinMode(BLUE_LED, OUTPUT);
}

void TurnOn() { 
  analogWrite(RED_LED,206);
  analogWrite(GREEN_LED, 23);
  analogWrite(BLUE_LED, 36);
  delay(1000);
}

void TurnOff() {
  int a = (analogRead(AnalogOutput))*1.3;
  analogWrite(RED_LED,0);
  analogWrite(GREEN_LED, 0);
  analogWrite(BLUE_LED, 0);
}

int r[10]={204,255,51,255,255,102,0,255,0,255};
int g[10]={0,165,153,0,102,204,153,215,255,160};
int b[10]={204,0,255,0,102,0,153,0,255,122};

int i =0;

//void loop(){
//  
//  int sensorvalue= digitalRead (soundsensor);            
//                                                           
//  if (sensorvalue == 1){                                  
//    if(i<=9){
//      analogWrite(RED_LED,r[i]);
//      analogWrite(GREEN_LED,g[i]);
//      analogWrite(BLUE_LED,b[i]);
//      i++;
//    }else{
//      i=0;
//    }
//  }else{
//    int a;
//  }
//
//}
void loop() {

  if(i<765){
      int sensorvalue= digitalRead (soundsensor);            
                                                              
      if (sensorvalue == 1)                                    
      {
        if(i<=255){
          analogWrite(BLUE_LED,i);
        }else if(i>255 && i<510){
          analogWrite(RED_LED,i-255);
        }else if(i>510 && i<765){
          analogWrite(GREEN_LED, i-510);
        }
       
      }
      
      else
      {
        analogWrite(BLUE_LED, 0);
        analogWrite(RED_LED, 0);
        analogWrite(GREEN_LED, 0);
      }
      i++;
  }else{
    i=0;
  } 
    
    
}
