from settings import Settings
import time
import serial



com_settings = Settings()

serial_1 = serial.Serial(com_settings.port)


def run():

	digital_in = '0'
	analog_in = '0'
	analog_out = ''

	#program loop
	while True:

		#send request for digital pin value
		serial_1.write('a')
		#wait for respponse
		if (serial_1.inWaiting() > 0):
			digital_in = serial_1.read() #read response
			print digital_in #test print

			#handle response
			#
			#send digital value
			if (digital_in == '1'):
				serial_1.write('c1');
			elif (digital_in == '0'):
				serial_1.write('c0');

		#send request for analog value		
		serial_1.write('b')
		#wait for respponse
		if (serial_1.inWaiting() > 0):
			analog_in = serial_1.read() #read response
			analog_out = 'd' + analog_in
			serial_1.write(analog_out);
			print analog_out #test print	

		#send request for analog value

		#send analog value


run()