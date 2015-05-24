/**
  ******************************************************************************
  * @file    AM2303.c
  * @author  Karolina Majstrovic
  * @version 
  * @date    20-May-2015
  * @brief   AM2303 (temperature and humidity) sensor library.
  ******************************************************************************
  ******************************************************************************
  */
	
/* Includes ------------------------------------------------------------------*/
#include "AM2303.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
extern TIM_HandleTypeDef TimHandle;
volatile int TIM_Status = 0;
/* Private functions ---------------------------------------------------------*/

void AM2303_Init(GPIO_TypeDef  *GPIOx, uint16_t GPIO_Pin){
	GPIO_Init_Output(GPIOx, GPIO_Pin);
	GPIO_On(GPIOx, GPIO_Pin);
}

/* Counter should be initialized.
 * 
*/
void AM2303_Measure(GPIO_TypeDef  *GPIOx, uint16_t GPIO_Pin){	
	// set counter for 18ms
	TIM_Set_Value(&TimHandle, 18, MS);
	GPIO_Off(GPIOx, GPIO_Pin);
	TIM_Start(&TimHandle);
	while(TIM_Status == 0);		
	GPIO_On(GPIOx, GPIO_Pin);
	TIM_Status = 0;
	
	// init pin as input
	
	// receive states
	
}
	