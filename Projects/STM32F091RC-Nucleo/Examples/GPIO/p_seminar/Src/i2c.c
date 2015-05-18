/**
  ******************************************************************************
  * @file    i2c.c
  * @author  Karolina Majstrovic
  * @version 
  * @date    09-May-2015
  * @brief   Functions for fast init of I2C communication.
  ******************************************************************************
  ******************************************************************************
  */
	
#include "i2c.h"
#include "main.h"

/* Private define ------------------------------------------------------------*/
#define MASTER_BOARD
#define I2C_ADDRESS        0x30F

/* I2C TIMING Register define when I2C clock source is SYSCLK */
/* I2C TIMING is calculated in case of the I2C Clock source is the SYSCLK = 48 MHz */
/* This example use TIMING to 0x00A51314 to reach 1 MHz speed (Rise time = 100 ns, Fall time = 100 ns) */
#define I2C_TIMING      0x00A51314

/* I2C handler declaration */
I2C_HandleTypeDef I2cHandle;

uint8_t aTxBuffer[] = "I2C communication";

void I2C_Init(){
	I2cHandle.Instance             = I2Cx;
  I2cHandle.Init.Timing          = I2C_TIMING;
  I2cHandle.Init.OwnAddress1     = I2C_ADDRESS;
  I2cHandle.Init.AddressingMode  = I2C_ADDRESSINGMODE_10BIT;
  I2cHandle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLED;
  I2cHandle.Init.OwnAddress2     = 0xFF;
  I2cHandle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLED;
  I2cHandle.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLED;  
	HAL_I2C_Init(&I2cHandle);
	
	/* Enable the Analog I2C Filter */
  HAL_I2CEx_AnalogFilter_Config(&I2cHandle,I2C_ANALOGFILTER_ENABLED);
}

void I2C_Send(){
/*##-2- Start the transmission process #####################################*/  
  /* While the I2C in reception process, user can transmit data through 
     "aTxBuffer" buffer */
  while(HAL_I2C_Master_Transmit_IT(&I2cHandle, (uint16_t)I2C_ADDRESS, (uint8_t*)aTxBuffer, TXBUFFERSIZE)!= 0){
  }
}
