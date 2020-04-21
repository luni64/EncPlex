#pragma once

// un-comment the following line if you prefer plain function pointers for callbacks
//#define PLAIN_ENC_CALLBACK


//================================================================================================================

#if not defined(PLAIN_ENC_CALLBACK)
    #include <functional>
    inline void std::__throw_bad_function_call(){while (1) {}}  // do whatever you want to do instead of an exception
#endif

#include <cstdint>

namespace EncPlex
{
    #if defined(PLAIN_ENC_CALLBACK)
        using encCallback_t = void (*)(int32_t value);
        using allCallback_t = void (*)(uint32_t nr, int32_t value);
    #else
        using encCallback_t = std::function<void(int32_t)>;
        using allCallback_t = std::function<void(uint32_t, int32_t)>;
    #endif
}