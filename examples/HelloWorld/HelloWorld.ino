/*
  FutabaVFD Library - Hello World
  
  Tested with Futaba US202SD01A/C
 
  This sketch prints "Hello World!" to the LCD
  and shows the time.

  The pinout for the Futaba US202SD01A/C displays is as follows:

    1 - +5V ( can be powered from arduino board)
    2 - CLOCK
    3 - GND
    4 - DATA
    5 - STROBE

  The circuit:
    VFD +5V to 5V
    VFD CLOCK pin to digital pin 5
    VFD GND pin to ground ( GND )
    VFD DATA pin to digital pin 4
    VFD STROBE pin to digital pin 3

  API loosly based on LiquidCrystal library (https://www.arduino.cc/en/Reference/LiquidCrystal) 

 This example code is in the public domain.

 https://github.com/nervus/FutabaVFD
 */

// include the library code:
#include <FutabaVFD.h>

// initialize the library with the numbers of the interface pins
FutabaVFD vfd(5, 4, 3);

void setup() 
{
  vfd.begin(20);
  
  // Print a message to the LCD.
  vfd.setCursor(0, 0);
  vfd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  
  vfd.setCursor(0, 1);
  vfd.print(millis() / 1000);

  delay(100);
}
