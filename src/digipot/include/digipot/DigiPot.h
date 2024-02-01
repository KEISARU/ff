#ifndef DigiPot_H
#define DigiPot_H

#include <cstdint>

/**
 * @brief Rewrite of DigiPot library
 * using JetsonGPIO library
 */
class DigiPot {
public:
    DigiPot(int udPin, int incPin, int csPin);

    void reset();

    void set(int value);

    uint8_t get();

    void increase(int amount);

    void decrease(int amount);

    void change(uint8_t direction, int amount);

private:
    int _udPin;
    int _incPin;
    int _csPin;
    int _currentValue;
};
#endif //DigiPot_H
