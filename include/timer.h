/* TIMER.H - Header file for TIMER.C                               */
/* By Jim Dosé.  This program is released to the public domain and */
/* may be used in your own programs.  Leave me a note if you find  */
/* it helpful!                                                     */
/* On CompuServe: Jim Dose' 76346,2061                             */
/* On AOL:        JimDose                                          */

#pragma once

#include <stdint.h>

void Set8253Rate(int speed);
void SetClockRate(int TicksPerSecond);
void InitTimer(int TicksPerSecond);
void RestoreTimer(void);
uint32_t GetCounter(void);
void SetCounter(uint32_t count);
