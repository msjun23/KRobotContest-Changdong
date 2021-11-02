#### K로봇대회 2021 라인트레이서 ####
######## 출발 및 도착 계측기 ########
############## PC GUI ##############
####### Author: Moon Seokjun #######

import serial
import time
from multiprocessing import Process, Queue

class SerialPort:
	def __init__(self):
		self.port = 'COM6'
		self.baudrate = 9600
		self.ser = serial.Serial(self.port, self.baudrate, timeout=1)

		self.start_time = 0.0
		self.end_time = 0.0

	def StartFlag(self, str):
		#str = self.ser.readline().decode('utf-8')
		if (str == 'Start\r\n'):
			self.start_time = time.time()
			return True
		return False

	def EndFlag(self, str):
		#str = self.ser.readline().decode('utf-8')
		if (str == 'End\r\n'):
			self.end_time = time.time()
			return True
		return False

	def PrintData(self):
		print(self.ser.readline().decode('utf-8'))
		#print(type(self.ser.readline()))

def GetSerial(self, ser):
	return ser.ser.readline().decode('utf-8')

if __name__ == "__main__":
	ser = SerialPort()

	while True:
		str = ser.ser.readline().decode('utf-8')
		if (str == 'Start\r\n'):
			ser.start_time = time.time()
		elif (str == 'End\r\n'):
			break

		print(time.time() - ser.start_time)
