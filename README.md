# STM32MIDI
MIDI Controller with STM32F103C8. 

## Before upload, disconnect the USB port of the MCU!!!

### Serial port Mac
1. Write `ls /dev/tty.*` and copy the path to the serial port device.
2. Write `screen <SERIAL_PORT_HERE>`
3. To exit from screen, press Ctrl+A (^A) and then press K. A prompt will ask you if you wanna kill the session, press Y.
4. To run the serial monitor in background, press Ctrl+A (^A) an then press D. To resume simply write `screen -r`.