#pragma once

#include "config.h"
#include "EncoderBase.h"

namespace PollingEncoder
{
    class EncPlexBase
    {
     public:
        inline void setCallback(allCallback_t callback);
        inline EncoderBase& operator[](std::size_t idx);

     protected:
        inline EncPlexBase(unsigned EncoderCount);
        uint32_t encoderCount;
        EncoderBase* encoders;

        allCallback_t callback = nullptr;
    };

    EncPlexBase::EncPlexBase(unsigned eCnt) : encoderCount(eCnt), encoders(new EncoderBase[eCnt])
    {
    }

    EncoderBase& EncPlexBase::operator[](std::size_t idx)
    {
        return idx < encoderCount ? encoders[idx] : encoders[encoderCount - 1];
    }

    void EncPlexBase::setCallback(allCallback_t _callback)
    {
        callback = _callback;
    }
}
