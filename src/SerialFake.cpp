#include "ArduinoFake.h"
#include "SerialFake.h"
#include <stdarg.h>

#if defined(USBCON)

void Serial_::begin(unsigned long baud_count)
{
    ArduinoFakeInstance(Serial, this)->begin(baud_count);
}

void Serial_::begin(unsigned long baud_count, byte config)
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

void Serial_::printf(const char* fmt, ...)
{
    va_list argv;
    va_start(argv, fmt);

    for (int i = 0; fmt[i] != '\0'; i++) {
        if (fmt[i] == '%') {
            // Look for specification of number of decimal places
            int places = 2;
            if (fmt[i+1] == '.') i++;  // alw1746: Allows %.4f precision like in stdio printf (%4f will still work).
            if (fmt[i+1] >= '0' && fmt[i+1] <= '9') {
                places = fmt[i+1] - '0';
                i++;
            }
            
            switch (fmt[++i]) {
                case 'B':
                    serial.print("0b"); // Fall through intended
                case 'b':
                    serial.print(va_arg(argv, int), BIN);
                    break;
                case 'c': 
                    serial.print((char) va_arg(argv, int));
                    break;
                case 'd': 
                case 'i':
                    serial.print(va_arg(argv, int), DEC);
                    break;
                case 'f': 
                    serial.print(va_arg(argv, double), places);
                    break;
                case 'l': 
                    serial.print(va_arg(argv, long), DEC);
                    break;
                case 'o':
                    serial.print(va_arg(argv, int) == 0 ? "off" : "on");
                    break;
                case 's': 
                    serial.print(va_arg(argv, const char*));
                    break;
                case 'X':
                    serial.print("0x"); // Fall through intended
                case 'x':
                    serial.print(va_arg(argv, int), HEX);
                    break;
                case '%': 
                    serial.print(fmt[i]);
                    break;
                default:
                    serial.print("?");
                    break;
            }
        } else {
            serial.print(fmt[i]);
        }
    }
    va_end(argv);
}

Serial_ Serial = SerialFakeProxy(ArduinoFakeInstance(Serial));

#endif // USBCON