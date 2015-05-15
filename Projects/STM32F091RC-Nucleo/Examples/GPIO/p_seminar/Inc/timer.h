/**
  ******************************************************************************
  * @file    timer.h
  * @author  Karolina Majstrovic
  * @version 
  * @date    09-May-2015
  * @brief   Header for timer.c module
  ******************************************************************************
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#include "stm32f091xc.h"
#include "stm32f0xx_hal.h"
#include "stm32f0xx_nucleo.h"
#include "main.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void TIM_Init(TIM_TypeDef * timx);
void TIM_Start(TIM_HandleTypeDef *htim);
void TIM_Turn_On(TIM_HandleTypeDef *htim);
