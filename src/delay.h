#pragma once

namespace EncPlex
{

#if defined(ARDUINO_TEENSY40) || defined(ARDUINO_TEENSY40)

    #include "core_pins.h"

    inline void delay50ns()
    {
        delayNanoseconds(50);
    }

#else

#endif
}