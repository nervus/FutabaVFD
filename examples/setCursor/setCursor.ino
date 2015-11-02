/*
  FutabaVFD Library - Hello World
  
  Tested with Futaba US202SD01A/C
 
 This sketch prints to all the positions of the LCD using the
 setCursor() method:

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

// these constants won't change.  But you can change the size of your VFD using them:
const int numRows = 2;
const int numCols = 20;

// initialize the library with the numbers of the interface pins
FutabaVFD vfd(5, 4, 3);

void setup() 
{
  vfd.begin(20);
}

void loop() 
{
  // loop from ASCII 'a' to ASCII 'z':
  for (int thisLetter = 'a'; thisLetter <= 'z'; thisLetter++) {
    // loop over the columns:
    for (int  thisRow = 0; thisRow < numRows; thisRow++) {
      // loop over the rows:
      for (int thisCol = 0; thisCol < numCols; thisCol++) {
        // set the cursor position:
        vfd.setCursor(thisCol, thisRow);
        // print the letter:
        vfd.write(thisLetter);
        delay(200);
      }
    }
  }
}

