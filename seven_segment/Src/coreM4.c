/*
 * coreM4.c
 *
 *
 *      Author: Baris Cakir
 */
#include "coreM4.h"

static volatile clock_t tmTickCount;


void nvic_irqno_enable(uint8_t irq_num){
	if(irq_num < 32)
		NVIC_ISERx->NVIC_ISER0 |= (1U<<irq_num );
	else if( irq_num < 64)
		NVIC_ISERx->NVIC_ISER1 |= (1U<<(irq_num%32));
	else if(irq_num <= 81)
		NVIC_ISERx->NVIC_ISER2 |= (1U<<(irq_num%32));

}

void nvic_irqno_disable(uint8_t irq_num){
	if(irq_num < 32)
		NVIC_ICERx->NVIC_ICER0 |= ((1U<<irq_num ));
	else if( irq_num < 64)
		NVIC_ICERx->NVIC_ICER1 |= (1U<<(irq_num%32));
	else if(irq_num <= 81)
		NVIC_ICERx->NVIC_ICER2 |= (1U<<(irq_num%32));
}



void systick_config(uint32_t tick){
	//1-Program reload value
	//2-Clear current value
	//3-Program Control and Status register

	SYSTIC->SYST_RVR= tick -1;
	SYSTIC->SYST_CVR= 0;
	SYSTIC->SYST_CSR |= (1U<<2);
	SYSTIC->SYST_CSR |= (1U<<1);
	SYSTIC->SYST_CSR |= (1U<<0); //COUNTER ENABLE

}


clock_t clock(){
	tmTickCount;
}

