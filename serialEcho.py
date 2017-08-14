import serial
port = "/dev/ttyACM0"
serialFromArduino = serial.Serial(port,9600)
serialFromArduino.flushInput()



while True:
	serialFromArduino.write('1')
	serialFromArduino.write('0')

	