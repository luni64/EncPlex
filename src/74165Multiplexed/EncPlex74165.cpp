#include "EncPlex74165.h"
#include "../delay.h"

#include "Arduino.h"

using namespace EncPlex;

EncPlex74165::EncPlex74165(unsigned encoderCount, unsigned pinLD, unsigned pinCLK, unsigned pinA, unsigned pinB, unsigned stepsPerDetent)
    : EncPlex::EncPlexBase(encoderCount, stepsPerDetent), A(pinA), B(pinB), S(-1), LD(pinLD), CLK(pinCLK)
{
    begin();
}
 
void EncPlex74165::begin()
{
    pinMode(A, INPUT);
    pinMode(B, INPUT);
    pinMode(LD, OUTPUT);
    pinMode(CLK, OUTPUT);

    digitalWriteFast(LD, HIGH); // active low
}

void EncPlex74165::tick()
{
    // load current values to shift register
    digitalWriteFast(LD, LOW);
    delay50ns();
    delay50ns();
    delay50ns();
    digitalWriteFast(LD, HIGH);

    // first values are available directly after loading
    if (encoders[0].update(digitalReadFast(A), digitalReadFast(B)) && callback != nullptr)
    {
        callback(0, encoders[0].getValue());
    }
    for (unsigned i = 1; i < encoderCount; i++) // shift in the the rest of the encoders
    {
        digitalWriteFast(CLK, HIGH);
        delay50ns();
        if (encoders[i].update(digitalReadFast(A), digitalReadFast(B)) && callback != nullptr)
        {
            callback(i, encoders[i].getValue());
        }
        digitalWriteFast(CLK, LOW);
        delay50ns();
    }
}