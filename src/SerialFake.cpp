#include "ArduinoFake.h"
#include "SerialFake.h"
#include <stdarg.h>

#if defined(USBCON)

void Serial_::begin(unsigned long baud_count)
{
    ArduinoFakeInstance(Serial, this)->begin(baud_count);
}

void Serial_::begin(unsigned long baud_count, uint8_t config)
{
    ArduinoFakeInstance(Serial, this)->begin(baud_count, config);
}

void Serial_::end(void)
{
    ArduinoFakeInstance(Serial, this)->end();
}

int Serial_::available(void)
{
    return ArduinoFakeInstance(Serial, this)->available();
}

int Serial_::peek(void)
{
    return ArduinoFakeInstance(Serial, this)->peek();
}

int Serial_::read(void)
{
    return ArduinoFakeInstance(Serial, this)->read();
}

int Serial_::availableForWrite(void)
{
    return ArduinoFakeInstance(Serial, this)->availableForWrite();
}

void Serial_::flush(void)
{
    ArduinoFakeInstance(Serial, this)->flush();
}

size_t Serial_::write(uint8_t c)
{
    return ArduinoFakeInstance(Serial, this)->write(c);
}

size_t Serial_::write(const uint8_t *buffer, size_t size)
{
    return ArduinoFakeInstance(Serial, this)->write(buffer, size);
}

uint32_t Serial_::baud()
{
    return ArduinoFakeInstance(Serial, this)->baud();
}

uint8_t Serial_::stopbits()
{
    return ArduinoFakeInstance(Serial, this)->stopbits();
}

uint8_t Serial_::paritytype()
{
    return ArduinoFakeInstance(Serial, this)->paritytype();
}

uint8_t Serial_::numbits()
{
    return ArduinoFakeInstance(Serial, this)->numbits();
}

bool Serial_::dtr()
{
    return ArduinoFakeInstance(Serial, this)->dtr();
}

bool Serial_::rts()
{
    return ArduinoFakeInstance(Serial, this)->rts();
}

int32_t Serial_::readBreak()
{
    return ArduinoFakeInstance(Serial, this)->readBreak();
}

Serial_ Serial = SerialFakeProxy(ArduinoFakeInstance(Serial));
#else // USBCON

void HardwareSerial::begin(unsigned long baud_count)
{
    ArduinoFakeInstance(Serial, this)->begin(baud_count);
}

void HardwareSerial::begin(unsigned long baud_count, uint8_t config)
{
    ArduinoFakeInstance(Serial, this)->begin(baud_count, config);
}

void HardwareSerial::end(void)
{
    ArduinoFakeInstance(Serial, this)->end();
}

int HardwareSerial::available(void)
{
    return ArduinoFakeInstance(Serial, this)->available();
}

int HardwareSerial::peek(void)
{
    return ArduinoFakeInstance(Serial, this)->peek();
}

int HardwareSerial::read(void)
{
    return ArduinoFakeInstance(Serial, this)->read();
}

int HardwareSerial::availableForWrite(void)
{
    return ArduinoFakeInstance(Serial, this)->availableForWrite();
}

void HardwareSerial::flush(void)
{
    ArduinoFakeInstance(Serial, this)->flush();
}

size_t HardwareSerial::write(uint8_t c)
{
    return ArduinoFakeInstance(Serial, this)->write(c);
}

size_t HardwareSerial::write(const uint8_t *buffer, size_t size)
{
    return ArduinoFakeInstance(Serial, this)->write(buffer, size);
}

HardwareSerial Serial = SerialFakeProxy(0, ArduinoFakeInstance(Serial));

#if defined(UBRR1H)
HardwareSerial Serial1 = SerialFakeProxy(1, ArduinoFakeInstance(Serial1));
#endif
#if defined(UBRR2H)
HardwareSerial Serial2 = SerialFakeProxy(2, ArduinoFakeInstance(Serial2));
#endif
#if defined(UBRR3H)
HardwareSerial Serial3 = SerialFakeProxy(3, ArduinoFakeInstance(Serial3));
#endif
#if defined(UBRR4H)
HardwareSerial Serial4 = SerialFakeProxy(4, ArduinoFakeInstance(Serial4));
#endif
#if defined(UBRR5H)
HardwareSerial Serial5 = SerialFakeProxy(5, ArduinoFakeInstance(Serial5));
#endif
#if defined(UBRR6H)
HardwareSerial Serial6 = SerialFakeProxy(6, ArduinoFakeInstance(Serial6));
#endif
#if defined(UBRR7H)
HardwareSerial Serial7 = SerialFakeProxy(7, ArduinoFakeInstance(Serial7));
#endif
#if defined(UBRR8H)
HardwareSerial Serial8 = SerialFakeProxy(8, ArduinoFakeInstance(Serial8));
#endif
#if defined(UBRR9H)
HardwareSerial Serial9 = SerialFakeProxy(9, ArduinoFakeInstance(Serial9));
#endif

#endif // USBCON