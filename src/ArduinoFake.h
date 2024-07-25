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

#define _ArduinoFakeInstanceGetter11(mock, mockid) \
    mock##Fake* mockid() \
    { \
        if (!this->Instances->mockid){ \
            this->Instances->mockid = &this->Mocks->mockid.get(); \
        } \
        return this->Instances->mockid; \
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
    fakeit::Mock<WireFake> Wire;
    fakeit::Mock<StreamFake> Stream;
    fakeit::Mock<ClientFake> Client;
    fakeit::Mock<PrintFake> Print;
    fakeit::Mock<SPIFake> SPI;
    fakeit::Mock<EEPROMFake> EEPROM;
    fakeit::Mock<SerialFake> Serial;
    fakeit::Mock<SerialFake> Serial1;
    fakeit::Mock<SerialFake> Serial2;
    fakeit::Mock<SerialFake> Serial3;
    fakeit::Mock<SerialFake> Serial4;
    fakeit::Mock<SerialFake> Serial5;
    fakeit::Mock<SerialFake> Serial6;
    fakeit::Mock<SerialFake> Serial7;
    fakeit::Mock<SerialFake> Serial8;
    fakeit::Mock<SerialFake> Serial9;
};

struct ArduinoFakeInstances
{
    FunctionFake* Function;
    WireFake* Wire;
    StreamFake* Stream;
    ClientFake* Client;
    PrintFake* Print;
    SPIFake* SPI;
    EEPROMFake* EEPROM;
    SerialFake* Serial;
    SerialFake* Serial1;
    SerialFake* Serial2;
    SerialFake* Serial3;
    SerialFake* Serial4;
    SerialFake* Serial5;
    SerialFake* Serial6;
    SerialFake* Serial7;
    SerialFake* Serial8;
    SerialFake* Serial9;
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
        _ArduinoFakeInstanceGetter1(Wire)
        _ArduinoFakeInstanceGetter1(Client)
        _ArduinoFakeInstanceGetter1(Function)
        _ArduinoFakeInstanceGetter1(SPI)
        _ArduinoFakeInstanceGetter1(EEPROM)

        _ArduinoFakeInstanceGetter11(Serial, Serial)
        _ArduinoFakeInstanceGetter11(Serial, Serial1)
        _ArduinoFakeInstanceGetter11(Serial, Serial2)
        _ArduinoFakeInstanceGetter11(Serial, Serial3)
        _ArduinoFakeInstanceGetter11(Serial, Serial4)
        _ArduinoFakeInstanceGetter11(Serial, Serial5)
        _ArduinoFakeInstanceGetter11(Serial, Serial6)
        _ArduinoFakeInstanceGetter11(Serial, Serial7)
        _ArduinoFakeInstanceGetter11(Serial, Serial8)
        _ArduinoFakeInstanceGetter11(Serial, Serial9)

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
        void setSerialDefaults(fakeit::Mock<SerialFake>&);

        void reset(void)
        {
            this->Instances = new ArduinoFakeInstances();

            this->Mocks->Function.Reset();
            this->Mocks->Stream.Reset();
            this->Mocks->Wire.Reset();
            this->Mocks->Client.Reset();
            this->Mocks->Print.Reset();
            this->Mocks->SPI.Reset();
            this->Mocks->EEPROM.Reset();
            this->Mocks->Serial.Reset();
            this->Mocks->Serial1.Reset();
            this->Mocks->Serial2.Reset();
            this->Mocks->Serial3.Reset();
            this->Mocks->Serial4.Reset();
            this->Mocks->Serial5.Reset();
            this->Mocks->Serial6.Reset();
            this->Mocks->Serial7.Reset();
            this->Mocks->Serial8.Reset();
            this->Mocks->Serial9.Reset();
            Mapping[&::Wire] = this->Wire();
            Mapping[&::SPI] = this->SPI();
            Mapping[&::EEPROM] = this->EEPROM();
            Mapping[&::Serial] = this->Serial();
            Mapping[&::Serial1] = this->Serial1();
            Mapping[&::Serial2] = this->Serial2();
            Mapping[&::Serial3] = this->Serial3();
            Mapping[&::Serial4] = this->Serial4();
            Mapping[&::Serial5] = this->Serial5();
            Mapping[&::Serial6] = this->Serial6();
            Mapping[&::Serial7] = this->Serial7();
            Mapping[&::Serial8] = this->Serial8();
            Mapping[&::Serial9] = this->Serial9();
        }
};

ArduinoFakeContext* getArduinoFakeContext();

#if !defined(UBRR1H)
#define Serial1 Serial
#endif
#if !defined(UBRR2H)
#define Serial2 Serial
#endif
#if !defined(UBRR3H)
#define Serial3 Serial
#endif
#if !defined(UBRR4H)
#define Serial4 Serial
#endif
#if !defined(UBRR5H)
#define Serial5 Serial
#endif
#if !defined(UBRR6H)
#define Serial6 Serial
#endif
#if !defined(UBRR7H)
#define Serial7 Serial
#endif
#if !defined(UBRR8H)
#define Serial8 Serial
#endif
#if !defined(UBRR9H)
#define Serial9 Serial
#endif

#endif //_ARDUINO_FAKE_H_
// clang-format on