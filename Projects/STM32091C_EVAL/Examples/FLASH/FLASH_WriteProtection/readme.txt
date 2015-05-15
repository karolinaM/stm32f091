/**
  @page FLASH_WriteProtection FLASH write protection
  
  @verbatim
  ******************** (C) COPYRIGHT 2014 STMicroelectronics *******************
  * @file    FLASH/FLASH_WriteProtection/readme.txt
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    05-Dec-2014
  * @brief   Description of the FLASH write protection example.
  ******************************************************************************
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
  @endverbatim

@par Example Description 

This example provides a description of how to enable and disable the write protection
for the STM32091C FLASH:
  
- Enable Write protection: 
   To enable the Write Protection, uncomment the line "#define WRITE_PROTECTION_ENABLE"
   in main.c file.  
   To protect a set of pages, the user has to call the function HAL_FLASHEx_OBProgram.
   The parameter of this function will define the number of pages to be protected.
   To load the new option byte values, a system Reset is necessary, for this, the
   function HAL_FLASH_OB_Launch() is used.

- Disable Write protection:
   To disable the Write Protection, uncomment the line "#define WRITE_PROTECTION_DISABLE"
   in main.c file.
   To disable the write protection of the STM32091C Flash, an erase of the Option 
   Bytes is necessary. This operation is done by the function HAL_FLASHEx_OBErase.
   To load the new option byte values, a system Reset is necessary, for this, the
   function HAL_FLASH_OB_Launch() is used.

If the desired pages are not write protected, an erase and a write operation are
performed.
  
The following LEDs can be used to monitor the transfer status:
 - LED1 is ON when there are no errors detected after programmation
    => should be the case when WRITE_PROTECTION_DISABLE flag is enabled
 - LED2 is ON when there are errors dectected after programmation
    => should be the case when WRITE_PROTECTION_ENABLE flag is enabled
 - LED3 is ON when there is an issue during erase, OB erase, program or OB program procedure

@par Directory contents 

  - FLASH/FLASH_WriteProtection/Inc/stm32f0xx_hal_conf.h        HAL Configuration file  
  - FLASH/FLASH_WriteProtection/Inc/stm32f0xx_it.h              Header for stm32f0xx_it.c
  - FLASH/FLASH_WriteProtection/Inc/main.h                      Header for main.c module 
  - FLASH/FLASH_WriteProtection/Src/stm32f0xx_it.c              Interrupt handlers
  - FLASH/FLASH_WriteProtection/Src/main.c                      Main program
  - FLASH/FLASH_WriteProtection/Src/system_stm32f0xx.c          STM32F0xx system clock configuration file
  

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Hardware and Software environment

  - This example runs on STM32F091C devices.
    
  - This example has been tested with STM32091C-EVAL board and can be
    easily tailored to any other supported device and development board.

@par How to use it ? 

In order to make the program work, you must do the following:
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
