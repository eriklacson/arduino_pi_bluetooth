import time
import serial
port = "/dev/ttyACM0"
serialFromArduino = serial.Serial(port,9600)

while True:

	send = raw_input("enter 1 to turn LED or 0 to turn LED off: ")
	serialFromArduino.reset_input_buffer()
	serialFromArduino.write(send)
	time.sleep(.175)


	if (serialFromArduino.inWaiting() > 0):
		input = serialFromArduino.read(1)
		print "Button state: " + input	


		
			