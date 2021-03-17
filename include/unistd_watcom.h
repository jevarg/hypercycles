#pragma once

/**
 * @brief   Return the number of bytes in an open file
 * @note    https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/src/filelength.html
 * @param   filedes: file descriptor
 * @retval  The number of bytes in the file. If an error occurs, (-1L) is returned, and errno indicates the type of error detected.
 */
long int filelength(int filedes);