/*
 * pot.c
 *
 *  Created on: Feb 24, 2020
 *      Author: bacel
 */
#include "pot.h"

uint8_t Pot_values[4] = {0};
uint8_t Pot_prevValues[4] = {0};

void Pot_readAll(void){
	// Read ADC
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, ADC_POLL_TIMEOUT);
	uint32_t adcValue = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);

	Pot_values[0] = (uint8_t)map(adcValue, 0, 4095, 0, 127);
}

uint8_t Pot_checkChanged(uint8_t potNumber){
	Pot_readAll();

	switch(potNumber){
		case 0:
			if(Pot_values[potNumber] > Pot_prevValues[potNumber]+POT_THRESHOLD ||
			   Pot_values[potNumber] < Pot_prevValues[potNumber]-POT_THRESHOLD){
				Pot_prevValues[potNumber] = Pot_values[potNumber];
				return 1;
			}
		break;
	}

	return 0;
}

uint8_t Pot_getValue(uint8_t potNumber){
	return Pot_values[potNumber];
}
