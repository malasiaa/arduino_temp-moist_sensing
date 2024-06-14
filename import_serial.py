import serial
import time

max_lines = 10  # Number of lines to log each time
line_count = 0

# Set the serial port and baud rate
ser = serial.Serial('COM3', 2400)  # 'COM3' port

print("Writting...")
# Open a file to log the data
with open(f"serial_log_{time.strftime('%Y-%m-%d_%H-%M-%S')}.txt", 'w') as f:
    while line_count < max_lines:
        if ser.in_waiting:
            # Read the serial data
            line = ser.readline().decode('utf-8').strip()
            # Write in the log file
            f.write(f"{time.strftime('%Y-%m-%d %H:%M:%S')} - {line}\n")
            f.flush()
            line_count += 1

print("log file updated!")
