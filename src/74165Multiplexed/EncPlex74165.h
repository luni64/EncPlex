#pragma once

#include "EncPlexBase.h"

class EncPlex74165 : public PollingEncoder::EncPlexBase
{
 public:
    EncPlex74165(unsigned EncoderCount, unsigned pinLD, unsigned pinCLK, unsigned pinA, unsigned pinB);
    EncPlex74165(unsigned EncoderCount, unsigned pinLD, unsigned pinCLK, unsigned pinA, unsigned pinB, unsigned pinS); // incl.switch TBD
    void tick();  // call as often as possible

    void begin(); // optional, call in setup if other code grabed the pins after construction

 protected:
    const unsigned A, B, S, LD, CLK;
};