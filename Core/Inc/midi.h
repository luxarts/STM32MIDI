/*
 * midi.h
 *
 *  Created on: Feb 21, 2020
 *      Author: lbacelo
 */

#ifndef INC_MIDI_H_
#define INC_MIDI_H_

#include "stdint.h"
#include "usbd_cdc_if.h"

#define STATUS_NOTE_OFF	0x80
#define STATUS_NOTE_ON	0x90
#define STATUS_CC		0xB0

typedef struct{
	uint8_t type;
	uint8_t channel;
	uint8_t data1;
	uint8_t data2;
} MIDI_msg_TypeDef;

void MIDI_send(MIDI_msg_TypeDef *msg);
void MIDI_note(uint8_t channel, uint8_t note, uint8_t velocity, uint8_t status);

#endif /* INC_MIDI_H_ */
