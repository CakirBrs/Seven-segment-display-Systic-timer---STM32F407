/*
 * sevenSegment.c
 *
 *
 *      Author: Baris Cakir
 */

#include "sevenSegment.h"
uint8_t numbers_of_7segment[10]={
			0x3f,
			0x06,
			0x5b,
			0x4f,
			0x66,
			0x6d,
			0x7d,
			0x07,
			0x7f,
			0x6f
	};

void update_of_7segment(uint8_t number){
	gpio_writeto_output_pin(GPIOD, GPIO_PIN_NO_0, ((numbers_of_7segment[number]>>0)&0x01));
	gpio_writeto_output_pin(GPIOD, GPIO_PIN_NO_1, ((numbers_of_7segment[number]>>1)&0x01));
	gpio_writeto_output_pin(GPIOD, GPIO_PIN_NO_2, ((numbers_of_7segment[number]>>2)&0x01));
	gpio_writeto_output_pin(GPIOD, GPIO_PIN_NO_3, ((numbers_of_7segment[number]>>3)&0x01));
	gpio_writeto_output_pin(GPIOD, GPIO_PIN_NO_4, ((numbers_of_7segment[number]>>4)&0x01));
	gpio_writeto_output_pin(GPIOD, GPIO_PIN_NO_5, ((numbers_of_7segment[number]>>5)&0x01));
	gpio_writeto_output_pin(GPIOD, GPIO_PIN_NO_6, ((numbers_of_7segment[number]>>6)&0x01));
}
