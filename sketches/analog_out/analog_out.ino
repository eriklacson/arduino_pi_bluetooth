// set analog input pin
const int POT = 0;

// set pwm output pin
const int LED = 11;

// set variables
int input; //value read from POT
int val; //value of input map to analog range

 
void setup() {
  // start serial comms
  Serial.begin(9600);
  pinMode(POT,INPUT);

}

void loop() {
  // read analog input from input pin
  input = analogRead(POT);
  Serial.println(input);
}
