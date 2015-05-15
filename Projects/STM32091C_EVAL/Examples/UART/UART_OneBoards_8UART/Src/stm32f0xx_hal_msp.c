/**
  ******************************************************************************
  * @file    UART/UART_OneBoards_8UART/Src/stm32f0xx_hal_msp.c
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    05-Dec-2014
  * @brief   HAL MSP module.    
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************  
  */ 

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F0xx_HAL_Examples
  * @{
  */

/** @defgroup UART_TwoBoards_ComIT
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
enum
{
  __ENABLE,
  __DISABLE,
};

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void IRQ_Managment(int32_t mode, int32_t IrqName);
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */

/**
  * @brief UART MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration  
  *           - NVIC configuration for UART interrupt request enable
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{  
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  switch((uint32_t)huart->Instance)
  {
  case (uint32_t)USART1 :
    {
      /*##-1- Enable peripherals and GPIO Clocks #################################*/
      /* Enable GPIO TX/RX clock */
      __GPIOA_CLK_ENABLE();
      /* Enable USARTx clock */
      __USART1_CLK_ENABLE(); 
      
      /*##-2- Configure peripheral GPIO ##########################################*/  
      /* UART TX GPIO pin configuration  */
      GPIO_InitStruct.Pin       = GPIO_PIN_9 | GPIO_PIN_10;
      GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
      GPIO_InitStruct.Pull      = GPIO_PULLUP;
      GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF1_USART1;
      HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
      
      /*##-3- Configure the NVIC for UART ########################################*/
      /* NVIC for USART */
      HAL_NVIC_SetPriority(USART1_IRQn, 1, 0);
      HAL_NVIC_EnableIRQ(USART1_IRQn);
    }
    break;
  case (uint32_t)USART2 :
    {
      /*##-1- Enable peripherals and GPIO Clocks #################################*/
      /* Enable GPIO TX/RX clock */
      __GPIOD_CLK_ENABLE();
      /* Enable USARTx clock */
      __USART2_CLK_ENABLE(); 
      
      /*##-2- Configure peripheral GPIO ##########################################*/  
      /* UART TX GPIO pin configuration  */
      GPIO_InitStruct.Pin       = GPIO_PIN_6 | GPIO_PIN_5;
      GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
      GPIO_InitStruct.Pull      = GPIO_PULLUP;
      GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF0_USART2;
      
      HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
      
      /*##-3- Configure the NVIC for UART ########################################*/
      /* NVIC for USART */
      HAL_NVIC_SetPriority(USART2_IRQn, 1, 0);
      HAL_NVIC_EnableIRQ(USART2_IRQn);
    }
    break;
  case (uint32_t)USART3 :
    {
      /*##-1- Enable peripherals and GPIO Clocks #################################*/
      /* Enable GPIO TX/RX clock */
      __GPIOD_CLK_ENABLE();
      /* To allow the IT source identification */
      __SYSCFG_CLK_ENABLE();      
      /* Enable USARTx clock */
      __USART3_CLK_ENABLE(); 
      
      /*##-2- Configure peripheral GPIO ##########################################*/  
      /* UART TX GPIO pin configuration  */
      GPIO_InitStruct.Pin       = GPIO_PIN_8 | GPIO_PIN_9;
      GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
      GPIO_InitStruct.Pull      = GPIO_PULLUP;
      GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF0_USART3;
      HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
      
      /*##-3- Configure the NVIC for UART ########################################*/
      /* NVIC for USART */
      HAL_NVIC_SetPriority(USART3_8_IRQn, 0, 0);
      HAL_NVIC_EnableIRQ(USART3_8_IRQn);
    }
    break;
  case (uint32_t)USART4 :
    {
      /*##-1- Enable peripherals and GPIO Clocks #################################*/
      /* Enable GPIO TX/RX clock */
      __GPIOC_CLK_ENABLE();
      /* To allow the IT source identification */
      __SYSCFG_CLK_ENABLE();
      
      /* Enable USARTx clock */
      __USART4_CLK_ENABLE(); 
      
      /*##-2- Configure peripheral GPIO ##########################################*/  
      /* UART TX GPIO pin configuration  */
      GPIO_InitStruct.Pin       = GPIO_PIN_10 | GPIO_PIN_11;
      GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
      GPIO_InitStruct.Pull      = GPIO_PULLUP;
      GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF0_USART4;
      HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

      /*##-3- Configure the NVIC for UART ########################################*/
      /* NVIC for USART */
      HAL_NVIC_SetPriority(USART3_8_IRQn, 0, 0);
      HAL_NVIC_EnableIRQ(USART3_8_IRQn);
    }
    break;
  case (uint32_t)USART5 :
    {
      /*##-1- Enable peripherals and GPIO Clocks #################################*/
      /* Enable GPIO TX/RX clock */
      __GPIOB_CLK_ENABLE();
      /* To allow the IT source identification */
      __SYSCFG_CLK_ENABLE();      
      /* Enable USARTx clock */
      __USART5_CLK_ENABLE(); 
      
      /*##-2- Configure peripheral GPIO ##########################################*/  
      /* UART TX GPIO pin configuration  */
      GPIO_InitStruct.Pin       = GPIO_PIN_3 | GPIO_PIN_4;
      GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
      GPIO_InitStruct.Pull      = GPIO_PULLUP;
      GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF4_USART5;
      HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
      
      /*##-3- Configure the NVIC for UART ########################################*/
      /* NVIC for USART */
      HAL_NVIC_SetPriority(USART3_8_IRQn, 0, 0);
      HAL_NVIC_EnableIRQ(USART3_8_IRQn);
    }
    break;
  case (uint32_t)USART6 :
    {
      /*##-1- Enable peripherals and GPIO Clocks #################################*/
      /* Enable GPIO TX/RX clock */
      __GPIOF_CLK_ENABLE();
      /* To allow the IT source identification */
      __SYSCFG_CLK_ENABLE();      
      /* Enable USARTx clock */
      __USART6_CLK_ENABLE(); 
      
      /*##-2- Configure peripheral GPIO ##########################################*/  
      /* UART TX GPIO pin configuration  */
      GPIO_InitStruct.Pin       = GPIO_PIN_9 | GPIO_PIN_10;
      GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
      GPIO_InitStruct.Pull      = GPIO_PULLUP;
      GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF1_USART6;  
      HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
      
      /*##-3- Configure the NVIC for UART ########################################*/
      /* NVIC for USART */
      HAL_NVIC_SetPriority(USART3_8_IRQn, 0, 0);
      HAL_NVIC_EnableIRQ(USART3_8_IRQn);
    }
    break;
  case (uint32_t)USART7 :
    {
      /*##-1- Enable peripherals and GPIO Clocks #################################*/
      /* Enable GPIO TX/RX clock */
      __GPIOF_CLK_ENABLE();
      /* To allow the IT source identification */
      __SYSCFG_CLK_ENABLE();
      /* Enable USARTx clock */
      __USART7_CLK_ENABLE(); 
      
      /*##-2- Configure peripheral GPIO ##########################################*/  
      /* UART TX GPIO pin configuration  */
      GPIO_InitStruct.Pin       = GPIO_PIN_3 | GPIO_PIN_2;
      GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
      GPIO_InitStruct.Pull      = GPIO_PULLUP;
      GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF1_USART7;
      HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
      
      /*##-3- Configure the NVIC for UART ########################################*/
      /* NVIC for USART */
      HAL_NVIC_SetPriority(USART3_8_IRQn, 0, 0);
      HAL_NVIC_EnableIRQ(USART3_8_IRQn);
    }
    break;
  case (uint32_t)USART8 :
    {
      /*##-1- Enable peripherals and GPIO Clocks #################################*/
      /* Enable GPIO TX/RX clock */
      __GPIOC_CLK_ENABLE();
      /* To allow the IT source identification */
      __SYSCFG_CLK_ENABLE();      
      /* Enable USARTx clock */
      __USART8_CLK_ENABLE(); 
      
      /*##-2- Configure peripheral GPIO ##########################################*/  
      /* UART TX GPIO pin configuration  */
      GPIO_InitStruct.Pin       = GPIO_PIN_8 | GPIO_PIN_9;
      GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
      GPIO_InitStruct.Pull      = GPIO_PULLUP;
      GPIO_InitStruct.Speed     = GPIO_SPEED_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF1_USART8;     
      HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
      
      /*##-3- Configure the NVIC for UART ########################################*/
      /* NVIC for USART */
      HAL_NVIC_SetPriority(USART3_8_IRQn, 1, 0);
      HAL_NVIC_EnableIRQ(USART3_8_IRQn);
    }
    break;
  }
}

/**
* @brief UART MSP De-Initialization 
*        This function frees the hardware resources used in this example:
*          - Disable the Peripheral's clock
*          - Revert GPIO and NVIC configuration to their default state
* @param huart: UART handle pointer
* @retval None
*/
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{
  switch((uint32_t)huart->Instance)
  {
  case (uint32_t)USART1 :
    {
      /*##-1- Reset peripherals ##################################################*/
      __USART1_FORCE_RESET();
      __USART1_RELEASE_RESET();
      __USART1_CLK_DISABLE();
      
      /*##-2- Disable peripherals and GPIO Clocks #################################*/
      /* Configure UART Tx/Rx as alternate function  */
      HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9 | GPIO_PIN_10);
      
      /*##-3- Disable the NVIC for UART ##########################################*/
      IRQ_Managment(__DISABLE, USART1_IRQn);
    }
    break;
  case (uint32_t)USART2 :
    {
      /*##-1- Reset peripherals ##################################################*/
      __USART2_FORCE_RESET();
      __USART2_RELEASE_RESET();
      __USART2_CLK_DISABLE();
      
      /*##-2- Disable peripherals and GPIO Clocks #################################*/
      /* Configure UART Tx/Rx as alternate function  */
      HAL_GPIO_DeInit(GPIOD, GPIO_PIN_5 | GPIO_PIN_6);
      
      /*##-3- Disable the NVIC for UART ##########################################*/
      IRQ_Managment(__DISABLE, USART2_IRQn);
    }
    break;
  case (uint32_t)USART3 :
    {
      /*##-1- Reset peripherals ##################################################*/
      __USART3_FORCE_RESET();
      __USART3_RELEASE_RESET();
      __USART3_CLK_DISABLE();
      
      /*##-2- Disable peripherals and GPIO Clocks #################################*/
      /* Configure UART Tx/Rx as alternate function  */
      HAL_GPIO_DeInit(GPIOD, GPIO_PIN_9 | GPIO_PIN_10);
      
      /*##-3- Disable the NVIC for UART ##########################################*/
      IRQ_Managment(__DISABLE, USART3_8_IRQn);
      
    }
    break;
  case (uint32_t)USART4 :
    {
      /*##-1- Reset peripherals ##################################################*/
      __USART4_FORCE_RESET();
      __USART4_RELEASE_RESET();
      __USART4_CLK_DISABLE();
      
      /*##-2- Disable peripherals and GPIO Clocks #################################*/
      /* Configure UART Tx/Rx as alternate function  */
      HAL_GPIO_DeInit(GPIOC, GPIO_PIN_10 | GPIO_PIN_11);
      
      /*##-3- Disable the NVIC for UART ##########################################*/
      IRQ_Managment(__DISABLE, USART3_8_IRQn);
    }
    break;
  case (uint32_t)USART5 :
    {
      /*##-1- Reset peripherals ##################################################*/
      __USART5_FORCE_RESET();
      __USART5_RELEASE_RESET();
      __USART5_CLK_DISABLE();
      
      /*##-2- Disable peripherals and GPIO Clocks #################################*/
      /* Configure UART Tx/Rx as alternate function  */
      HAL_GPIO_DeInit(GPIOB, GPIO_PIN_3 | GPIO_PIN_4);
      
      /*##-3- Disable the NVIC for UART ##########################################*/
      IRQ_Managment(__DISABLE, USART3_8_IRQn);
    }
    break;
  case (uint32_t)USART6 :
    {
      /*##-1- Reset peripherals ##################################################*/
      __USART6_FORCE_RESET();
      __USART6_RELEASE_RESET();
      __USART6_CLK_DISABLE();
      
      /*##-2- Disable peripherals and GPIO Clocks #################################*/
      /* Configure UART Tx/Rx as alternate function  */
      HAL_GPIO_DeInit(GPIOF, GPIO_PIN_9 | GPIO_PIN_10);
      
      /*##-3- Disable the NVIC for UART ##########################################*/
      IRQ_Managment(__DISABLE, USART3_8_IRQn);
    }
    break;
  case (uint32_t)USART7 :
    {
      /*##-1- Reset peripherals ##################################################*/
      __USART7_FORCE_RESET();
      __USART7_RELEASE_RESET();
      __USART7_CLK_DISABLE();
      
      /*##-2- Disable peripherals and GPIO Clocks #################################*/
      /* Configure UART Tx/Rx as alternate function  */
      HAL_GPIO_DeInit(GPIOF, GPIO_PIN_2 | GPIO_PIN_3);
      
      /*##-3- Disable the NVIC for UART ##########################################*/
      IRQ_Managment(__DISABLE, USART3_8_IRQn);
    }
    break;
  case (uint32_t)USART8 :
    {
      /*##-1- Reset peripherals ##################################################*/
      __USART8_FORCE_RESET();
      __USART8_RELEASE_RESET();
      __USART8_CLK_DISABLE();
      
      /*##-2- Disable peripherals and GPIO Clocks #################################*/
      /* Configure UART Tx/Rx as alternate function  */
      HAL_GPIO_DeInit(GPIOC, GPIO_PIN_8 | GPIO_PIN_9);
      
      /*##-3- Disable the NVIC for UART ##########################################*/
      IRQ_Managment(__DISABLE, USART3_8_IRQn);
    }
    break;
  }
}

/**
  * @brief IRQ_Managment 
  *        This function is used to avoid ENABLE or DISABLE when the IRQ has been already update for another peripheral :
  *          - Disable/Enable the Peripheral's clock
  *
  * @param mode : mode __ENABLE or __DISABLE
  * @param IrqName : IRQ id USART1_IRQn, USART2_IRQn or USART3_8_IRQn
  * @retval None
  */
void IRQ_Managment(int32_t mode, int32_t IrqName)
{
  static int8_t IRQ_state[3] = { 0, 0, 0};
  uint8_t IRQ_index;
  
  switch(IrqName)
  {
  case USART1_IRQn   : IRQ_index=0; break;
  case USART2_IRQn   : IRQ_index=1; break;
  case USART3_8_IRQn : IRQ_index=3; break;
  default: return;
  }

  switch(mode)
  {
  case __ENABLE :
    IRQ_state[IRQ_index]++;
    if(IRQ_state[IRQ_index] == 1)
    {
      HAL_NVIC_DisableIRQ((IRQn_Type)IrqName);
    }
    break;
  case __DISABLE :
    if(IRQ_state[IRQ_index] != 0)
    {
      IRQ_state[IRQ_index]--;
      if(IRQ_state[IRQ_index] == 0)
      {
        HAL_NVIC_DisableIRQ((IRQn_Type)IrqName);
      }
    }
  break;
  }
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
