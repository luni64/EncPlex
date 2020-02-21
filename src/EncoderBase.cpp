#include "EncoderBase.h"
#include "core_pins.h"

namespace PollingEncoder
{
    bool EncoderBase::update(uint32_t phaseA, uint32_t phaseB) // https://www.mikrocontroller.net/articles/Drehgeber
    {
        int current = 0, diff;

        if (phaseA == HIGH) current = 3;
        if (phaseB == HIGH) current ^= 1;

        diff = last - current;
        if (diff & 1)
        {
            last = current;
            raw += (diff & 2) - 1;
          
            if (raw >> 2 != value)
            {
                value = raw >> 2;
                if (callback != nullptr)
                {
                    callback(value);
                }
                return true;
            }
        }
        return false;
    }
}