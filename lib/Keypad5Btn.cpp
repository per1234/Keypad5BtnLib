#include "Keypad5Btn.h"

// constructor; takes arguments specifying whether to enable internal pull-up
// and the default state of the pin that the button is connected to
Keypad5Btn::Keypad5Btn(unsigned char pin, unsigned char pullUp, unsigned char defaultState)
{
  _pin = pin;
  _pullUp = pullUp;
  _defaultState = defaultState;
 }


int Keypad5Btn::checkBtn()
{
  init(); // initialize if necessary
  int analogval = getAnalogValue(); 
  
  for (int i=0; i<sizeof(BTN_ANALOG_VALUE); i++) {
  	if(abs(BTN_ANALOG_VALUE[i]-analogval) < BTN_ANALOG_TOLERANCE) {
  		_lastBtn = i;
		 return _lastBtn;
  	}
  }
  _lastBtn = BTN_UNDEFINED;

  return _lastBtn;
}

int Keypad5Btn::getAnalogValue()
{
  init(); // initialize if necessary
  
  return analogRead(_pin);
}

// initializes I/O pin for use as button inputs
void Keypad5Btn::init2()
{
  if (_pullUp == PULL_UP_ENABLED)
    pinMode(_pin, INPUT_PULLUP);
  else
    pinMode(_pin, INPUT); // high impedance

  _lastBtn = BTN_UNDEFINED;
  
  delayMicroseconds(5); // give pull-up time to stabilize
  
}

