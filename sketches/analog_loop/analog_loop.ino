// set analog input pin
const int POT = 0;

// set pwm output pin
const int LED = 11;

// set variables
String inString = ""; //analog value read from serial port
char inChar; //value of input map to analog range
int inVal;
int outVal;


void setup() {
  
  Serial.begin(9600); //open serial port at 9600 bps rate  
  pinMode(LED, OUTPUT); //Set led pin as output
  pinMode(POT, INPUT); //Set potentiometer pin as input

}
 
void loop() {

  // check for incoming data
  if(Serial.available() > 0) {

    // read serial input
    int inChar = Serial.read();

    // check if input is a digit character
    if (isDigit(inChar)) {
           
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;  
      }

    // if you get a newline, process serial output

    // check if incoming byte is '\n'
    else if (inChar == '\n') {
            
      analogWrite(LED,inString.toInt()); //light up LED        
      inString = ""; //clear string buffer
      
      }
      
    delay(1); //wait for the the port clear

    }

   // if there no incoming data 
   else {

    inVal = analogRead(POT); //get raw potentiometer value
    outVal = map(inVal,0,1200,0,255); //map raw value to analog output range (0-255)
    Serial.println(outVal);//send output value to serial port
    
    } 
  
}
     
