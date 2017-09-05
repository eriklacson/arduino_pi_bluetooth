class Settings():
	"""Class to store all app related settings"""

	def __init__(self):
		self.port_0 = "/dev/rfcomm0" #arduino 1 serial port
		self.port_1 = "/dev/rfcomm1" #arduino 2 serial port
		