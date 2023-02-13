#ifndef _STM32F407XX_H
#define _STM32F407XX_H
#include  <stdint.h>


//bus
#define PERIPHERAL_BASE_ADDR 			0x40000000U
#define APB1PERIPHERAL_BASE_ADDR 		PERIPHERAL_BASE_ADDR
#define APB2PERIPHERAL_BASE_ADDR 		0x40010000U
#define AHB1PERIPHERAL_BASE_ADDR 		0x40020000U
#define AHB2PERIPHERAL_BASE_ADDR 		0x50050000U
#define AHB3PERIPHERAL_BASE_ADDR 		0x60000000

//apb1
#define TIM2_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x0000)
#define TIM3_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x0400)
#define TIM4_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x0800)
#define TIM5_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x0C00)
#define TIM6_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x1000)
#define TIM7_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x1400)
#define TIM12_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x1800)
#define TIM13_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x1C00)
#define TIM14_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x2000)
#define RTC_BKP_BASEADDR 	(APB1PERIPHERAL_BASE_ADDR + 0x2800)//4 - 55:52
#define WWDG_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x2C00)
#define IWDG_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x3000)
#define I2S2ext_BASEADDR 	(APB1PERIPHERAL_BASE_ADDR + 0x2C00)
#define SP2_I2S2_BASEADDR 	(APB1PERIPHERAL_BASE_ADDR + 0x3800)
#define SP3_I2S3_BASEADDR 	(APB1PERIPHERAL_BASE_ADDR + 0x3C00)
#define I2S3ext_BASEADDR 	(APB1PERIPHERAL_BASE_ADDR + 0x4000)
#define USART2_BASEADDR 	(APB1PERIPHERAL_BASE_ADDR + 0x4400)
#define USART3_BASEADDR 	(APB1PERIPHERAL_BASE_ADDR + 0x4800)
#define UART4_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x4C00)
#define UART5_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x5000)
#define I2C1_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x5400)
#define I2C2_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x5800)
#define I2C3_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x5C00)
#define CAN1_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x6400)
#define CAN2_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x6800)
#define PWR_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x7000)
#define DAC_BASEADDR 		(APB1PERIPHERAL_BASE_ADDR + 0x7400)

//apb2

#define TIM1_BASEADDR 		(APB2PERIPHERAL_BASE_ADDR + 0x0000)
#define TIM8_BASEADDR 		(APB2PERIPHERAL_BASE_ADDR + 0x0400)
#define USART1_BASEADDR 	(APB2PERIPHERAL_BASE_ADDR + 0x1000)
#define USART6_BASEADDR 	(APB2PERIPHERAL_BASE_ADDR + 0x1400)
#define ADC1_2_3_BASEADDR 	(APB2PERIPHERAL_BASE_ADDR + 0x2000)
#define SDIO_BASEADDR 		(APB2PERIPHERAL_BASE_ADDR + 0x2C00)
#define SPI1_BASEADDR 		(APB2PERIPHERAL_BASE_ADDR + 0x3000)
#define SYSCFG_BASEADDR 	(APB2PERIPHERAL_BASE_ADDR + 0x3800)
#define EXTI_BASEADDR 		(APB2PERIPHERAL_BASE_ADDR + 0x3C00)
#define TIM9_BASEADDR 		(APB2PERIPHERAL_BASE_ADDR + 0x4000)
#define TIM10_BASEADDR 		(APB2PERIPHERAL_BASE_ADDR + 0x4400)
#define TIM11_BASEADDR 		(APB2PERIPHERAL_BASE_ADDR + 0x4800)

//ahb1

#define GPIOA_BASEADDR 				(AHB1PERIPHERAL_BASE_ADDR + 0x0000)
#define GPIOB_BASEADDR 				(AHB1PERIPHERAL_BASE_ADDR + 0x0400)
#define GPIOC_BASEADDR 				(AHB1PERIPHERAL_BASE_ADDR + 0x0800)
#define GPIOD_BASEADDR 				(AHB1PERIPHERAL_BASE_ADDR + 0x0C00)
#define GPIOE_BASEADDR 				(AHB1PERIPHERAL_BASE_ADDR + 0x1000)
#define GPIOF_BASEADDR 				(AHB1PERIPHERAL_BASE_ADDR + 0x1400)
#define GPIOG_BASEADDR 				(AHB1PERIPHERAL_BASE_ADDR + 0x1800)
#define GPIOH_BASEADDR 				(AHB1PERIPHERAL_BASE_ADDR + 0x1C00)
#define GPIOI_BASEADDR 				(AHB1PERIPHERAL_BASE_ADDR + 0x2000)
#define CRC_BASEADDR 				(AHB1PERIPHERAL_BASE_ADDR + 0x3000)
#define RCC_BASEADDR	 			(AHB1PERIPHERAL_BASE_ADDR + 0x3800)
#define FLASH_INTERFACE_BASEADDR	(AHB1PERIPHERAL_BASE_ADDR + 0x3C00)
#define BKPSRAM_BASEADDR 			(AHB1PERIPHERAL_BASE_ADDR + 0x4000)
#define DMA1_BASEADDR 				(AHB1PERIPHERAL_BASE_ADDR + 0x6000)
#define DMA2_BASEADDR 				(AHB1PERIPHERAL_BASE_ADDR + 0x6400)
#define ETHERNET_MAC_BASEADDR 		(AHB1PERIPHERAL_BASE_ADDR + 0x8000)
#define USB_OTG_HS_BASEADDR 		(AHB1PERIPHERAL_BASE_ADDR + 0x40000)
#define USB_OTG_FS_BASEADDR 		(0x50000000U)


//ahb2

#define DCMI_BASEADDR 				(AHB2PERIPHERAL_BASE_ADDR + 0x0000)
#define RNG_BASEADDR 				(AHB2PERIPHERAL_BASE_ADDR + 0x10800)

//ahb3
//#define _BASEADDR 				(AHB3PERIPHERAL_BASE_ADDR + 0x) //4 - 1:22:00


//IRQ Numbers
#define IRQ_EXTI0				6
#define IRQ_EXTI1				7
#define IRQ_EXTI2				8
#define IRQ_EXTI3				9
#define IRQ_EXTI4				10  //bu doğru mu kontrol et
#define IRQ_EXTI9_5				23
#define IRQ_EXTI15_10			40

#define IRQ_HASH_RNG			80
#define IRQ_TIM6_DAC			54




typedef struct{
//1:36:34. dkakika //referance manual sf 211
	volatile uint32_t	CR;
	volatile uint32_t	PLLCFGR;
	volatile uint32_t	CFGR;
	volatile uint32_t	CIR;
	volatile uint32_t	AHB1STR;
	volatile uint32_t	AHB2STR;
	volatile uint32_t	AHB3STR;
	uint32_t RESERVED0;
	volatile uint32_t	APB1STR;
	volatile uint32_t	APB2STR;
	uint32_t RESERVED1[2];
	volatile uint32_t	AHB1ENR;
	volatile uint32_t	AHB2ENR;
	volatile uint32_t	AHB3ENR;
	uint32_t RESERVED2;
	volatile uint32_t	APB1ENR;
	volatile uint32_t	APB2ENR;
	uint32_t RESERVED3;
	volatile uint32_t	AHB1LPENR;
	volatile uint32_t	AHB2LPENR;
	volatile uint32_t	AHB3LPENR;
	uint32_t RESERVED4;
	volatile uint32_t	APB1LPENR;
	volatile uint32_t	APB2LPENR;
	uint32_t RESERVED5[2];
	volatile uint32_t	BDCR;
	volatile uint32_t	CSR;
	uint32_t RESERVED6[2];
	volatile uint32_t	SSCGR;
	volatile uint32_t	PLLI2SCFGR;
	volatile uint32_t	PLLSAICFGR;
	volatile uint32_t	DCKCFGR;


}RCC_RegDef_t;

typedef struct{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];//AFR[0]-->L AFR[1]-->H
}GPIO_RegDef_t;

typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_RegDef_t;

typedef struct{
	volatile uint32_t MEMRF;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	//0x14 + 0x4 = 0x18 reserve
	//0x18 + 0x4 = 0x1c reserve
	//0x1c + 0x4 = 0x20 cmpcr olacak
	uint32_t RESERVED0[2];
	volatile uint32_t CMPCR;
}SYSCFG_RegDef_t;


typedef struct{
	volatile uint32_t CR;
	volatile uint32_t SR;
	volatile uint32_t DR;
}RNG_RegDef_t;


typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RCR;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CCR3;
	volatile uint32_t CCR4;
	volatile uint32_t BDTR;
	volatile uint32_t DCR;
	volatile uint32_t DMAR;
	volatile uint32_t OR;
}TIM_RegDef_t;








#define 	GPIOA					((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define 	GPIOB					((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define 	GPIOC					((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define 	GPIOD					((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define 	GPIOE					((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define 	GPIOF					((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define 	GPIOG					((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define 	GPIOH					((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define 	GPIOI					((GPIO_RegDef_t*)GPIOI_BASEADDR)


#define 	RCC  					((RCC_RegDef_t *) RCC_BASEADDR)
#define		EXTI					((EXTI_RegDef_t *) EXTI_BASEADDR)
#define 	SYSCFG					((SYSCFG_RegDef_t *) SYSCFG_BASEADDR)
#define 	RNG 					((RNG_RegDef_t *) RNG_BASEADDR)

#define		TIMER1					((TIM_RegDef_t *) TIM1_BASEADDR)
#define		TIMER2					((TIM_RegDef_t *) TIM2_BASEADDR)
#define		TIMER3					((TIM_RegDef_t *) TIM3_BASEADDR)
#define		TIMER4					((TIM_RegDef_t *) TIM4_BASEADDR)
#define		TIMER5					((TIM_RegDef_t *) TIM5_BASEADDR)
#define		TIMER6					((TIM_RegDef_t *) TIM6_BASEADDR)
#define		TIMER7					((TIM_RegDef_t *) TIM7_BASEADDR)
#define		TIMER8					((TIM_RegDef_t *) TIM8_BASEADDR)
#define		TIMER9					((TIM_RegDef_t *) TIM9_BASEADDR)
#define		TIMER10					((TIM_RegDef_t *) TIM10_BASEADDR)
#define		TIMER11					((TIM_RegDef_t *) TIM11_BASEADDR)
//daha fazla varsa tanımla timerları

#define GPIOA_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1<<0))
#define GPIOB_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1<<1))
#define GPIOC_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1<<2))
#define GPIOD_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1<<3))
#define GPIOE_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1<<4))
#define GPIOF_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1<<5))
#define GPIOG_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1<<6))
#define GPIOH_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1<<7))
#define GPIOI_CLOCK_ENABLE()		(RCC->AHB1ENR |=(1<<8))

#define SYSCFG_CLOCK_ENABLE()		(RCC->APB2ENR |=(1<<14))
#define RNG_CLOCK_ENABLE()			(RCC->AHB2ENR |=(1<<6))

//APB2 Bus timer's clock
#define TIMER1_CLOCK_ENABLE()		(RCC->APB2ENR |=(1<<0))
#define TIMER8_CLOCK_ENABLE()		(RCC->APB2ENR |=(1<<1))
#define TIMER9_CLOCK_ENABLE()		(RCC->APB2ENR |=(1<<16))
#define TIMER10_CLOCK_ENABLE()		(RCC->APB2ENR |=(1<<17))
#define TIMER11_CLOCK_ENABLE()		(RCC->APB2ENR |=(1<<18))

//APB1 Bus timer's clock
#define TIMER2_CLOCK_ENABLE()		(RCC->APB1ENR |=(1<<0))
#define TIMER3_CLOCK_ENABLE()		(RCC->APB1ENR |=(1<<1))
#define TIMER4_CLOCK_ENABLE()		(RCC->APB1ENR |=(1<<2))
#define TIMER5_CLOCK_ENABLE()		(RCC->APB1ENR |=(1<<3))
#define TIMER6_CLOCK_ENABLE()		(RCC->APB1ENR |=(1<<4))
#define TIMER7_CLOCK_ENABLE()		(RCC->APB1ENR |=(1<<5))



#endif

