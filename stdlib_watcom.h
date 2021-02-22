#if __APPLE__

/**
 * @brief   reverse a string
 * @note    https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/src/strrev.html
 * @param   char *str: 
 * @retval  The address of the original string str.
 */
char* strrev(char* str);

/**
 * @brief   The itoa() function constructs a string representation of an integer.
 * @note    https://users.pja.edu.pl/~jms/qnx/help/watcom/clibref/src/itoa.html
 * @param   value: The value to represent as a string
 * @param   char *string: 
 * @param   radix
 * @retval  A string representation of the value param
 */
char* itoa(int value, char* string, int radix);

#endif