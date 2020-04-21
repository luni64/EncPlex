#pragma once

#include "../EncoderBase.h"
#include "core_pins.h"

namespace EncPlex
{
    // Simple Encoder implementation which reads phase A and B from two digital pins
    class Encoder : public EncoderBase
    {
     public:
        //Constructor takes two pin numbers for phase A and B and an optional pin mode. E.g. INPUT_PULLUP or INPUT_PULLDOWN
        inline Encoder(int pinA, int pinB, int mode = INPUT_PULLUP);

        //begin() is optional and only required if some other code grabs the pins after construction of the encoder.
        inline void begin();

        //call tick() as often as possible. For mechanical encoders a call frequency of 1-2kHz is sufficient usually.
        inline void tick();

     protected:
        const int pinA, pinB, mode;
    };

    // Inline implementation ===============================================

    void Encoder::Encoder::tick()
    {
        update(digitalReadFast(pinA), digitalReadFast(pinB));
    }

    Encoder::Encoder(int _pinA, int _pinB, int _mode)
        : pinA(_pinA), pinB(_pinB), mode(_mode)
    {
        begin();
    }

    void Encoder::begin()
    {
        pinMode(pinA, mode);
        pinMode(pinB, mode);
    }
}