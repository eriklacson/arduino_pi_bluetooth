from settings import Settings
import time
import serial

com_settings = Settings()

serialFromArduino = serial.Serial(com_settings.port)


def run():
	while True:
		send = raw_input("enter a value from 1 to 255: ")
		serialFromArduino.reset_input_buffer()
		serialFromArduino.write(send)
		time.sleep(.175)

		if (serialFromArduino.inWaiting() > 0):
			input = serialFromArduino.readline()
			print "Potentiometer state: " + input	
run()