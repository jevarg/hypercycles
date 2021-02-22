#pragma once

#define JOY_X 1
#define JOY_Y 2
#define JBUTTON1 0x10
#define JBUTTON2 0x20
#define LMBUTTON 1
#define RMBUTTON 2

#ifdef __cplusplus
extern "C"
{
#endif
	int readstick(int);					 // Read joystick position
	int readjbutton(int);				 // Read joystick button
	int initmouse();					 // Initialize mouse driver
	void rempointer();					 // Remove mouse pointer from display
	void disppointer();					 // Show mouse pointer on display
	int readmbutton();					 // Read mouse buttons
	void relpos(int *, int *);			 // Get relative mouse position
	int initkey(char /* far */ *buffer); // Initialize keyboard handler
	int getscan();						 // Get last scan code
	int remkey();						 // Remove keyboard handler
#ifdef __cplusplus
}
#endif