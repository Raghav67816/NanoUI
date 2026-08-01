import serial
import time

# 1. Identify your port. On Mac, it typically starts with /dev/cu.usbserial or /dev/cu.usbmodem
# Replace this string with your actual port address
SERIAL_PORT = '/dev/cu.usbmodem14701' 
BAUD_RATE = 115200

try:
    # 2. Initialize the serial connection
    # Note: Opening the port resets some microcontrollers (like Arduino)
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    time.sleep(2) # Wait for the connection to initialize stably
    
    # 3. Define your message
    # Serial communication transmits raw bytes. Use the 'b' prefix for literal bytes
    message = b"Hello World\n" 
    
    # 4. Send the data
    ser.write(message)
    print(f"Successfully sent: {message}")
    
    # 5. Clean up and close the port
    ser.close()

except serial.SerialException as e:
    print(f"Error opening or writing to serial port: {e}")

