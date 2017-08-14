//Set I/O Pin Constants
const int LED = 13; //led pin
const int BUTTON = 12; //button pin

int state = 0;
int inByte;

void setup() {

  Serial.begin(9600); //open serial port at 9600 bps rate
  
  pinMode(LED, OUTPUT); //Set led pin as output 
  pinMode(BUTTON, INPUT); //Set button pin as input 
}

void loop() {
// put your main code here, to run repeatedly:

  //check for incoming serial data  
  if (Serial.available() > 0){   
    inByte = Serial.read();

    //if serial is turn on led if not turn off led
    if (inByte == '1') {
      digitalWrite(LED, HIGH);
      }
    else if (inByte == '0'){
      digitalWrite(LED, LOW);
      }                 
    }
  // if there is not incoming serial data read button state 
  // and send it to the serial port   
  else { 
    state = digitalRead(BUTTON);
    if (state == HIGH){
      Serial.print('1'); //if button is on send out 1 
      }
    else if (state == LOW) {
      Serial.print('0'); //if button is low send out 0
      }
   }  
}
