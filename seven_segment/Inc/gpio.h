/*
 * gpio.h
 *
 *  Created on: 2 Ara 2022
 *      Author: metab
 */

#ifndef GPIO_H_
#define GPIO_H_
#include <stdint.h>
#include "stm32f407xx.h"
#include "coreM4.h"

#define PUBLIC
#define PRIVATE		static


typedef struct{
	uint8_t 	pin_number;
	uint8_t 	pin_mode;
	uint8_t 	pin_speed;
	uint8_t 	pin_otype;
	uint8_t 	pin_pupd;
	uint8_t		pin_alternate_function_mode;

}GPIO_PinConfig_t;


typedef struct{
	GPIO_RegDef_t * pGpioX;
	GPIO_PinConfig_t gPIO_pinConfig;
}GPIO_Handle_t; //bu bir portu ifade ediyor


//GPİO MODES

enum{
	GPIO_MODE_IN,
	GPIO_MODE_OUT,
	GPIO_MODE_ALTERNATE,
	GPIO_MODE_ANALOG,
	GPIO_MODE_FE_IT,
	GPIO_MODE_RE_IT,
	GPIO_MODE_FRE_IT
	};

enum{
	GPIO_AF0,
	GPIO_AF1,
	GPIO_AF2,
	GPIO_AF3,
	GPIO_AF4,
	GPIO_AF5,
	GPIO_AF6,
	GPIO_AF7,
	GPIO_AF8,
	GPIO_AF9,
	GPIO_AF10,
	GPIO_AF11,
	GPIO_AF12,
	GPIO_AF13,
	GPIO_AF14,
	GPIO_AF15,
};

enum{
	GPIO_PIN_NO_0,
	GPIO_PIN_NO_1,
	GPIO_PIN_NO_2,
	GPIO_PIN_NO_3,
	GPIO_PIN_NO_4,
	GPIO_PIN_NO_5,
	GPIO_PIN_NO_6,
	GPIO_PIN_NO_7,
	GPIO_PIN_NO_8,
	GPIO_PIN_NO_9,
	GPIO_PIN_NO_10,
	GPIO_PIN_NO_11,
	GPIO_PIN_NO_12,
	GPIO_PIN_NO_13,
	GPIO_PIN_NO_14,
	GPIO_PIN_NO_15
};

enum{
	GPIO_PIN_GREEN=12,
	GPIO_PIN_ORANGE,
	GPIO_PIN_RED,
	GPIO_PIN_BLUE
};

enum{
	GPIOA_PORT_CODE,
	GPIOB_PORT_CODE,
	GPIOC_PORT_CODE,
	GPIOD_PORT_CODE,
	GPIOE_PORT_CODE,
	GPIOF_PORT_CODE,
	GPIOG_PORT_CODE,
	GPIOH_PORT_CODE,
	GPIOI_PORT_CODE,
};

enum{
	GPIO_SPEED_LOW,
	GPIO_SPEED_MEDIUM,
	GPIO_SPEED_HIGH,
	GPIO_SPEED_VERY_HIGH
};

enum{
	GPIO_OTYPE_PP,
	GPIO_OTYPE_OD
};

enum{
	GPIO_NO_PUPD,
	GPIO_PIN_PU,
	GPIO_PIN_PD
};

enum{
	GPIO_PIN_RESET,
	GPIO_PIN_SET
};

#define GPIO_PORT_PIN_BLUE			(1U<<15)
#define GPIO_PORT_PIN_RED			(1U<<14)
#define GPIO_PORT_PIN_ORANGE		(1U<<13)
#define GPIO_PORT_PIN_GREEN			(1U<<12)
#define GPIO_PORT_PIN_ALL_COLOR		GPIO_PORT_PIN_BLUE|GPIO_PORT_PIN_RED|GPIO_PORT_PIN_ORANGE|GPIO_PORT_PIN_GREEN

void gpio_init(GPIO_Handle_t * pGpio_handle);

void gpio_writeto_output_pin(GPIO_RegDef_t *pGpiox ,uint8_t pin_no, uint8_t val);
void gpio_writeto_output_port(GPIO_RegDef_t *pGpiox ,uint16_t val);
void gpio_toggleto_output_pin(GPIO_RegDef_t *pGpiox ,uint8_t pin_no);
uint32_t gpio_read_input_pin(GPIO_RegDef_t *pGpiox, uint32_t pin_no);



void clear_pending_reg(uint8_t pin_no);

//void EXTI0_IRQHandler(void);

void toggle_board_random_leds();
#endif /* GPIO_H_ */
