// variable for data recieved from port
int inByte;


void setup() {
  
  // start serial comms
  Serial.begin(9600);

}

void loop() {

  // wait for incoming data from serial
  if (Serial.available() > 0) {
    
    // read incoming data
    int inByte = Serial.read();
    
    //send data back to serial port
    Serial.write(inByte);
    delay(1);
    
    }
}
