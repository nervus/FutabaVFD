#ifndef FutabaVFD_h
#define Futaba_h

#include <inttypes.h>
#include "Print.h"

// commands
#define VFD_CLEARDISPLAY    0x01
#define VFD_SETCURSOR       0x02
#define VFD_SETINTENSITY    0x04

class FutabaVFD : public Print
{
public:
    FutabaVFD(uint8_t clk, uint8_t data, uint8_t strobe, uint8_t intensity = 0x0ff);

    // clear display, set cursor position to zero
    void clear() { send(VFD_CLEARDISPLAY); }
    void begin(uint8_t numColumns = 20);
    
    // set cursor position to zero
    void home() { setCursor(0,0); }
    void setCursor(uint8_t col, uint8_t row) { send(VFD_SETCURSOR); send((row) * _numcolumns + (col+1)); }
    
    virtual size_t write(uint8_t data) { send(data); return 1; }
    using Print::write;
    
    void strobe();
    void send(uint8_t);
private:
    
    uint8_t _clk_pin; // active high.
    uint8_t _dat_pin; // active high.
    uint8_t _stb_pin; // active low. it seems to be a device reset or smth. must be triggered at
    // least once before displaying.
    
    uint8_t _numcolumns;
    uint8_t _intensity;
};

#endif
