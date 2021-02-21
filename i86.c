#include "i86.h"
#include <unistd.h>

void _disable(void) {}
void _enable(void) {}

unsigned int delay(unsigned int milliseconds)
{
    usleep(milliseconds * 1000); // usleep is taking microseconds
}

unsigned FP_SEG(void _far *far_ptr)
{
    return 0;
}

unsigned FP_OFF(void _far *far_ptr)
{
    return 0;
}