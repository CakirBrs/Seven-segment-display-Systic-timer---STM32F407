/*
 * timer.c
 *
 *
 *      Author: Baris Cakir
 */
#include "timer.h"

TIM_RegDef_t * timTab[]={TIMER1,TIMER2,TIMER3,TIMER4,TIMER5,TIMER6,TIMER7,TIMER8};

static timer_clock_enable(TIM_RegDef_t * pTimerX){
	if(pTimerX==TIMER1)
		TIMER1_CLOCK_ENABLE();
		else if(pTimerX==TIMER8)
			TIMER8_CLOCK_ENABLE();
		else if(pTimerX==TIMER9)
			TIMER9_CLOCK_ENABLE();
		else if(pTimerX==TIMER10)
			TIMER10_CLOCK_ENABLE();
		else if(pTimerX==TIMER11)
			TIMER11_CLOCK_ENABLE();
		else if(pTimerX==TIMER2)
			TIMER2_CLOCK_ENABLE();
		else if(pTimerX==TIMER3)
			TIMER3_CLOCK_ENABLE();
		else if(pTimerX==TIMER4)
			TIMER4_CLOCK_ENABLE();
		else if(pTimerX==TIMER5)
			TIMER5_CLOCK_ENABLE();
		else if(pTimerX==TIMER6)
			TIMER6_CLOCK_ENABLE();
		else if(pTimerX==TIMER7)
			TIMER7_CLOCK_ENABLE();
	}


void timer_init(TIMNO e_timer_no, unsigned prescaler, unsigned period, unsigned repeat){

	//clock enable
	timer_clock_enable(timTab[e_timer_no]);

	//APB2 ve APB1  (timer 1,8,9,10,11)

	TIM_RegDef_t *p= timTab[e_timer_no];
	p->ARR=period-1;
	p->PSC=prescaler-1;

	timer_reset(e_timer_no);
	p->CR1 |= (1U<<0); //timer enable


}

void timer_reset(TIMNO e_timer_no){
	TIM_RegDef_t *p= timTab[e_timer_no];
	p->CNT=0;
}
void timer_start(TIMNO e_timer_no, int bstart_stop){
	TIM_RegDef_t *p= timTab[e_timer_no];
	if(bstart_stop==TIMER_START)
		p->CR1 |=(1U<<0);
	else if(bstart_stop==TIMER_STOP)
		p->CR1 &= ~(1U<<0);
}

void timer_interrupt_config(TIMNO e_timer_no){
	TIM_RegDef_t *pTimer= timTab[e_timer_no];
	pTimer->DIER |= (1U<<0);
	nvic_irqno_enable(IRQ_TIM6_DAC);
}



void TIM6_DAC_IRQHandler(){
	static int a =0;
	++a;
	gpio_toggleto_output_pin(GPIOD, GPIO_PIN_NO_14);

	Clear_IT_PendingBit();

}

int output_compare_init(TIMNO e_timer_no, unsigned prescaler, unsigned period, unsigned output_cmp_val){
	if(e_timer_no==TIMER_6 || e_timer_no==TIMER_7){
		return -1;
	}
	//clock enable
	timer_clock_enable(timTab[e_timer_no]);
	//APB2 ve APB1  (timer 1,8,9,10,11)
	TIM_RegDef_t *p= timTab[e_timer_no];
	p->ARR=period-1;
	p->PSC=prescaler-1;
	timer_reset(e_timer_no);


	//Cpp value
	p->CCR1 = output_cmp_val;


	//capture-compare 1 selection  output mode
	p->CCMR1 &= ~(1U<<0);
	p->CCMR1 &= ~(1U<<1);

	//Ocx selection
	p->CCMR1 &= ~(1U<<6);
	p->CCMR1 |= (1U<<5);
	p->CCMR1 |= (1U<<4);


	//polarity selection
	p->CCER &= ~(1U<<1);





	p->CCER |= (1U<<0);//Enable compare

	p->CR1 |= (1U<<0); //timer enable
	return 0;

}


int pwm_init(TIMNO e_timer_no, unsigned prescaler, unsigned period, unsigned duty_val){
	if(e_timer_no==TIMER_6 || e_timer_no==TIMER_7){
			return -1;
		}
		//clock enable
		timer_clock_enable(timTab[e_timer_no]);
		//APB2 ve APB1  (timer 1,8,9,10,11)
		TIM_RegDef_t *p= timTab[e_timer_no];
		p->ARR=period-1;
		p->PSC=prescaler-1;
		timer_reset(e_timer_no);


		//Cpp value
		p->CCR1 = duty_val;


		//capture-compare 1 selection  output mode
		p->CCMR1 &= ~(1U<<0);
		p->CCMR1 &= ~(1U<<1);

		//Ocx selection
		p->CCMR1 |= (1U<<6);
		p->CCMR1 |= (1U<<5);
		p->CCMR1 &= ~(1U<<4);


		//polarity selection
		p->CCER &= ~(1U<<1);

		p->CCER |= (1U<<0);//Enable compare

		p->CR1 |= (1U<<0); //timer enable
		return 0;

}






