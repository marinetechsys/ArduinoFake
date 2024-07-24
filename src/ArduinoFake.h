#ifndef _ARDUINO_FAKE_H_
#define _ARDUINO_FAKE_H_
// clang-format off

#if !defined(UBRRH) && !defined(UBRR0H) && !defined(USBCON)
    #define USBCON
#endif

#include <unordered_map>  
#include <cstring>
#include <cstdint>
#include <stdexcept>
#include "fakeit.hpp"

#include "arduino/Arduino.h"

#include "FunctionFake.h"
#include "StreamFake.h"
#include "SerialFake.h"
#include "WireFake.h"
#include "ClientFake.h"
#include "PrintFake.h"
#include "SPIFake.h"
#include "EEPROMFake.h"

#define ArduinoFake(mock) _ArduinoFakeGet##mock()

#define ArduinoFakeReset() \
    getArduinoFakeContext()->reset()

#define ArduinoFakeInstance(mock, ...) \
    getArduinoFakeContext()->mock(__VA_ARGS__)

#define ArduinoFakeMock(mock) \
    new mock##FakeProxy(ArduinoFakeInstance(mock))

#define _ArduinoFakeGetMock(mock) \
    getArduinoFakeContext()->Mocks->mock

#define _ArduinoFakeGetFunction() _ArduinoFakeGetMock(Function)
#if defined(USBCON)
#define _ArduinoFakeGetSerial() _ArduinoFakeGetMock(Serial)
#else
#define _ArduinoFakeGetHardwareSerial() _ArduinoFakeGetMock(Serial)
#endif
#define _ArduinoFakeGetWire() _ArduinoFakeGetMock(Wire)
#define _ArduinoFakeGetSPI() _ArduinoFakeGetMock(SPI)
#define _ArduinoFakeGetEEPROM() _ArduinoFakeGetMock(EEPROM)
#define _ArduinoFakeGetStream() _ArduinoFakeGetMock(Stream)
#define _ArduinoFakeGetClient() _ArduinoFakeGetMock(Client)
#define _ArduinoFakeGetPrint() _ArduinoFakeGetMock(Print)
#define _ArduinoFakeGet() _ArduinoFakeGetMock(Function)

#define _ArduinoFakeInstanceGetter1(mock) \
    mock##Fake* mock() \
    { \
        if (!this->Instances->mock){ \
            this->Instances->mock = &this->Mocks->mock.get(); \
        } \
        return this->Instances->mock; \
    }

#define _ArduinoFakeInstanceGetter2(name, clazz) \
    name##Fake* name(class clazz* instance) \
    { \
        if (Mapping[instance]) { \
            return (name##Fake*) Mapping[instance]; \
        } \
        if (dynamic_cast<name##FakeProxy*>(instance)) { \
            return dynamic_cast<name##FakeProxy*>(instance)->get##name##Fake(); \
        } \
        throw std::runtime_error("Unknown instance"); \
    }

struct ArduinoFakeMocks
{
    fakeit::Mock<FunctionFake> Function;
    fakeit::Mock<SerialFake> Serial;
    fakeit::Mock<WireFake> Wire;
    fakeit::Mock<StreamFake> Stream;
    fakeit::Mock<ClientFake> Client;
    fakeit::Mock<PrintFake> Print;
    fakeit::Mock<SPIFake> SPI;
    fakeit::Mock<EEPROMFake> EEPROM;
};

struct ArduinoFakeInstances
{
    FunctionFake* Function;
    SerialFake* Serial;
    WireFake* Wire;
    StreamFake* Stream;
    ClientFake* Client;
    PrintFake* Print;
    SPIFake* SPI;
    EEPROMFake* EEPROM;
};

class ArduinoFakeContext
{
    public:
        ArduinoFakeInstances* Instances = new ArduinoFakeInstances();
        ArduinoFakeMocks* Mocks = new ArduinoFakeMocks();
        std::unordered_map<void*, void*> Mapping;

        // Mock default data.
        SPISettings settings;
        uint8_t data = 0x01;
        uint8_t buffer[3] = {0x02, 0x03, 0x04};
        uint8_t *ptr = buffer;
        String str1 = String('X');
        String str2 = String('Z');

        _ArduinoFakeInstanceGetter1(Print)
        _ArduinoFakeInstanceGetter1(Stream)
        _ArduinoFakeInstanceGetter1(Serial)
        _ArduinoFakeInstanceGetter1(Wire)
        _ArduinoFakeInstanceGetter1(Client)
        _ArduinoFakeInstanceGetter1(Function)
        _ArduinoFakeInstanceGetter1(SPI)
        _ArduinoFakeInstanceGetter1(EEPROM)

        _ArduinoFakeInstanceGetter2(Print, Print)
        _ArduinoFakeInstanceGetter2(Client, Client)
        _ArduinoFakeInstanceGetter2(Stream, Stream)
#if defined(USBCON)
        _ArduinoFakeInstanceGetter2(Serial, Serial_)
#else
        _ArduinoFakeInstanceGetter2(Serial, HardwareSerial)
#endif
        _ArduinoFakeInstanceGetter2(Wire, TwoWire)
        _ArduinoFakeInstanceGetter2(SPI, SPIClass)
        _ArduinoFakeInstanceGetter2(EEPROM, EEPROMClass)

        ArduinoFakeContext()
        {
            this->reset();
            this->setDefaults();
        }

        void setDefaults();

        void reset(void)
        {
            this->Instances = new ArduinoFakeInstances();

            this->Mocks->Function.Reset();
            this->Mocks->Stream.Reset();
            this->Mocks->Serial.Reset();
            this->Mocks->Wire.Reset();
            this->Mocks->Client.Reset();
            this->Mocks->Print.Reset();
            this->Mocks->SPI.Reset();
            this->Mocks->EEPROM.Reset();
            Mapping[&::Serial] = this->Serial();
            Mapping[&::Wire] = this->Wire();
            Mapping[&::SPI] = this->SPI();
            Mapping[&::EEPROM] = this->EEPROM();
        }
};

ArduinoFakeContext* getArduinoFakeContext();

#define Serial1 Serial
#define Serial2 Serial
#define Serial3 Serial

#endif //_ARDUINO_FAKE_H_
// clang-format on