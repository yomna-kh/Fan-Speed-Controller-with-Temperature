/*
 * Project.c
 *
 *  Created on: 6 Oct 2022
 *      Author: Yomna Khalid
 */
#include <avr/io.h>
#include <util/delay.h> /* For the delay functions */
#include "common_macros.h" /* For GET_BIT Macro */
#include "PWM.h"
#include "gpio.h"
#include "motor.h"
#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"

int main(void)
{
    uint8 temp;

	ADC_ConfigType configuration = {INTERNAL, F_CPU8}; /* Create configuration structure for ADC driver */

	/*******************************************************************************
	 *                              Initialization                                  *
	 *******************************************************************************/
    ADC_init(&configuration);
	LCD_init();
	DcMotor_Init();

	/* Display this string "FAN is " only once on LCD at the first row */
	LCD_moveCursor(0,5);
	LCD_displayString("FAN is ");

	/* Display this string only once on LCD at the second row */
	LCD_moveCursor(1,5);
	LCD_displayString("Temp =   C");
	while(1)
	{
		temp = LM35_getTemperature();
		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,11);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);

			LCD_displayCharacter(' ');
		}


		LCD_moveCursor(0,12);
		if (temp < 30)
		{
            LCD_displayString("OFF");
			DcMotor_Rotate(STOP,0);      /*turn motor off and no speed*/
		}
		else if (temp >= 30 && temp < 60)
		{
			LCD_displayString("ON");
			DcMotor_Rotate(CW,25);      /*turn motor on with 25% of it's speed*/
		}
		else if (temp >=60 && temp < 90)
		{
			LCD_displayString("ON");
			DcMotor_Rotate(CW,50);      /*turn motor on with 50% of it's speed*/
		}
		else if (temp >=90 && temp < 120)
		{
			LCD_displayString("ON");
			DcMotor_Rotate(CW,75);      /*turn motor on with 75% of it's speed*/
		}
		else if (temp >=120)
		{
			LCD_displayString("ON");
			DcMotor_Rotate(CW,100);     /*turn motor on with 100% of it's speed*/
		}
	}
}
