#include <MicroView.h>
#include "Keypad5Btn.h"

int buttonVal;


Keypad5Btn keypad(A5, PULL_UP_DISABLED);

void setup()
{

	uView.begin();
    uView.clear(PAGE);      // clear the page buffer
    uView.display();
}

void loop()
{
    buttonVal = keypad.checkBtn();
    uView.clear(PAGE);      // clear the page buffer
    uView.setCursor(5,20);
    uView.print(buttonVal);
	uView.display();
	delay(20);
}
