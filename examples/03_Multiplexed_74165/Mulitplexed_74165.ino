#include "Arduino.h"
#include "EncPlex.h"

constexpr unsigned encoderCount = 4; //number of attached encoders (daisy chain shift regesters for more than 8)
constexpr unsigned pinLD = 14;       //load pin for all shift registers)
constexpr unsigned pinCLK = 15;      //clock pin for all shift registers
constexpr unsigned QH_A = 0;         //output pin QH of shift register A
constexpr unsigned QH_B = 1;         //output pin QH of shift register B
                                     //74165 datasheet: http://www.ti.com/product/SN74HC165

EncPlex74165 encoders(encoderCount, pinLD, pinCLK, QH_A, QH_B);

void encoderCallback(uint32_t encNr, int32_t value)
{
    Serial.printf("Encoder %d: %3d\n", encNr, value);
}

void setup()
{
    encoders.setCallback(encoderCallback);
}

void loop()
{
    encoders.tick(); // call as often as possible (~1-2kHz should be fine for mechanical encoders)
}
