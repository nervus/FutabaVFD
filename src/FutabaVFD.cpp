#include "FutabaVFD.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

/*
 
 The protocol is a really simple asyncronous serial protocol:
 - Display becomes active after the strobe pin has been triggered ( active LOW )
 - data is then sent in 8bit packets.
 */

FutabaVFD::FutabaVFD(uint8_t clkPin, uint8_t dataPin, uint8_t strobePin, uint8_t intensity)
{
    _clk_pin = clkPin;
    _dat_pin = dataPin;
    _stb_pin = strobePin;
    _intensity = intensity;
}

void FutabaVFD::begin(uint8_t numColumns)
{
    _numcolumns = numColumns;
    pinMode(_clk_pin, OUTPUT);
    pinMode(_dat_pin, OUTPUT);
    pinMode(_stb_pin, OUTPUT);
    
    digitalWrite(_clk_pin, LOW);
    digitalWrite(_dat_pin, LOW);
    digitalWrite(_stb_pin, LOW);
    
    delay(500);

    strobe();
    send(VFD_SETINTENSITY); send(_intensity);
    clear();
}


void FutabaVFD::send(uint8_t data)
{
    for (unsigned int mask = 0x80, i=0;i<8;i++,mask >>=1)
    {
        digitalWrite(_clk_pin, HIGH);
        delayMicroseconds(15);
        digitalWrite(_dat_pin, !!(data & mask));
        delayMicroseconds(5);
        digitalWrite(_clk_pin, LOW);
        delayMicroseconds(15);
    }
}


void FutabaVFD::strobe()
{
    digitalWrite(_clk_pin,HIGH);
    digitalWrite(_dat_pin,HIGH);
    
    digitalWrite(_stb_pin, HIGH);
    delay(5);
    digitalWrite(_stb_pin, LOW);
    delay(5);
}


