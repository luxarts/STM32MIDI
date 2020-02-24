/*
 * pot.h
 *
 *  Created on: Feb 24, 2020
 *      Author: bacel
 */

#ifndef INC_POT_H_
#define INC_POT_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "adc.h"
#include "utils.h"

#define ADC_POLL_TIMEOUT 10
#define POT_THRESHOLD 1

// Prototypes
void Pot_read(void);
uint8_t Pot_checkChanged(uint8_t potNumber);
uint8_t Pot_getValue(uint8_t potNumber);

#endif /* INC_POT_H_ */
