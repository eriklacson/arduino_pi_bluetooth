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
		if (self.connection.inWaiting() > 0):
			in_byte = self.connection.read(1)
			return in_byte



