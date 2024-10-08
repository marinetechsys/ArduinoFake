#ifndef _EEPROMFAKE_H_
#define _EEPROMFAKE_H_

#include "arduino/EEPROM.h"

struct EEPROMFake {
  virtual uint8_t read(int idx) = 0;
  virtual void write(int idx, uint8_t val) = 0;
  virtual void update(int idx, uint8_t val) = 0;
  virtual uint16_t length() = 0;
};

class EEPROMFakeProxy : public EEPROMClass {
private:
  EEPROMFake *eepromFake;

public:
  EEPROMFakeProxy(EEPROMFake *fake) { eepromFake = fake; }

  EEPROMFake *getEEPROMFake() { return eepromFake; }
};

#endif //_EEPROMFAKE_H_
