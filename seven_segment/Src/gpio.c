/*
 * gpio.c
 *
 *  Created on: 3 Ara 2022
 *      Author: metab
 */
#include "gpio.h"



PRIVATE void gpio_perip_en(GPIO_RegDef_t * pGpiox){
	if(pGpiox==GPIOA)
		GPIOA_CLOCK_ENABLE();
	else if(pGpiox==GPIOB)
		GPIOB_CLOCK_ENABLE();
	else if(pGpiox==GPIOC)
		GPIOC_CLOCK_ENABLE();
	else if(pGpiox==GPIOD)
		GPIOD_CLOCK_ENABLE();
	else if(pGpiox==GPIOE)
		GPIOE_CLOCK_ENABLE();
	else if(pGpiox==GPIOF)
		GPIOF_CLOCK_ENABLE();
	else if(pGpiox==GPIOG)
		GPIOG_CLOCK_ENABLE();
	else if(pGpiox==GPIOH)
		GPIOH_CLOCK_ENABLE();
	else if(pGpiox==GPIOI)
		GPIOI_CLOCK_ENABLE();
}


PRIVATE uint8_t get_port_code(const GPIO_RegDef_t * pGpioX){
	if(pGpioX==GPIOA)
		return GPIOA_PORT_CODE;
	else if(pGpioX==GPIOB)
		return GPIOB_PORT_CODE;
	else if(pGpioX==GPIOC)
		return GPIOC_PORT_CODE;
	else if(pGpioX==GPIOD)
		return GPIOD_PORT_CODE;
	else if(pGpioX==GPIOE)
		return GPIOE_PORT_CODE;
	else if(pGpioX==GPIOF)
		return GPIOF_PORT_CODE;
	else if(pGpioX==GPIOG)
		return GPIOG_PORT_CODE;
	else if(pGpioX==GPIOH)
		return GPIOH_PORT_CODE;
	else if(pGpioX==GPIOI)
		return GPIOI_PORT_CODE;
}

void gpio_init(GPIO_Handle_t * pGpio_handle){
	uint32_t temp=0;

	//clock aktif et
	gpio_perip_en(pGpio_handle->pGpioX);
	/*
	volatile uint32_t * p_rcc_ahb1_reg=(uint32_t*)(0x40023800+0x30);
	*p_rcc_ahb1_reg |=(1u<<3);
*/

	//pin mode ayarla
	if(pGpio_handle->gPIO_pinConfig.pin_mode<=GPIO_MODE_ANALOG){
		temp = (pGpio_handle->gPIO_pinConfig.pin_mode << (2 * pGpio_handle->gPIO_pinConfig.pin_number));
		pGpio_handle->pGpioX->MODER &= ~(0b11<<(2*pGpio_handle->gPIO_pinConfig.pin_number));
		pGpio_handle->pGpioX->MODER |=temp;
	}else{
		//interrupt mode
		if(pGpio_handle->gPIO_pinConfig.pin_mode==GPIO_MODE_FE_IT) //Only falling
		{
			EXTI->FTSR |= (1U<<pGpio_handle->gPIO_pinConfig.pin_number); //falling set
			EXTI->RTSR &= ~(1U<<pGpio_handle->gPIO_pinConfig.pin_number);//rising reset
		}
		else if(pGpio_handle->gPIO_pinConfig.pin_mode==GPIO_MODE_RE_IT) // only rising
		{
			EXTI->RTSR |= (1U<<pGpio_handle->gPIO_pinConfig.pin_number);//rising set
			EXTI->FTSR &= ~(1U<<pGpio_handle->gPIO_pinConfig.pin_number);//falling reset
		}
		else if(pGpio_handle->gPIO_pinConfig.pin_mode==GPIO_MODE_FRE_IT) // falling + rising
		{
			EXTI->RTSR |= (1U <<pGpio_handle->gPIO_pinConfig.pin_number); //rising set
			EXTI->FTSR |= (1U <<pGpio_handle->gPIO_pinConfig.pin_number); //falling set
		}
		//used port pin selection by SYSCF_EXTICRx
		SYSCFG_CLOCK_ENABLE();
		uint32_t syscfgr_exti_reg_no = pGpio_handle->gPIO_pinConfig.pin_number / 4;
		uint32_t syscfgr_exti_reg_bit_no = pGpio_handle->gPIO_pinConfig.pin_number % 4;
		uint8_t port_code = get_port_code(pGpio_handle->pGpioX);
		SYSCFG->EXTICR[syscfgr_exti_reg_no] |= (port_code<<(syscfgr_exti_reg_bit_no*4));

		//Enable IMR
		EXTI->IMR |= (1u<<pGpio_handle->gPIO_pinConfig.pin_number);
		//NVIC
	}

	//speed ayarla
	temp = (pGpio_handle->gPIO_pinConfig.pin_speed << (2 * pGpio_handle->gPIO_pinConfig.pin_number));
	pGpio_handle->pGpioX->OSPEEDR &= ~(0b11<<(2*pGpio_handle->gPIO_pinConfig.pin_number));
	pGpio_handle->pGpioX->OSPEEDR |=temp;

	//pull up pull down ayarla
	temp = (pGpio_handle->gPIO_pinConfig.pin_pupd << (2 * pGpio_handle->gPIO_pinConfig.pin_number));
	pGpio_handle->pGpioX->PUPDR &= ~(0b11<<(2*pGpio_handle->gPIO_pinConfig.pin_number));
	pGpio_handle->pGpioX->PUPDR |=temp;

	//otype ayarla
	temp = (pGpio_handle->gPIO_pinConfig.pin_otype << (pGpio_handle->gPIO_pinConfig.pin_number));
	pGpio_handle->pGpioX->OTYPER &= ~(0b1<<(pGpio_handle->gPIO_pinConfig.pin_number));
	pGpio_handle->pGpioX->OTYPER |=temp;

	//alternate func mode --ilerde
	if(pGpio_handle->gPIO_pinConfig.pin_mode==GPIO_MODE_ALTERNATE){

		uint8_t afr_low_high = pGpio_handle->gPIO_pinConfig.pin_number / 8;
		uint8_t afr_pin_no = pGpio_handle->gPIO_pinConfig.pin_number % 8;

		pGpio_handle->pGpioX->AFR[afr_low_high] &= ~(0X0F<<(4*afr_pin_no)); //  ??????
		pGpio_handle->pGpioX->AFR[afr_low_high] |= (pGpio_handle->gPIO_pinConfig.pin_alternate_function_mode<<(4*afr_pin_no));
	}

	//bi portun pinine 1 mi 0 mı yazacağız....




}


void  gpio_writeto_output_pin(GPIO_RegDef_t *pGpiox ,uint8_t pin_no, uint8_t val){

	if(val==GPIO_PIN_SET)
		pGpiox->ODR |= (1u<<pin_no);
	else
		pGpiox->ODR &=~ (1u<<pin_no);


}

void gpio_writeto_output_port(GPIO_RegDef_t *pGpiox ,uint16_t val){
	pGpiox->ODR=val; //bitsel olarak değil direk data olarak yazıyoruz.

}


void gpio_toggleto_output_pin(GPIO_RegDef_t *pGpiox ,uint8_t pin_no){
	pGpiox->ODR ^=(1u<<pin_no);

}

uint32_t gpio_read_input_pin(GPIO_RegDef_t *pGpiox, uint32_t pin_no){
	uint32_t res;
	res = pGpiox->IDR &(1u<<pin_no);
	//return res;
	return res!= 0? GPIO_PIN_SET : GPIO_PIN_RESET;
}



void clear_pending_reg(uint8_t pin_no){
	//clear PR
	if(EXTI->PR & (1<<pin_no))
		EXTI->PR |= (1U<<pin_no);
}

void toggle_board_random_leds(){
	uint8_t led_no =(uint8_t)(get_random_number()%4 + 12);
	gpio_toggleto_output_pin(GPIOD, led_no);
}

