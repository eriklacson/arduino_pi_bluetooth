import serial
import time
from settings import Settings 

app_settings = Settings()

class manageComs():
	"""Class for managing communications with the serial port"""

	def __init__(self):
		self.port = app_settings.port
		self.connection = serial.Serial(self.port)

	def send(self, packet):
		self.connection.reset_input_buffer()
		self.connection.write(packet)
		time.sleep(.25)

	def recv(self):
		self.connection.reset_input_buffer()
		self.connection.write('/n')
		time.sleep(.5)
		if (self.connection.inWaiting() > 0):
			inString = self.connection.readline()
			return inString
		else:
			return "no value"



