# -*- coding: utf-8 -*

import serial, time
import struct
from array import array
from io import BytesIO

class RobotCmd(object):

    _struct = struct.Struct('<hhh')

    def __init__(self):
        self.t1 = 0
        self.t2 = 0
        self.t3 = 0

    def serialize(self, buff):
        #try
        buff.write(RobotCmd._struct.pack(self.t1, self.t2, self.t3))
        #except struct.error as se:
        #    raise SerializationError('Error in serialization %s' % (self.__str__))
        


def to_hex(data):
    return ":".join("{:02x}".format(c) for c in data)

def angulos(th1, th2, th3):
    cmd = RobotCmd()
    buff = BytesIO()
    cmd.t1 = th1
    cmd.t2 = th2
    cmd.t3 = th3
    cmd.serialize(buff)
    base_cmd = bytearray(buff.getvalue())
    arduino.write(base_cmd)
    
    ser_bytes = arduino.readline() # lee una linea del puerto serial
    decoded_bytes = str(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
    print(decoded_bytes)

    ser_bytes = arduino.readline()
    decoded_bytes = str(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
    print(decoded_bytes)

    ser_bytes = arduino.readline()
    decoded_bytes = str(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
    print(decoded_bytes)
    

arduino = serial.Serial('COM3', 9600)
cmd = RobotCmd()
buff = BytesIO()
cmd.serialize(buff)
