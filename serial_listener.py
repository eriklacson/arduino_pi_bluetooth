#import PySerial module
import serial 

#assign serial port address
port = "/dev/ttyACM0"

#open serial port at 9600 baud rate and create serial communication object
serialFromArduino = serial.Serial(port,9600) 


#main 
def run():
	while True:
		#wait for incoming data from the serial port
		if (serialFromArduino.inWaiting() > 0):
			input = serialFromArduino.readline()
			print input 
run()