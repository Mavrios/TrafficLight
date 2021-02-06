/*
 * main.c
 *
 *  Created on: Jan 29, 2021
 *      Author: Kishk
 *
 */

#include "../Services/STD_TYPES.h"
#include "../Services/BIT_MATHS.h"

#include "../MCAL/01-DIO/DIO_interface.h"
#include "../HAL/01-LED/LED_interface.h"
#include "../HAL/02-SW/SW_interface.h"

#include <util/delay.h>
#include "../HAL/03-SSD/SSD_interface.h"

#define SSD_REST		10
#define RED_LIGHT		60
#define	YELLOW_LIGHT	10
#define GREEN_LIGHT		60

#define TIME			50
#define FIRST_DIGIT(Number)	 	Number % 10
#define SECOND_DIGIT(Number) 	Number / 10

int main(void) {
	u8 Counter = 0;
	u8 u8iterator = 0;
	u32 u8Timer = 0;
	SSD_Type Segment = { DIO_PORTA, SSD_COMMEN_ANODE };
	DIO_enumSetPortDirection(DIO_PORTB, DIO_DIRECTION_OUTPUT);
	SSD_voidInit(Segment);
	while (1) {
		DIO_enumSetPinValue(DIO_PORTB_PIN7, DIO_HIGH);
		DIO_enumSetPinValue(DIO_PORTB_PIN5, DIO_LOW);
		DIO_enumSetPinValue(DIO_PORTB_PIN6, DIO_LOW);
		for (u8iterator = 0; u8iterator < RED_LIGHT; u8iterator++) {
			Counter = RED_LIGHT - u8iterator;
			for (u8Timer = 0; u8Timer < TIME; u8Timer++) {
				DIO_enumSetPinValue(DIO_PORTB_PIN0, DIO_HIGH);
				DIO_enumSetPinValue(DIO_PORTB_PIN1, DIO_LOW);
				SSD_voidSelectNumber(Segment, FIRST_DIGIT(Counter));
				_delay_ms(SSD_REST);
				DIO_enumSetPinValue(DIO_PORTB_PIN0, DIO_LOW);
				DIO_enumSetPinValue(DIO_PORTB_PIN1, DIO_HIGH);
				SSD_voidSelectNumber(Segment, SECOND_DIGIT(Counter));
				_delay_ms(SSD_REST);
			}
		}
		DIO_enumSetPinValue(DIO_PORTB_PIN5, DIO_LOW);
		DIO_enumSetPinValue(DIO_PORTB_PIN7, DIO_LOW);
		DIO_enumSetPinValue(DIO_PORTB_PIN6, DIO_HIGH);

		for (u8iterator = 0; u8iterator < YELLOW_LIGHT; u8iterator++) {
			Counter = YELLOW_LIGHT - u8iterator;
			for (u8Timer = 0; u8Timer < TIME; u8Timer++) {
				DIO_enumSetPinValue(DIO_PORTB_PIN0, DIO_HIGH);
				DIO_enumSetPinValue(DIO_PORTB_PIN1, DIO_LOW);
				SSD_voidSelectNumber(Segment, FIRST_DIGIT(Counter));
				_delay_ms(SSD_REST);
				DIO_enumSetPinValue(DIO_PORTB_PIN0, DIO_LOW);
				DIO_enumSetPinValue(DIO_PORTB_PIN1, DIO_HIGH);
				SSD_voidSelectNumber(Segment, SECOND_DIGIT(Counter));
				_delay_ms(SSD_REST);
			}
		}

		DIO_enumSetPinValue(DIO_PORTB_PIN6, DIO_LOW);
		DIO_enumSetPinValue(DIO_PORTB_PIN7, DIO_LOW);
		DIO_enumSetPinValue(DIO_PORTB_PIN5, DIO_HIGH);

		for (u8iterator = 0; u8iterator < GREEN_LIGHT; u8iterator++) {
			Counter = GREEN_LIGHT - u8iterator;
			for (u8Timer = 0; u8Timer < TIME; u8Timer++) {
				DIO_enumSetPinValue(DIO_PORTB_PIN0, DIO_HIGH);
				DIO_enumSetPinValue(DIO_PORTB_PIN1, DIO_LOW);
				SSD_voidSelectNumber(Segment, FIRST_DIGIT(Counter));
				_delay_ms(SSD_REST);
				DIO_enumSetPinValue(DIO_PORTB_PIN0, DIO_LOW);
				DIO_enumSetPinValue(DIO_PORTB_PIN1, DIO_HIGH);
				SSD_voidSelectNumber(Segment, SECOND_DIGIT(Counter));
				_delay_ms(SSD_REST);
			}
		}
	}

}
