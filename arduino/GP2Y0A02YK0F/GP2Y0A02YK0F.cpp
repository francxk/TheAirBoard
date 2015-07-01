/*******************************************************************************
This is the SHARP GP2Y0A02YK0F analog infrared proximity sensor library.

Check license.txt for more information.
All text above must be included in any redistribution.
*******************************************************************************/

#include <GP2Y0A02YK0F.h>

const byte proxi[2][256] = {
{	// 5V power supply calibration
255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
255, 255, 255, 240, 233, 225, 215, 208, 200, 185, 180, 175, 170, 165, 160, 155,
150, 145, 142, 138, 135, 132, 128, 125, 122, 118, 115, 113, 110, 108, 105, 103,
102, 100, 98, 97, 95, 93, 92, 90, 88, 87, 85, 84, 82, 81, 79, 78,
76, 75, 74, 73, 71, 70, 69, 68, 66, 65, 64, 64, 63, 62, 62, 61,
60, 60, 59, 58, 58, 57, 56, 56, 55, 54, 54, 53, 53, 52, 52, 51,
51, 50, 49, 49, 48, 48, 47, 47, 46, 46, 45, 45, 44, 44, 44, 43,
43, 43, 42, 42, 42, 41, 41, 41, 40, 40, 40, 39, 39, 39, 38, 38,
38, 37, 37, 37, 36, 36, 36, 35, 35, 35, 35, 34, 34, 34, 34, 33,
33, 33, 33, 33, 32, 32, 32, 32, 32, 31, 31, 31, 31, 30, 30, 30,
30, 30, 29, 29, 29, 29, 28, 28, 28, 28, 28, 27, 27, 27, 27, 27,
26, 26, 26, 26, 25, 25, 25, 25, 24, 24, 24, 23, 23, 22, 22, 22,
21, 21, 21, 20, 20, 19, 19, 19, 18, 18, 18, 17, 17, 16, 16, 16,
15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15
},
{	// 3V3 power supply calibration
115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115,
115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115,
115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115,
115, 115, 110, 105, 102, 98, 95, 92, 88, 85, 83, 82, 80, 78, 77, 75,
73, 72, 70, 68, 67, 65, 64, 63, 62, 61, 60, 60, 59, 58, 57, 56,
55, 54, 54, 53, 53, 52, 52, 51, 51, 50, 49, 49, 48, 48, 47, 47,
46, 46, 45, 45, 44, 44, 44, 43, 43, 43, 42, 42, 42, 41, 41, 41,
40, 40, 39, 39, 39, 38, 38, 38, 37, 37, 37, 36, 36, 36, 35, 35,
35, 35, 34, 34, 34, 34, 33, 33, 33, 33, 32, 32, 32, 32, 31, 31,
31, 31, 30, 30, 30, 30, 30, 29, 29, 29, 29, 28, 28, 28, 28, 27,
27, 27, 27, 26, 26, 26, 26, 25, 25, 25, 24, 23, 23, 22, 21, 20,
20, 19, 18, 17, 17, 16, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15
}
};

/*******************************************************************************
 * Constructor : initialize proximity driver
 *******************************************************************************/
GP2Y0A02YK0F::GP2Y0A02YK0F(int pin) {
	pinMode(pin, INPUT);
    _pin = pin;
}

/*******************************************************************************
 * Acquire data
 *******************************************************************************/
byte GP2Y0A02YK0F::Ranging(boolean supply, boolean unit) {
	return unit?proxi[supply][analogRead(_pin)/4]/2.54:proxi[supply][analogRead(_pin)/4];
}