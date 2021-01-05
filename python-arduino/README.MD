# Uso
Una vez cargado MOV_.ino al Arduino,
Cambiar en serial_write_read.py la linea
      arduino = serial.Serial('COM3', 9600)
y reemplazar 'COM3' con el puerto del Arduino
Abrir serial_write_read.py y establecer los ángulos del motor con
      angulos(th1, th1, th3)
