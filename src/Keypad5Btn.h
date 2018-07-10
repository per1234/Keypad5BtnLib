#ifndef Keypad5Btn_h
#define Keypad5Btn_h

#include <Arduino.h>


#define PULL_UP_DISABLED    0
#define PULL_UP_ENABLED     1

#define DEFAULT_STATE_LOW   0
#define DEFAULT_STATE_HIGH  1


const int BTN_ANALOG_VALUE[] = {1023, 740, 503, 329, 142, 0};
const int BTN_ANALOG_TOLERANCE = 50;


const int 	BTN_UNDEFINED = -1;
const int 	BTN_NONE = 0;   
const int 	BTN_FIRE = 1;
const int 	BTN_RIGHT = 2;
const int 	BTN_DOWN = 3;
const int 	BTN_UP = 4;
const int 	BTN_LEFT = 5; 

class Keypad5Btn
{
  public:
    
    // constructor; takes arguments specifying whether to enable internal pull-up
    // and the default state of the pin that the button is connected to
    Keypad5Btn(unsigned char pin, unsigned char pullUp = PULL_UP_ENABLED, unsigned char defaultState = DEFAULT_STATE_HIGH);
    
    int checkBtn();
	int getAnalogValue();
    
  private:
  
    unsigned char _pin;
    unsigned char _pullUp;
    unsigned char _defaultState;
    int _lastBtn;

    inline void init()
    {
      static boolean initialized = false;

      if (!initialized)
      {
        initialized = true;
        init2();
      }
    }
    
    // initializes I/O pin for use as button input
    void init2();
    
};

#endif