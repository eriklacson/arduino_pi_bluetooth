import serial
port = "/dev/ttyACM0"
serialFromArduino = serial.Serial(port,9600)
serialFromArduino.flushInput()



while True:

	send = raw_input("enter a string: ")
	serialFromArduino.write(send)
	wait = 1

	while (wait == .125)
		if (serialFromArduino.inWaiting() > 0):
			recv = serialFromArduino.read(1)
			print(recv)
		else
			wait = 0
			