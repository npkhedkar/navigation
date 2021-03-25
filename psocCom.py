# simple python snippet
import serial
import time

# create an empty list
buffer = []

COM_PORT = "COM3"
# open a serial port
# use COM_ (or put your own port in here)
# baudrate 115200 is the default setting for the XBee
# timeout = 1 ensure the serial port won't read forever (we
# don't use flow control)
s=serial.Serial(COM_PORT,baudrate=115200,timeout=1)

lines = ""

# sample for 30 seconds
t0 = time.time()
TOTAL_SAMPLE_TIME_SECS = 30
print(f"Sampling for {TOTAL_SAMPLE_TIME_SECS}")
while (time.time() - t0) < TOTAL_SAMPLE_TIME_SECS:

    # read() returns a byte array, decode() casts to string
    lines = s.readline().decode().rstrip()
    print(lines)
    #if len(lines):
     #   print(lines)
        # parse the lines according to your comm. spec
      #  buffer.append(lines)

    if (lines == "&&&"):
        break