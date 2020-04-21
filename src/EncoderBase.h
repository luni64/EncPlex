#pragma once
#include "config.h"
#include "wiring.h"
#include <cstdint>

class EncPlexBase;

namespace EncPlex
{
    class EncoderBase
    {
     public:
        EncoderBase();

        void setStepsPerDetent(unsigned spd);

        int32_t read() const { return value; }
        void set(int32_t val);

        bool update(uint32_t phaseA, uint32_t phaseB);
        // tbd void setLimits(int32_t min, int32_t max);
        void setCallback(encCallback_t cb) { callback = cb; }

     protected:
        int32_t raw = 0;
        int32_t value = 0;
        int32_t last = 0;

        // bool limit = false;
        // int32_t min, max;

        encCallback_t callback = nullptr;

        const unsigned spr = 0;
        int stepsPerDetent = 4;

        EncoderBase& operator=(EncoderBase const&) = delete;
        EncoderBase(EncoderBase const&) = delete;
    };
}