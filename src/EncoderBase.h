#pragma once
#include "config.h"
#include <cstdint>
#include "wiring.h"

class EncPlexBase;

namespace PollingEncoder
{
    class EncoderBase
    {
     public:
        EncoderBase(){}

        int32_t read() const { return value; }
        void set(int32_t val)
        {
            noInterrupts();
            last = val << 2;
            raw = val << 2;
            value = val;
            interrupts();
        }

        bool update(uint32_t phaseA, uint32_t phaseB);

     protected:
        int32_t raw = 0;
        int32_t value = 0;
        int32_t last = 0;
        encCallback_t callback = nullptr;

        EncoderBase& operator=(EncoderBase const&) = delete;
        EncoderBase(EncoderBase const&) = delete;
    };
}