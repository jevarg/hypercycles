#pragma once

#include "watcom.h"

/**
 * @brief   The _disable() function causes interrupts to become disabled.
 * @note    https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/src/_disable.html
 */
void _disable(void);

/**
 * @brief    The _enable() function causes interrupts to become enabled.
 * @note    https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/src/_enable.html
 */
void _enable(void);

/**
 * @brief  suspend a process for a given length of time
 * @note   https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/src/delay.html
 * @param  milliseconds: amount of ms to pause the execution for
 * @retval 0 if the full time specified was completed, or the number of milliseconds unslept if interrupted by a signal.
 */
unsigned int delay(unsigned int milliseconds);

/**
 * @brief  obtain the segment portion of a far pointer
 * @note   https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/src/fp_seg.html
 * @param  _far *far_ptr: 
 * @retval The segment portion of the pointer value.
 */
unsigned FP_SEG(void _far *far_ptr);

/**
 * @brief  obtain the offset of a far pointer value
 * @note   https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/src/fp_off.html
 * @param  _far *far_ptr: 
 * @retval The offset portion of the pointer value.
 */
unsigned FP_OFF(void _far *far_ptr);