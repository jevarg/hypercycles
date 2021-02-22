//-------+---------+---------+---------+---------+---------+---------+---------+
// 1991-1992 Betz Associates. Released to the Public Domain. This source code
// is offered without warranty or guarantee of any kind, and the author(s)
// expressly disclaim any responsibility for consequences of it's use in
// products for commercial, shareware, or public domain release of any kind.
//
// File Name: HTIMER.H
// Creation:  August 2, 1992
// Author:    Mark Betz (MB)
//
// Machine:   IBM PC and Compatibles
//
// Includes:  nothing
//
//-------+---------+---------+---------+---------+---------+---------+---------+
// Change History
// ------ -------
//
//      Date            Rev.	Author		Purpose
//      ----            ----    ------      -------
//      8-2-1992        1.0     MB          Initial release
//      9-20-1992       1.1     MB          Update release v 1.1
//
// Description
// -----------
//      Header file for the hi-res multi-channel timer
//
//-------+---------+---------+---------+---------+---------+---------+---------+

#pragma once

#include <stdint.h>

// The HTimer class implements a microsecond timer. Each instance of the
// class provides a seperate 32-bit timer channel (up to 255). When the
// constructor is called it tests a static member counter to see if it is the
// first timer instance. If it is, then it reprograms the 8254 channel 1 to
// operate in pulse mode, and increments the counter. When the destructor
// is called it checks the same counter to see if it is the "last guy out".
// If so, it resets the channel to default operation (square wave mode).

class HTimer
{
public:
  HTimer();
  ~HTimer();
  void timerOn();               // starts the timer
  uint32_t timerOff();             // stops the timer, returns elapsed time in mics
  uint32_t getElapsed();           // returns the current elapsed time without
                                // resetting the timer
  void setCount(uint32_t regCount); // used to tell the timer what value
                                // has been loaded into the 8254
                                // counter register
private:
  uint32_t calcElapsed(); // used internally to calculate elapsed time
  static void interrupt int8Handler(...);

  boolean tmrOn;         // true if the timer is running
  uint32_t start8254;        // counter value at start of current run
  uint32_t startTick;       // number of int 8 ticks at start of current run
  static uint32_t ticks;    // incremented on every IRQ 0 level interrrupt
  static uint32_t numTimers; // the number of timer instances in existence
  static uint32_t countVal;  // value loaded into the 8254 counter register
};

// These three functions are a test frame for the timer object

uint32_t testTimerOnOff();
uint32_t testGetElapsed();
uint32_t testFastCount(uint32_t intRate);
