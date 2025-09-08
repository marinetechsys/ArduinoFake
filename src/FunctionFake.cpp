#include "FunctionFake.h"
#include "ArduinoFake.h"
#include "ArduinoSpy.h"
#include <array>

// Simple in-process spy storage for native tests
static std::array<int, 256> g_pinMode;              // -1 if unset
static std::array<int, 256> g_digitalValue;         // -1 if unset
static std::array<int, 256> g_analogWriteValue;     // -1 if unset
static std::array<int, 256> g_analogWriteFrequency; // -1 if unset
static std::array<int, 256> g_analogWriteResolution;// -1 if unset
static bool g_proxyEnabled = false;

namespace ArduinoSpy {
void reset() {
    g_pinMode.fill(-1);
    g_digitalValue.fill(-1);
    g_analogWriteValue.fill(-1);
    g_analogWriteFrequency.fill(-1);
    g_analogWriteResolution.fill(-1);
}
void enableProxy(bool enable) { g_proxyEnabled = enable; }
uint8_t pinModeOf(uint8_t pin) {
    int v = g_pinMode[pin];
    return v < 0 ? 0xFF : static_cast<uint8_t>(v);
}
int digitalValueOf(uint8_t pin) {
    return g_digitalValue[pin];
}
int analogValueOf(uint8_t pin) {
    return g_analogWriteValue[pin];
}
int analogFrequencyOf(uint8_t pin) {
    return g_analogWriteFrequency[pin];
}
int analogResolutionOf(uint8_t pin) {
    return g_analogWriteResolution[pin];
}
} // namespace ArduinoSpy

void pinMode(uint8_t pin, uint8_t mode)
{
    if (g_proxyEnabled) {
        ArduinoFakeInstance(Function)->pinMode(pin, mode);
    } else {
        g_pinMode[pin] = mode;
    }
}

void digitalWrite(uint8_t pin, uint8_t val)
{
    if (g_proxyEnabled) {
        ArduinoFakeInstance(Function)->digitalWrite(pin, val);
    } else {
        g_digitalValue[pin] = val;
    }
}

int digitalRead(uint8_t pin)
{
    if (g_proxyEnabled) {
        return ArduinoFakeInstance(Function)->digitalRead(pin);
    }
    return g_digitalValue[pin] < 0 ? LOW : g_digitalValue[pin];
}

int analogRead(uint8_t pin)
{
    return ArduinoFakeInstance(Function)->analogRead(pin);
}

void analogWrite(uint8_t pin, int val)
{
    if (g_proxyEnabled) {
        ArduinoFakeInstance(Function)->analogWrite(pin, val);
    } else {
        g_analogWriteValue[pin] = val;
    }
}

void analogWriteFrequency(uint8_t pin, int val)
{
    if (g_proxyEnabled) {
        ArduinoFakeInstance(Function)->analogWriteFrequency(pin, val);
    } else {
        g_analogWriteFrequency[pin] = val;
    }
}

void analogWriteResolution(uint8_t pin, int val)
{
    if (g_proxyEnabled) {
        ArduinoFakeInstance(Function)->analogWriteResolution(pin, val);
    } else {
        g_analogWriteResolution[pin] = val;
    }
}

void analogReference(uint8_t mode)
{
    ArduinoFakeInstance(Function)->analogReference(mode);
}

void analogReadResolution(uint8_t mode)
{
    ArduinoFakeInstance(Function)->analogReadResolution(mode);
}

unsigned long millis(void)
{
    return ArduinoFakeInstance(Function)->millis();
}

unsigned long micros(void)
{
    return ArduinoFakeInstance(Function)->micros();
}

void delay(unsigned long value)
{
    ArduinoFakeInstance(Function)->delay(value);
}

void delayMicroseconds(unsigned int us)
{
    ArduinoFakeInstance(Function)->delayMicroseconds(us);
}

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout)
{
    return ArduinoFakeInstance(Function)->pulseIn(pin, state, timeout);
}

unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout)
{
    return ArduinoFakeInstance(Function)->pulseInLong(pin, state, timeout);
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
    ArduinoFakeInstance(Function)->shiftOut(dataPin, clockPin, bitOrder, val);
}

uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder) {
    return ArduinoFakeInstance(Function)->shiftIn(dataPin, clockPin, bitOrder);
}

void detachInterrupt(uint8_t interruptNum) {
    ArduinoFakeInstance(Function)->detachInterrupt(interruptNum);
}

void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode) {
	ArduinoFakeInstance(Function)->attachInterrupt(interruptNum, userFunc, mode);
}

void cli() {
    ArduinoFakeInstance(Function)->cli();
}

void sei() {
    ArduinoFakeInstance(Function)->sei();
}

void tone(uint8_t pin, unsigned int frequency, unsigned long duration)
{
    ArduinoFakeInstance(Function)->tone(pin, frequency, duration);
}

void noTone(uint8_t pin)
{
    ArduinoFakeInstance(Function)->noTone(pin);
}

long random(long max)
{
    return ArduinoFakeInstance(Function)->random(max);
}

long random(long min, long max)
{
    return ArduinoFakeInstance(Function)->random(min, max);
}

void randomSeed(unsigned long seed)
{
    return ArduinoFakeInstance(Function)->randomSeed(seed);
}

long map(long value, long fromLow, long fromHigh, long toLow, long toHigh)
{
    return ArduinoFakeInstance(Function)->map(value, fromLow, fromHigh, toLow, toHigh);
}

void yield()
{
    ArduinoFakeInstance(Function)->yield();
}
