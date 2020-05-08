#pragma once
    
    #include "core_pins.h"

namespace EncPlex
{

#if defined(ARDUINO_TEENSY40) || defined(ARDUINO_TEENSY40)

    
    inline void delay50ns()
    {
        delayNanoseconds(50);
    
    }


#else

    inline void delay50ns()
    {
        delayMicroseconds(1);
    }

#endif
}