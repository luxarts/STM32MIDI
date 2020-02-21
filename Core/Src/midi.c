/*
 * midi.c
 *
 *  Created on: Feb 21, 2020
 *      Author: lbacelo
 */
#include "midi.h"

void MIDI_send(MIDI_msg_TypeDef *msg){
	uint8_t buf[3];

	// Check if status type is valid
	if(msg->type & 0x80){
		// Prepare buffer
		buf[0]= (msg->type & 0xF0) | (msg->channel & 0x0F);
		buf[1]= msg->data1 & 0x7F;  // Clean bit 7
		buf[2]= msg->data2 & 0x7F;  // Clean bit 7

		// Send to USB
		CDC_Transmit_FS(buf, 3);
	}
}
void MIDI_note(uint8_t channel, uint8_t note, uint8_t velocity, uint8_t status){
	static MIDI_msg_TypeDef msg = {0};

	if(status){
		msg.type = STATUS_NOTE_ON;
		msg.data2 = velocity;
	} else {
		msg.type = STATUS_NOTE_OFF;
		msg.data2 = 0;
	}

	msg.channel = channel;
	msg.data1 = note;

	MIDI_send(&msg);
}
