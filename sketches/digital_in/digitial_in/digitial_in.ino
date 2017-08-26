/*
    Simple Serial
    Context: Arduino
    Listens for an incoming serial byte, adds one to the byte
    and sends the result back out serially.
 */

// LED constants
const int LED13 = 13; 

int inByte = 0;              // variable to hold incoming serial data

void setup() {
  Serial.begin(9600);         // configure the serial port for 9600 bps
                              // data rate.
}

void loop() {
  // if there are any incoming serial bytes available to read:
  if (Serial.available() > 0) {
    // then read the first available byte:
    inByte = Serial.read();
    // and add one to it, then send the result out:
    if (inByte == '1') {
      digitalWrite(LED13, HIGH);
    }
    else if (inByte == '0') {
      digitalWrite(LED13, LOW);
    }
  }
}
