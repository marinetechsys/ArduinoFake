// Lightweight spy helpers for Arduino function calls in native tests
#pragma once
#include <cstdint>

namespace ArduinoSpy {

void reset();

// When enabled, FunctionFake routes to ArduinoFake proxies so Verify/When works.
// When disabled, calls only update the spy storage (safe before tests start).
void enableProxy(bool enable);

// Returns last set mode for pin, or 0xFF if never set
uint8_t pinModeOf(uint8_t pin);

// Returns last digitalWrite value for pin, or -1 if never written
int digitalValueOf(uint8_t pin);

// Returns last analogWrite value for pin, or -1 if never written
int analogValueOf(uint8_t pin);

// Returns last analogWriteFrequency for pin, or -1 if never set
int analogFrequencyOf(uint8_t pin);

// Returns last analogWriteResolution for pin, or -1 if never set
int analogResolutionOf(uint8_t pin);

} // namespace ArduinoSpy
