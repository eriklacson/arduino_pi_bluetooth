//Pin Constants
const int DIGI_IN = 12;
const int DIGI_OUT = 13;
const int ANA_IN = 0;
const int ANA_OUT = 11;


int inByte; //incoming byte from serial
int currentPin; //the pin requested from serial input
int state = 0; //state of digital sensor pin
int output
; //output value to analog actuator pin
int analogVal; //raw value of analog sensor pin
int analogMap; //analogVal map to 1 - 9 range

void setup(){

  Serial.begin(9600);
  pinMode(DIGI_IN,INPUT);
  pinMode(ANA_IN,INPUT);
  pinMode(DIGI_OUT,OUTPUT);
  pinMode(ANA_OUT,OUTPUT);

}
  
void loop() {

    // check to see whether there is a byte available
    // to read in the serial buffer:
    if (Serial.available() > 0) {

        // read incoming byte
        inByte = Serial.read();
        
        //respond to pin requsted by serial input 
        if (inByte == 'a'){         
          state = digitalRead(DIGI_IN); //read  digital
          if (state == HIGH){
            Serial.write('1'); //if button is on send out 1 
            }
          else if (state == LOW) {
            Serial.write('0'); //if button is low send out 0
            }
          }
          
        if (inByte == 'b'){         
           analogVal = analogRead(ANA_IN); //read analog sensor
           analogMap = map(analogVal,0,850,0,9);         
           Serial.print (analogMap);         
           }
          
        if (inByte == 'c'){         
          currentPin = DIGI_OUT;
          }
          
        if (inByte == 'd'){         
          currentPin = ANA_OUT;
          }
         
        if ((inByte >= '0' && inByte <= '1') && currentPin == DIGI_OUT) {
          
          if (inByte == '1') {
            digitalWrite(currentPin,HIGH);
            }
          else if (inByte == '0') {
            digitalWrite(currentPin,LOW);
            }                 
       }
        
        if ((inByte >= '0' && inByte <= '9') && currentPin == ANA_OUT){          
          output = map(inByte,'0','9',0,255);
           analogWrite(currentPin, output);

          }                  
    }    

}
