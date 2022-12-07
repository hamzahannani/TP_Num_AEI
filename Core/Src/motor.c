/**
  ******************************************************************************
  * @file    shell.c
  * @brief   This file provides code for motor control
  ******************************************************************************
  *  Created on: Nov 7, 2022
  *      Author: nicolas
  *
  ******************************************************************************
  */

#include "motor.h"
extern TIM_HandleTypeDef htim1;

/**
  * @brief  Switch on the motor driver
  * @retval None
  */

void StartPWM(void)
{
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_2);
}

void motorPowerOn(void){
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin); // just for test, you can delete it
}

/**
  * @brief  Switch off the motor driver
  * @retval None
  */
void motorPowerOff(void){
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin); // just for test, you can delete it
}

/**
  * @brief  Set the motor speed
  * @param  speed : target speed of the motor
  * @retval None
  */
void motorSetSpeed(int speed){
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	// just for test, you can delete it
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,speed);
	TIM1->CCR1 = speed;
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,1023-speed);

}
/*void init_motor(void){
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
	motorSetSpeed(int speed)
}*/

void HAL_GPIO_EXTI_CallBack(uint16_t GPIO_Pin){
	HAL_GPIO_WritePin(ISO_RESET_GPIO_Port, ISO_RESET_Pin, SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(ISO_RESET_GPIO_Port, ISO_RESET_Pin, RESET);
}
