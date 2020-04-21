#pragma once

#include "config.h"
#include "EncoderBase.h"

namespace EncPlex
{
    class EncPlexBase
    {
     public:
        void setCallback(allCallback_t callback);
        EncoderBase& operator[](std::size_t idx);

     protected:
        EncPlexBase(unsigned EncoderCount, unsigned stepsPerDetent);
        const uint32_t encoderCount;
        EncoderBase* encoders;

        allCallback_t callback = nullptr;
    };


}
