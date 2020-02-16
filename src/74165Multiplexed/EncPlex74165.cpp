#include "EncPlex74165.h"
#include "Arduino.h"

using namespace PollingEncoder;

EncPlex74165::EncPlex74165(unsigned encoderCount, unsigned pinLD, unsigned pinCLK, unsigned pinA, unsigned pinB)
    : EncPlexBase(encoderCount), A(pinA), B(pinB), S(-1), LD(pinLD), CLK(pinCLK)
{
    begin();
}

void EncPlex74165::begin()
{
    pinMode(A, INPUT);
    pinMode(B, INPUT);
    pinMode(LD, OUTPUT);
    pinMode(CLK, OUTPUT);

    pinMode(12, OUTPUT);
}

void EncPlex74165::tick()
{
    digitalWriteFast(12, HIGH);

    // load current values to shift register
    digitalWriteFast(LD, LOW);
    delayMicroseconds(1);
    digitalWriteFast(LD, HIGH);

     // first values are available directly after loading
    if (encoders[0].update(digitalReadFast(A), digitalReadFast(B)) && callback != nullptr)
    {
        callback(0, encoders[0].read());
    }
    for (unsigned i = 1; i < encoderCount; i++) // shift in the the rest of the encoders
    {
        digitalWriteFast(CLK, HIGH);
        if (encoders[i].update(digitalReadFast(A), digitalReadFast(B)) && callback != nullptr)
        {
            callback(i, encoders[i].read());
        }
        digitalWriteFast(CLK, LOW);
    }

    digitalWriteFast(12, LOW);
}