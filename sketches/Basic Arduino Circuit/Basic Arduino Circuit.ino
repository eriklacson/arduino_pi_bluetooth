// Turn on LED while the button is pressed

const int LED = 13;
const int BUTTON = 12;

int inByte;
int val = 0;

void setup() {
	pinMode(LED, OUTPUT); // tell Arduino LED is an output
	pinMode(BUTTON, INPUT); // and BUTTON is an input
  
  	Serial.begin(9600);
	}


void loop(){
  
	val = digitalRead(BUTTON); // read input value and store it		
	
  	if (val == HIGH) {
      	Serial.write('1');
    	} 
    else {
		digitalWrite(LED, LOW); // turn LED off
		Serial.write('0');	      
   		}
  
  	if (Serial.available() > 0) {
      	inByte = Serial.read(); 

      if (inByte = '1') {
      	digitalWrite(LED, HIGH); // turn LED on
      	}
      else if (inByte = '0') {
      	digitalWrite(LED, LOW); // turn LED on
      }    
    }  
}  