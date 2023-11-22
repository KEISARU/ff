#include <JetsonGPIO.h>
#include <delivery_bot_package/DigiPot.h>
#include <unistd.h>

#define DIGIPOT_UP          GPIO::HIGH
#define DIGIPOT_DOWN        GPIO::LOW
#define DIGIPOT_MAX_AMOUNT  99
#define DIGIPOT_UNKNOWN     255

DigiPot::DigiPot(int udPin, int incPin, int csPin) : _udPin(udPin), _incPin(incPin), _csPin(csPin),
                                                     _currentValue(DIGIPOT_UNKNOWN) {
    GPIO::setmode(GPIO::BOARD);
    GPIO::setup(_udPin, GPIO::OUT, GPIO::LOW);
    GPIO::setup(_incPin, GPIO::OUT, GPIO::LOW);
    GPIO::setup(_csPin, GPIO::OUT, GPIO::HIGH);
}

void DigiPot::reset() {
    decrease(DIGIPOT_MAX_AMOUNT);
    _currentValue = 0;
}

void DigiPot::set(int value) {
    value = std::min(value, DIGIPOT_MAX_AMOUNT);
    if (_currentValue == DIGIPOT_UNKNOWN) reset();
    if (_currentValue > value) {
        change(DIGIPOT_DOWN, _currentValue - value);
    } else if (_currentValue < value) {
        change(DIGIPOT_UP, value - _currentValue);
    }
}

uint8_t DigiPot::get() {
    return _currentValue;
}

void DigiPot::increase(int amount) {
    amount = std::min(amount, DIGIPOT_MAX_AMOUNT);
    change(DIGIPOT_UP, amount);
}

void DigiPot::decrease(int amount) {
    amount = std::min(amount, DIGIPOT_MAX_AMOUNT);
    change(DIGIPOT_DOWN, amount);
}

void DigiPot::change(uint8_t direction, int amount) {
    amount = std::min(amount, DIGIPOT_MAX_AMOUNT);
    GPIO::output(_udPin, direction);
    GPIO::output(_incPin, GPIO::HIGH);
    GPIO::output(_csPin, GPIO::LOW);

    for (uint8_t i = 0; i < amount; i++) {
        GPIO::output(_incPin, GPIO::LOW);
        usleep(2);
        GPIO::output(_incPin, GPIO::HIGH);
        usleep(2);
        if (_currentValue != DIGIPOT_UNKNOWN) {
            _currentValue += (direction == DIGIPOT_UP ? 1 : -1);
            _currentValue = std::max(0, std::min(_currentValue, DIGIPOT_MAX_AMOUNT));
        }
    }
    GPIO::output(_csPin, GPIO::HIGH);
}
