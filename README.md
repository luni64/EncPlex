# EncPlex

EncPlex is a small class to read encoders (single and multiplexed) using the polling technique instead of the usual interrupt based method.

Advantage: If you have a lot high speed or bouncy encoders, the generated interrupts can lead to a high and unpredictable load.

The following example shows how to use multiplexed encoders (see the extras folder for information about the used hardware)

```c++
#include "Arduino.h"
#include "EncPlex.h"

constexpr unsigned encoderCount = 4; // number of attached  (daisy chain shift regesters for more than 8)

constexpr unsigned pinLD = 14;       //load pin for all shift registers)
constexpr unsigned pinCLK = 15;      //clock pin for all shift registers
constexpr unsigned QH_A = 0;         //output pin QH of shift register A
constexpr unsigned QH_B = 1;         //output pin QH of shift register B
                                     //74165 datasheet: http://www.ti.com/product/SN74HC165

EncPlex74165 encoders(encoderCount, pinLD, pinCLK, QH_A, QH_B);

void setup()
{
  // nothing to do
}

elapsedMillis stopwatch = 0;

void loop()
{
    encoders.tick();      // call as often as possible (~1-2kHz should be fine for mechanical encoders)

    if (stopwatch > 200)  // display encoder values every 200 ms
    {
        for (unsigned i = 0; i < encoderCount; i++)
        {
            Serial.printf("E%u:%3d ", i, encoders[i].read());
        }
        Serial.println();
        stopwatch = 0;
   }
}
```

More examples shortly....
