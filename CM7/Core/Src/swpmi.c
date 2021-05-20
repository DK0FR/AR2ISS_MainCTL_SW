/**
  ******************************************************************************
  * @file    swpmi.c
  * @brief   This file provides code for the configuration
  *          of the SWPMI instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "swpmi.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

SWPMI_HandleTypeDef hswpmi1;

/* SWPMI1 init function */
void MX_SWPMI1_Init(void)
{

  /* USER CODE BEGIN SWPMI1_Init 0 */

  /* USER CODE END SWPMI1_Init 0 */

  /* USER CODE BEGIN SWPMI1_Init 1 */

  /* USER CODE END SWPMI1_Init 1 */
  hswpmi1.Instance = SWPMI1;
  hswpmi1.Init.VoltageClass = SWPMI_VOLTAGE_CLASS_B;
  hswpmi1.Init.BitRate = 15;
  hswpmi1.Init.TxBufferingMode = SWPMI_TX_NO_SOFTWAREBUFFER;
  hswpmi1.Init.RxBufferingMode = SWPMI_RX_NO_SOFTWAREBUFFER;
  if (HAL_SWPMI_Init(&hswpmi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SWPMI1_Init 2 */

  /* USER CODE END SWPMI1_Init 2 */

}

void HAL_SWPMI_MspInit(SWPMI_HandleTypeDef* swpmiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(swpmiHandle->Instance==SWPMI1)
  {
  /* USER CODE BEGIN SWPMI1_MspInit 0 */

  /* USER CODE END SWPMI1_MspInit 0 */
  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SWPMI1;
    PeriphClkInitStruct.Swpmi1ClockSelection = RCC_SWPMI1CLKSOURCE_D2PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* SWPMI1 clock enable */
    __HAL_RCC_SWPMI1_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    /**SWPMI1 GPIO Configuration
    PC6     ------> SWPMI1_IO
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* USER CODE BEGIN SWPMI1_MspInit 1 */

  /* USER CODE END SWPMI1_MspInit 1 */
  }
}

void HAL_SWPMI_MspDeInit(SWPMI_HandleTypeDef* swpmiHandle)
{

  if(swpmiHandle->Instance==SWPMI1)
  {
  /* USER CODE BEGIN SWPMI1_MspDeInit 0 */

  /* USER CODE END SWPMI1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SWPMI1_CLK_DISABLE();

    /**SWPMI1 GPIO Configuration
    PC6     ------> SWPMI1_IO
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_6);

  /* USER CODE BEGIN SWPMI1_MspDeInit 1 */

  /* USER CODE END SWPMI1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
