#pragma once

/**
 * @brief  get the command line, removing the program name
 * @note   https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/src/getcmd.html
 * @param  char *cmd_line
 * @retval The address of the target cmd_line.
 */
char* getcmd(char* cmd_line);