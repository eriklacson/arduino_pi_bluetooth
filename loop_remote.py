from settings import Settings
import time
import serial

com_settings = Settings()

serial_0 = serial.Serial(com_settings.port_0)
serial_1 = serial.Serial(com_settings.port_1)


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
			print "digital: " + digital_in #test print

			#handle response
			#
			#send digital value
			serial_0.reset_output_buffer()
			if (digital_in == '1'):
				serial_0.write('c1');
			elif (digital_in == '0'):
				serial_0.write('c0');
				#send request for analog value
						
		serial_1.write('b')
		#wait for respponse
		if (serial_1.inWaiting() > 0):
			analog_in = serial_1.read() #read response
			print "analog: " + analog_in #test print

			#handle response
			#
			#clear serial buffer
			serial_0.reset_output_buffer()
			#send analog value
			analog_out = 'd' + str(analog_in)
			serial_0.write(analog_out)		
run()