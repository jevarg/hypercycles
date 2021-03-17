#pragma once

// Globals

extern int Music_Address;
extern int DMA_Channel;
extern int io_addr;
extern int intr_num;
extern int digital_speed;
extern int CTV_voice_status;

void Write_DSP(int port, int data5);