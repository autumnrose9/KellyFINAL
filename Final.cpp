#include <iostream> // for the input/output
#include <stdlib.h> // for the getenv call
#include <sys/sysinfo.h> // for the system uptime call
#include <cgicc/Cgicc.h> // the cgicc headers
#include <iomanip>
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include <unistd.h>
#include<unistd.h>
#include "GPIO.h"
#include "AnalogIn.h"

using namespace exploringBB;
using namespace std;

float getTemperature(int adc_value) {     // from the TMP36 datasheet
   float cur_voltage = adc_value * (1.80f/4096.0f); // Vcc = 1.8V, 12-bit
   float diff_degreesC = (cur_voltage-0.75f)/0.01f;
   return (25.0f + diff_degreesC);
}

float getResistance(int adc_value) {
	float cur_voltage = adc_value * (1.80f/4096.0f); // Vcc = 1.8V, 12-bit
	// Top resistance is 10000.0 Ohms.
	float resistance = (cur_voltage *10000.0f) / (1.80f - cur_voltage);
	return resistance;
}

int main()
{
	int state;
	GPIO inGPIO(46);
	GPIO outGPIO(60);
	inGPIO.setDirection(INPUT);
	outGPIO.setDirection(OUTPUT);

	AnalogIn AIN(0);

	state = inGPIO.getValue();
	//button pressed
	if(state == 0)
	{
		cout << "Button Pressed" << endl;
		float resistance = getResistance(AIN.readADCsample());
		cout << "Resistance is: " << resistance << endl;
		outGPIO.setValue(HIGH);
		sleep(1);
		outGPIO.setValue(LOW);
		sleep(1);
		outGPIO.setValue(HIGH);
                sleep(1);
                outGPIO.setValue(LOW);
                sleep(1);
	}
	//button not pressed
	else
	{
		cout << "Button Not Pressed" << endl;
		float temperature = getTemperature(AIN.readADCsample());
		cout << "Temperature is: " << temperature << endl;
		outGPIO.setValue(HIGH);
                sleep(1);
                outGPIO.setValue(LOW);
                sleep(1);
	}
}
