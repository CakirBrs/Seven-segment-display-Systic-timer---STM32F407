/*
 * coreM4.h
 *
 *  Created on: 7 Oca 2023
 *      Author: metab
 */

#ifndef COREM4_H_
#define COREM4_H_
#include <stdint.h>
//#include "stm32f407xx.h"


//ARM Cortex M+ Processor Core Register

#define NVIC_ISER_BASEADDR 						0xE000E100
#define NVIC_ICER_BASEADDR 						0xE000E180
#define SYSTIC_BASEADDR							0xE000E010

typedef struct{
	volatile uint32_t NVIC_ISER0;
	volatile uint32_t NVIC_ISER1;
	volatile uint32_t NVIC_ISER2;
	volatile uint32_t NVIC_ISER3;
	volatile uint32_t NVIC_ISER4;
	volatile uint32_t NVIC_ISER5;
	volatile uint32_t NVIC_ISER6;
	volatile uint32_t NVIC_ISER7;
}NVIC_ISER_RegDef_t;

typedef struct{
	volatile uint32_t NVIC_ICER0;
	volatile uint32_t NVIC_ICER1;
	volatile uint32_t NVIC_ICER2;
	volatile uint32_t NVIC_ICER3;
	volatile uint32_t NVIC_ICER4;
	volatile uint32_t NVIC_ICER5;
	volatile uint32_t NVIC_ICER6;
	volatile uint32_t NVIC_ICER7;
}NVIC_ICER_RegDef_t;

typedef struct{
	volatile uint32_t SYST_CSR;
	volatile uint32_t SYST_RVR;
	volatile uint32_t SYST_CVR;
	volatile uint32_t SYST_CALIB;
}Systick_RegDef_t;



#define NVIC_ISERx							((NVIC_ISER_RegDef_t*)NVIC_ISER_BASEADDR)
#define NVIC_ICERx							((NVIC_ICER_RegDef_t*)NVIC_ICER_BASEADDR)
#define SYSTIC								((Systick_RegDef_t*) SYSTIC_BASEADDR)

//#define CPU_CLOCK		(1u<<2)
#define SYSTEM_FREQ 		16000000

void nvic_irqno_enable(uint8_t irq_num);
void nvic_irqno_disable(uint8_t irq_num);

void systick_config(uint32_t tick);
//void SysTick_Handler();


typedef uint32_t clock_t;
clock_t clock();

#endif /* COREM4_H_ */
