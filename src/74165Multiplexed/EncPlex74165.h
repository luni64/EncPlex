#pragma once

#include "EncPlexBase.h"

namespace EncPlex
{
    class EncPlex74165 : public EncPlexBase
    {
     public:
        EncPlex74165(unsigned EncoderCount, unsigned pinLD, unsigned pinCLK, unsigned pinA, unsigned pinB, unsigned stepsPerDetent = 4);
        // tbd EncPlex74165(unsigned EncoderCount, unsigned pinLD, unsigned pinCLK, unsigned pinA, unsigned pinB, unsigned pinS); // incl.switch TBD

        void begin(); // optional, call in setup if other code grabed the pins after construction

        void tick(); // call as often as possible

     protected:
        const unsigned A, B, S, LD, CLK;
    };

}