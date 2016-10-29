/*
 * GPIO.h
 *
 *  Created on: May 8, 2016
 *      Author: vagrant
 */

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_

#include "common.h"

void GPIO_DigitalWrite(GPIO_TypeDef *port, uint16_t pin, uint16_t value);

void GPIO_AnalogWrite(GPIO_TypeDef *port, uint16_t pin, uint16_t value);


#endif /* INCLUDE_GPIO_H_ */
