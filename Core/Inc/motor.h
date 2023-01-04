/*
 * motor.h
 *
 *  Created on: Nov 8, 2022
 *      Author: nicolas
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "main.h"

void StartPWM(void);
void motorPowerOn(void);
void motorPowerOff(void);
void motorSetSpeed(int speed);
void HAL_GPIO_EXTI_CallBack(uint16_t GPIO_Pin);


#endif /* INC_MOTOR_H_ */
