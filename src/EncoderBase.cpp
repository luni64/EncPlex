#include "EncoderBase.h"
#include "Arduino.h"
#include "core_pins.h"

namespace EncPlex
{

    EncoderBase::EncoderBase()
    {
    }

    void EncoderBase::set(int32_t val)
    {
        noInterrupts();
        last = val << spr;
        raw = val << spr;
        value = val;
        interrupts();
    }

    void EncoderBase::setStepsPerDetent(unsigned spd)
    {
        stepsPerDetent = spd;
    }

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

            // handle steps per detent
            int newVal;
            if (raw > 0)
            {
                newVal = (raw + stepsPerDetent / 2) / stepsPerDetent;
            } else
            {
                newVal = (raw - stepsPerDetent / 2) / stepsPerDetent;
            }

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

    // void EncoderBase::setLimits(int32_t _min, int32_t _max)
    // {
    //     if (_min >= _max)
    //     {
    //         limit = false;
    //         return;
    //     }

    //     limit = true;

    //     min = _min << spr;
    //     max = _max << spr;
    // }
}