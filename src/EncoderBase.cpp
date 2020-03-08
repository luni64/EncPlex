#include "EncoderBase.h"
#include "Arduino.h"
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

            if (limit)
            {
                raw = std::min(max, std::max(min, raw));
            }

            int32_t newVal = raw >> spr;
            if (newVal != value)
            {
                value = newVal;
                if (callback != nullptr)
                {
                    callback(value);
                }
                return true;
            }
        }
        return false;
    }

    void EncoderBase::setLimits(int32_t _min, int32_t _max)
    {
        if (_min >= _max)
        {
            limit = false;
            return;
        }

        limit = true;

        min = _min << spr;
        max = _max << spr;
    }
}