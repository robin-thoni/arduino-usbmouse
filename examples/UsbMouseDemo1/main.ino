#define ARD_UTILS_DELAYMS
#include "ArdUtils/ArdUtils.h"

#include "UsbMouse.h"

#define ledPin 13

void setup()
{
    pinMode (ledPin, OUTPUT);
    digitalWrite (ledPin, HIGH);
}

void loop()
{
    WAIT_USB;

    UsbMouse.move(50, 0);
    //UsbMouse.moveWheel(1);
    //UsbMouse.pressButton(MOUSE_BUTTON_LEFT);
    //UsbMouse.releaseButton(MOUSE_BUTTON_LEFT);

    ArdUtils::delayMs(1000);
    digitalWrite(ledPin, !digitalRead(ledPin));
}
