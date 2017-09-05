from settings import Settings
import time
import serial

com_settings = Settings()

serial_1 = serial.Serial(com_settings.port_1)

def run():

	digital_in = '0'
	analog_in = '0'

	#program loop
	while True:

		#send request for digital pin value
		serial_1.write('a')
		time.sleep(.125)
		#wait for respponse
		if (serial_1.inWaiting() > 0):
			digital_in = serial_1.read() #read response
			print "digital: " + digital_in #test print

		#send request for analog value		
		serial_1.write('b')
		time.sleep(.125)
		#wait for respponse
		if (serial_1.inWaiting() > 0):
			analog_in = serial_1.read() #read response
			print "analog: " + analog_in #test print

run()