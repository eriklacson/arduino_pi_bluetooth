from settings import Settings
import time
import serial

com_settings = Settings()

serial_1 = serial.Serial(com_settings.port)


def run():
	
	//program loop
	while True:
		
		//check for digital value
		serial_1.write('d')
		if (serial_1.inWaiting() > 0):
			incoming = serial_1.read()
			print input

		//check for analogy value

		//send digital value

		//send analog value


run()