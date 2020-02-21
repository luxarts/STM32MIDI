/*
 * midi.c
 *
 *  Created on: Feb 21, 2020
 *      Author: lbacelo
 */
#include "midi.h"

void MIDI_send(MIDI_msg_TypeDef *msg){
	uint8_t buf[3];

	// Prepare buffer
	buf[0]= msg->status | 0x80; // Set bit 7
	buf[1]= msg->data1 & 0x7F;  // Clean bit 7
	buf[2]= msg->data2 & 0x7F;  // Clean bit 7

	// Send to USB
	CDC_Transmit_FS(buf, 3);
}


