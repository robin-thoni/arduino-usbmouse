/*
 * Based on Obdev's AVRUSB code and under the same license.
 * Modified by Robin Thoni <robin@rthoni.com>
 */
#ifndef __UsbKeyboard_h__
#define __UsbKeyboard_h__

#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <string.h>

#include "usbdrv.h"

// TODO: Work around Arduino 12 issues better.
//#include <WConstants.h>
//#undef int()

typedef uint8_t byte;

#define WAIT_USB do {           \
  UsbMouse.update();         \
  if (!usbInterruptIsReady())   \
  {                             \
    return;                     \
  }                             \
} while(0)

#define BUFFER_SIZE 4 // Minimum of 2: 1 for modifiers + 1 for keystroke 

typedef struct{
    uchar   buttonMask;
    char    dx;
    char    dy;
    char    dWheel;
}report_t;

#define MOUSE_BUTTON_LEFT   1
#define MOUSE_BUTTON_RIGHT  2
#define MOUSE_BUTTON_MIDDLE 4

static uchar    idleRate;/* repeat rate for keyboards, never used for mice */

class UsbMouseDevice {
public:
    UsbMouseDevice();

    bool isUsbReady();
    
    void update() {
        usbPoll();
    }

    void move(char dx, char dy);

    void moveWheel(char dy);

    void pressButton(char button);

    void releaseButton(char button);

    void setButtonState(char button, bool pressed);

    //void clickButton(char button);

    void updateStatus();

    void resetStatus();
    
    //private: TODO: Make friend?
    report_t reportBuffer;    // buffer for HID reports [ 1 modifier byte + (len-1) key strokes]

private:

};

#include "UsbMouse.hxx"

#endif // __UsbKeyboard_h__
