#include "EncPlexBase.h"

namespace EncPlex
{
    EncPlexBase::EncPlexBase(unsigned eCnt, unsigned spd)
        : encoderCount(eCnt), encoders(new EncoderBase[eCnt])
    {
        for (int i = 0; i < eCnt; i++)
        {
            encoders[i].setStepsPerDetent(spd);
        }
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