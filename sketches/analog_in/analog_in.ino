// set pwm output pin
const int LED = 11;

// set variables
String inString = ""; //analog value read from serial port
char inChar; //value of input map to analog range
int outputValue = 0; //value for analogy output

void setup() {

  Serial.begin(9600); //open serial port at 9600 bps rate  
  pinMode(LED, OUTPUT); //Set led pin as output 

}

 
void loop() {

// Read serial input:
  while (Serial.available() > 0) {

    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char
      // and add it to the string:
      inString += (char)inChar;
    }

    // if you get a newline, print the string,
    // then the string's value:
    if (inChar == '\n') {
      outputValue = inString.toInt();
      Serial.println(outputValue);
      analogWrite(LED,outputValue);        
      inString = "";
    }
  }
  
}
     
