from manage_coms import manageComs
import time


coms = manageComs()

coms.send('1')
time.sleep(1)
coms.send('0')
time.sleep(1)
print coms.recv()
