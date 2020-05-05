#pragma once
#include "config.h"

namespace EncPlex
{
    enum class CountMode {// cnt per quad period | input at detents | remark
        quarter,          //          1          |       0/0        | standard for mech encoders
        quarterInv,       //          1          |       1/1        |
        half,             //          2          |   0/0 and 1/1    | seldom used
        full              //          4          |       n.a.       | standard for optical encoders w/o detents
    };

    class EncoderBase
    {
     public:
        EncoderBase() = default;
        void setCountMode(CountMode m);

        int32_t getValue() const { return value; }
        void setValue(int32_t val) { value = val; }

        void begin(uint32_t phaseA, uint32_t phaseB);
        bool update(uint32_t phaseA, uint32_t phaseB);
        void setLimits(int32_t min, int32_t max, bool periodic = false);
        void attachCallback(encCallback_t cb) { callback = cb; }

     protected:
        int32_t value = 0;
        int32_t minVal = INT32_MIN, maxVal = INT32_MAX;
        bool periodic = false;
        unsigned invert = 0x00;
        uint8_t curState = 0;

        encCallback_t callback = nullptr;

        static const uint8_t stateMachineQtr[7][4];
        static const uint8_t stateMachineHalf[7][4];
        static const uint8_t stateMachineFull[7][4];
        const uint8_t (*stateMachine)[7][4] = &stateMachineFull;

        EncoderBase& operator=(EncoderBase const&) = delete;
        EncoderBase(EncoderBase const&) = delete;

#if defined(USE_ERROR_CALLBACKS)
     protected:
        encCallback_t errCallback = nullptr;

     public:
        void attachErrorCallback(encCallback_t cb) { errCallback = cb; }
#endif
    };
}