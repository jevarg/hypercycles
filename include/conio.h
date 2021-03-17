#pragma once

#ifndef getche
#include <curses.h> // Needed for getch
#define getche getch
#endif

/**
 * @note https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/src/putch.html
 */
#define putch putchar

/**
 * @note https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/src/cprintf.html
 */
#define cprintf printf

/**
 * @brief   Inputs, from a port, a byte
 * @note    https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/src/inp.html
 * @param   port: I/O port to get the value from.
 * @retval  The byte read from port. There's no error return.
 */
unsigned int inp(unsigned int port);

/**
 * @brief   Write one byte to a 80x86 hardware port
 * @note    https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/src/outp.html
 * @param   port: I/O port to write the value to.
 * @retval  The value transmitted.
 */
unsigned int outp(int port, int value);

/**
 * @brief  Checks the console for keyboard input.
 * @note   https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/kbhit?view=msvc-160
 * @retval nonzero value if a key has been pressed. Otherwise, it returns 0.
 */
int kbhit();