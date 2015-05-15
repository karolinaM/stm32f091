/**
  ******************************************************************************
  * @file    gpio.c
  * @author  Karolina Majstrovic
  * @version 
  * @date    09-May-2015
  * @brief   Delay function.
  ******************************************************************************
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
#include "main.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  
  * @param  
  * @retval 
  */
void GPIO_Init_Output(GPIO_TypeDef  *GPIOx, uint16_t GPIO_Pin){
  GPIO_InitTypeDef  GPIO_InitStruct;
	
	GPIO_InitStruct.Pin = GPIO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
	
}

/**
  * @brief  Turns selected GPIO On.
  * @param  
  *     @arg LED2
  * @retval None
  */
void GPIO_On(GPIO_TypeDef  *GPIOx, uint16_t GPIO_Pin)
{
  HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET); 
}

/**
  * @brief  Turns selected LED Off.
  * @param  
  *     @arg 
  * @retval None
  */
void GPIO_Off(GPIO_TypeDef  *GPIOx, uint16_t GPIO_Pin)
{
  HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
}
/**
  * @brief  Init selected pin as input.
  * @param  
  *     @arg 
  * @retval None
  */
void GPIO_Init_Input(GPIO_TypeDef  *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
	
  /* Enable and set EXTI line 4_15 Interrupt to the lowest priority */
  HAL_NVIC_SetPriority(BUTTON_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(BUTTON_IRQn);
}
