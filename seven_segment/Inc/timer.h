/*
 * timer.h
 *
 *  Created on: 12 Oca 2023
 *      Author: metab
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "stm32f407xx.h"
#include "gpio.h"


#define	MOTOR_POSITION_0	1500
#define	MOTOR_POSITION_90	2000
#define	MOTOR_POSITION_270	1000


typedef enum TIMNO{
	TIMER_1,
	TIMER_2,
	TIMER_3,
	TIMER_4,
	TIMER_5,
	TIMER_6,
	TIMER_7,
	TIMER_8
}TIMNO;


#define Clear_IT_PendingBit() 	(TIMER6->SR &= ~(1U<<0));

#define TIMER_STOP		0
#define TIMER_START		1

void timer_init(TIMNO e_timer_no, unsigned prescaler, unsigned period, unsigned repeat);
void timer_start(TIMNO e_timer_no, int bstart_stop);
void timer_reset(TIMNO e_timer_no);
void timer_interrupt_config(TIMNO e_timer_no);

void TIM6_DAC_IRQHandler();

int get_timer_cnt();
int output_compare_init(TIMNO e_timer_no, unsigned prescaler, unsigned period, unsigned output_cmp_val);

int pwm_init(TIMNO e_timer_no, unsigned prescaler, unsigned period, unsigned duty_val);

#endif /* TIMER_H_ */
