#include "EncPlex4067.h"
#include "Arduino.h"

using namespace EncPlex;

EncPlex4067::EncPlex4067(unsigned encoderCount, unsigned pinS0, unsigned pinS1, unsigned pinS2, unsigned pinS3, unsigned pinA, unsigned pinB, unsigned stepsPerDetent)
    : EncPlexBase(encoderCount, stepsPerDetent),
      S0(pinS0), S1(pinS1), S2(pinS2), S3(pinS3),
      A(pinA), B(pinB)
{
    begin();
}

void EncPlex4067::begin()
{
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);

    pinMode(A, INPUT);
    pinMode(B, INPUT);

    pinMode(12, OUTPUT);
}

void EncPlex4067::tick()
{
    digitalWriteFast(12, HIGH);

    for (unsigned i = 0; i < encoderCount; i++)
    {
        digitalWriteFast(S0, i & 0b0001);
        // digitalWriteFast(S1, i & 0b0010);
        // digitalWriteFast(S2, i & 0b0100);
        // digitalWriteFast(S3, i & 0b1000);
        //delayMicroseconds(1);

        // Serial.print(digitalReadFast(A));
        // Serial.print(" ");

        // if (encoders[i].update(digitalReadFast(A), digitalReadFast(B)) && callback != nullptr)
        // {
        //     callback(0, encoders[i].read());
        // }

    }
        digitalWriteFast(12, LOW);
}