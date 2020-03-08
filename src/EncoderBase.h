#pragma once
#include "config.h"
#include "wiring.h"
#include <cstdint>

class EncPlexBase;

namespace PollingEncoder
{
    class EncoderBase
    {
     public:
        EncoderBase() {}

        int32_t read() const { return value; }
        void set(int32_t val)
        {
            noInterrupts();
            last = val << spr;
            raw = val << spr;
            value = val;
            interrupts();
        }

        bool update(uint32_t phaseA, uint32_t phaseB);
        void setLimits(int32_t min, int32_t max);
        void setCallback(encCallback_t cb) { callback = cb; }

     protected:
        int32_t raw = 0;
        int32_t value = 0;
        int32_t last = 0;

        bool limit = false;
        int32_t min, max;

        encCallback_t callback = nullptr;

        const unsigned spr = 0;

        EncoderBase& operator=(EncoderBase const&) = delete;
        EncoderBase(EncoderBase const&) = delete;
    };
}