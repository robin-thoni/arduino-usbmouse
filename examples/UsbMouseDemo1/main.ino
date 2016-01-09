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

    /*reportBuffer.buttonMask = 0;
    reportBuffer.dx = 50;
    reportBuffer.dy = 0;
    reportBuffer.dWheel = 0;

    usbSetInterrupt((unsigned char*)(void *)&reportBuffer, sizeof(reportBuffer));
    ArdUtils::delayMs(1000);
    usbSetInterrupt((unsigned char*)(void *)&reportBuffer, sizeof(reportBuffer));*/

    //ArdUtils::delayMs(1000);
    digitalWrite(ledPin, !digitalRead(ledPin));
    //while(1);
}
