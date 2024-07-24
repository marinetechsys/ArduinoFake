#include "ArduinoFake.h"

ArduinoFakeContext* arduinoFakeContext;

ArduinoFakeContext* getArduinoFakeContext()
{
    if (!arduinoFakeContext) {
        arduinoFakeContext = new ArduinoFakeContext();
    }

    return arduinoFakeContext;
}

void ArduinoFakeContext::setDefaults()
{
    fakeit::When(Method(Mocks->Function, pinMode)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, attachInterrupt)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, detachInterrupt)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, micros)).AlwaysReturn(100000);
    fakeit::When(Method(Mocks->Function, millis)).AlwaysReturn(200000);
    fakeit::When(Method(Mocks->Function, digitalWrite)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, digitalRead)).AlwaysReturn(LOW);
    fakeit::When(Method(Mocks->Function, analogWrite)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, analogRead)).AlwaysReturn(123);
    fakeit::When(Method(Mocks->Function, analogReadResolution)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, analogWriteFrequency)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, analogWriteResolution)).AlwaysReturn();

    fakeit::When(Method(Mocks->Function, yield)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, delay)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, delayMicroseconds)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, pulseIn)).AlwaysReturn(1000);
    fakeit::When(Method(Mocks->Function, shiftIn)).AlwaysReturn(8);
    fakeit::When(Method(Mocks->Function, shiftOut)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, cli)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, sei)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, randomSeed)).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Function, random, long(long))).AlwaysReturn(11);
    fakeit::When(OverloadedMethod(Mocks->Function, random, long(long, long))).AlwaysReturn(21);
    fakeit::When(Method(Mocks->Function, tone)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, noTone)).AlwaysReturn();
    fakeit::When(Method(Mocks->Function, map)).AlwaysReturn(5);

    fakeit::When(OverloadedMethod(Mocks->Print, print, size_t(char))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, print, size_t(const char *))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, print, size_t(unsigned char, int))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, print, size_t(int, int))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, print, size_t(long, int))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, print, size_t(double, int))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, print, size_t(unsigned int, int))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, print, size_t(unsigned long, int))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, println, size_t())).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, println, size_t(char))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, println, size_t(const char *))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, println, size_t(unsigned char, int))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, println, size_t(int, int))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, println, size_t(long, int))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, println, size_t(double, int))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, println, size_t(unsigned int, int))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, println, size_t(unsigned long, int))).AlwaysReturn();

    //fakeit::When(OverloadedMethod(Mocks->Stream, print, size_t(char))).AlwaysReturn();
    //fakeit::When(OverloadedMethod(Mocks->Stream, print, size_t(int, int))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Serial, print, size_t(char))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Serial, print, size_t(int, int))).AlwaysReturn();
    fakeit::When(Method(Mocks->Serial, available)).AlwaysReturn(1);
    fakeit::When(OverloadedMethod(Mocks->Serial, print, size_t(char))).AlwaysReturn(1);
    fakeit::When(Method(Mocks->Serial, end)).AlwaysReturn();
    fakeit::When(Method(Mocks->Serial, flush)).AlwaysReturn();
    fakeit::When(Method(Mocks->Serial, available)).AlwaysReturn(1);
    fakeit::When(OverloadedMethod(Mocks->Serial, write, size_t(uint8_t))).AlwaysReturn(1);
    fakeit::When(OverloadedMethod(Mocks->Serial, begin, void(unsigned long))).AlwaysReturn();

    fakeit::When(OverloadedMethod(Mocks->SPI, begin, void(void))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->SPI, end, void(void))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->SPI, beginTransaction, void(SPISettings)).Using(settings)).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->SPI, endTransaction, void(void))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->SPI, transfer, uint8_t(uint8_t)).Using(data)).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->SPI, transfer, void(void*, size_t)).Using(ptr, sizeof(buffer))).AlwaysReturn();

    /*
    fakeit::When(OverloadedMethod(Mocks->Stream, print, size_t(char))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Stream, print, size_t(int, int))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, print, size_t(char))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Print, print, size_t(int, int))).AlwaysReturn();
    fakeit::When(Method(Mocks->Stream, available)).Return(0, 1, 0);
    fakeit::When(Method(Mocks->Stream, read)).Return(11, 12, 13);
    fakeit::When(Method(Mocks->Stream, peek)).Return(21, 22, 23);
    fakeit::When(Method(Mocks->Stream, flush)).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Stream, find, bool(char*))).Return(true, false);
    fakeit::When(OverloadedMethod(Mocks->Stream, find, bool(char*, size_t))).Return(true, false);
    fakeit::When(OverloadedMethod(Mocks->Stream, findUntil, bool(char*, char*))).Return(true, false);
    fakeit::When(OverloadedMethod(Mocks->Stream, findUntil, bool(char*, size_t, char*, size_t))).Return(true, false);
    fakeit::When(Method(Mocks->Stream, parseInt)).Return(10, 11);
    fakeit::When(Method(Mocks->Stream, parseFloat)).Return(2.0, 2.1);
    fakeit::When(Method(Mocks->Stream, readBytes)).Return(1, 2);
    fakeit::When(Method(Mocks->Stream, readBytesUntil)).Return(3, 4);
    fakeit::When(Method(Mocks->Stream, readString)).Return(str1, str2);
    fakeit::When(Method(Mocks->Stream, readStringUntil)).Return(str1, str2);
    */

    fakeit::When(OverloadedMethod(Mocks->Wire, print, size_t(char))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Wire, print, size_t(int, int))).AlwaysReturn();
    fakeit::When(Method(Mocks->Wire, available)).AlwaysReturn(1);
    fakeit::When(OverloadedMethod(Mocks->Wire, print, size_t(char))).AlwaysReturn(1);
    fakeit::When(OverloadedMethod(Mocks->Wire, begin, void(void))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Wire, beginTransmission, void(uint8_t))).AlwaysReturn();
    fakeit::When(OverloadedMethod(Mocks->Wire, write, size_t(uint8_t))).AlwaysReturn(true);
    fakeit::When(OverloadedMethod(Mocks->Wire, endTransmission, uint8_t(bool))).AlwaysReturn(0);
    fakeit::When(OverloadedMethod(Mocks->Wire, requestFrom, uint8_t(uint8_t, uint8_t))).AlwaysReturn(0);
    fakeit::When(OverloadedMethod(Mocks->Wire, available, int(void))).AlwaysReturn(1);
    fakeit::When(OverloadedMethod(Mocks->Wire, read, int(void))).AlwaysReturn(1);

    fakeit::When(Method(Mocks->EEPROM, read)).AlwaysReturn(255);
    fakeit::When(Method(Mocks->EEPROM, write)).AlwaysReturn();
    fakeit::When(Method(Mocks->EEPROM, update)).AlwaysReturn();
    fakeit::When(Method(Mocks->EEPROM, length)).AlwaysReturn(1);
}
