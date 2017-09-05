from settings import Settings
import time
import serial

com_settings = Settings()

serial_0 = serial.Serial(com_settings.port_0)

def run():

	analog_out = ''

	#program loop
	while True:

		for val in range(0,9):
			
			serial_0.write('c1') 
			time.sleep(1)
			print val
			analog_out = 'd' + str(val)
			serial_0.write(analog_out)
			serial_0.write('c0')
			time.sleep(1)			
run()