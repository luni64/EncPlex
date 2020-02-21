#pragma once

#include "EncPlexBase.h"

class EncPlex4067 : public PollingEncoder::EncPlexBase
{
 public:
    EncPlex4067(unsigned EncoderCount, unsigned pinS0, unsigned pinS1, unsigned pinS2, unsigned pinS3, unsigned pinA, unsigned pinB);
    
    void tick();  // call as often as possible

    void begin(); // optional, call in setup if other code grabed the pins after construction

 protected:
    const unsigned S0, S1, S2, S3, A, B;
};