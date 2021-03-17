/**
        ===== To be used with OUTCHIP.ASM & SETFREQ.ASM files. =====

        The following routines are public (see each routine for further
        documentation):

                SoundColdInit (port)
                SoundWarmInit()
                SetMode (mode)
                SetWaveSel (state)
                SetPitchRange (pR)
                SetGParam (amD, vibD, nSel)
                SetVoiceTimbre (voice, paramArray)
                SetVoiceVolume(voice, volume)
                SetVoicePitch (voice, pitchBend)
                NoteOn (voice, pitch)
                NoteOff (voice)

**/
#include <stdint.h>
#include <stdlib.h>
#include "adlib.h"
#include "debug.h"
#include "cflags.h"
#include "conio.h"
#include "watcom.h"

/* Declaring variables as near improves performance. */
#define N_V near

/*
        In percussive mode, the last 4 voices  (SD TOM HH CYMB) are created
        using melodic voices 7 & 8. A noise generator use channels 7 & 8
        frequency information for creating rhythm instruments. Best results
        are obtained by setting TOM two octaves below mid C and SD 7 half-tones
        above TOM.
        In this implementation, only the TOM pitch may vary, with the SD always
        set 7 half-tones above it.
*/

#define TOM_PITCH 24 /* best frequency, in range of 0 to 95 */
#define TOM_TO_SD 7  /* 7 half-tones between voice 7 & 8 */
#define SD_PITCH (TOM_PITCH + TOM_TO_SD)

#define GetLocPrm(slot, prm) ((unsigned)paramSlot[slot][prm])

/*
-----------------------------------------------------------------
*/
int MAX_VOLUME = 0x7f;

unsigned int genAddr; /* addr. of sound chip, in DS, used by OUTCHIP.ASM */
unsigned pitchRange;  /* pitch variation, half-tone [+1,+12] */

static int N_V modeWaveSel; /* != 0 if used with the 'wave-select' parameters */

static char N_V percBits; /* control bits of percussive voices */
static const char N_V percMasks[] = {
  0x10, 0x08, 0x04, 0x02, 0x01
};

static char N_V voiceNote[9];      /* pitch of last note-on of each voice */
static char N_V voiceKeyOn[9];     /* state of keyOn bit of each voice */
static unsigned N_V vPitchBend[9]; /* current pitch bend of each voice */
static char N_V bxRegister[9];     /* current val. of 0xB0 - 0xB8 reg */
static char N_V lVoiceVolume[11];  /* volume for each of 11 logical voices */

static unsigned N_V modeVoices; /* 9 or 11, depending on 'percussion'*/

/* definition of the ELECTRIC-PIANO voice (opr0 & opr1) */
static unsigned char N_V pianoParamsOp0[nbLocParam] = {
  1, 1, 3, 15, 5, 0, 1, 3, 15, 0, 0, 0, 1, 0
};
static unsigned char N_V pianoParamsOp1[nbLocParam] = {
  0, 1, 1, 15, 7, 0, 2, 4, 0, 0, 0, 1, 0, 0
};

/* definition of default percussive voices: */
static unsigned char N_V bdOpr0[] = { 0, 0, 0, 10, 4, 0, 8, 12, 11, 0, 0, 0, 1, 0 };
static unsigned char N_V bdOpr1[] = { 0, 0, 0, 13, 4, 0, 6, 15, 0, 0, 0, 0, 1, 0 };
static unsigned char N_V sdOpr[] = { 0, 12, 0, 15, 11, 0, 8, 5, 0, 0, 0, 0, 0, 0 };
static unsigned char N_V tomOpr[] = { 0, 4, 0, 15, 11, 0, 7, 5, 0, 0, 0, 0, 0, 0 };
static unsigned char N_V cymbOpr[] = { 0, 1, 0, 15, 11, 0, 5, 5, 0, 0, 0, 0, 0, 0 };
static unsigned char N_V hhOpr[] = { 0, 1, 0, 15, 11, 0, 7, 5, 0, 0, 0, 0, 0, 0 };

static char N_V paramSlot[18][nbLocParam]; /* all the parameters of slots...  */

static char N_V amDepth;    /* chip global parameters .. */
static char N_V vibDepth;   /* ... */
static char N_V noteSel;    /* ... */
static char N_V percussion; /* percussion mode parameter */

/* Slot numbers as a function of the voice and the operator.
   (melodic mode only)
*/
unsigned char N_V slotMVoice[9][2] = {
  { 0, 3 },   /* voix 0 */
  { 1, 4 },   /* 1 */
  { 2, 5 },   /* 2 */
  { 6, 9 },   /* 3 */
  { 7, 10 },  /* 4 */
  { 8, 11 },  /* 5 */
  { 12, 15 }, /* 6 */
  { 13, 16 }, /* 7 */
  { 14, 17 }  /* 8 */
};

/* Slot numbers for the percussive voices.
   255 indicates that there is only one slot used by a voice.
*/
unsigned char N_V slotPVoice[11][2] = {
  { 0, 3 },    /* voice 0 */
  { 1, 4 },    /* 1 */
  { 2, 5 },    /* 2 */
  { 6, 9 },    /* 3 */
  { 7, 10 },   /* 4 */
  { 8, 11 },   /* 5 */
  { 12, 15 },  /* Bass Drum: slot 12 et 15 */
  { 16, 255 }, /* SD: slot 16 */
  { 14, 255 }, /* TOM: slot 14 */
  { 17, 255 }, /* TOP-CYM: slot 17 */
  { 13, 255 }  /* HH: slot 13 */
};

/* 
        This table gives the offset of each slot within the chip.
        offset = fn (slot)
*/
static const char N_V offsetSlot[] = {
  0, 1, 2, 3, 4, 5,
  8, 9, 10, 11, 12, 13,
  16, 17, 18, 19, 20, 21
};

/* This table indicates if the slot is a modulator (operator 0) or a
   carrier (operator 1).
   opr = fn (slot)
*/
static const char N_V carrierSlot[] = {
  0, 0, 0, /* 1 2 3 */
  1, 1, 1, /* 4 5 6 */
  0, 0, 0, /* 7 8 9 */
  1, 1, 1, /* 10 11 12 */
  0, 0, 0, /* 13 14 15 */
  1, 1, 1, /* 16 17 18 */
};

/* This table gives the voice number associated with each slot.
   (melodic mode only)
   voice = fn (slot)
*/
static const char N_V voiceMSlot[] = {
  0,
  1,
  2,
  0,
  1,
  2,
  3,
  4,
  5,
  3,
  4,
  5,
  6,
  7,
  8,
  6,
  7,
  8,
};

/* This table gives the voice number  (0-10) associated with each
   slot (percussive mode only),
   voice = fn (slot)
*/
static const char N_V voicePSlot[] = {
  0, 1, 2,
  0, 1, 2,
  3, 4, 5,
  3, 4, 5,
  BD, HIHAT, TOM,
  BD, SD, CYMB
};

/*----------------------------------------------------------
   Function prototypes.
*/

extern void SndOutput(); /* in file OUTCHIP.ASM */
//extern void SetFreq();                               /* in file SETFREQ.ASM */

static void InitSlotParams();
static void SetSlotParam(unsigned, unsigned*, unsigned);
static void SndSetPrm(int, int);
static void SndSetAllPrm(int);
static void SndSKslLevel(int);
static void SndSNoteSel();
static void SndSFeedFm(int);
static void SndSAttDecay(int);
static void SndSSusRelease(int);
static void SndSAVEK(int);
static void SndSAmVibRhythm();
static void SndWaveSelect(int);
static void UpdateFNums(int);
static int BoardInstalled();
unsigned SetFreq(int, int, int, int);

/*
----------------------------------------------------------
*/

/*
        Must be called for start-up initialisation.

        Returns 0 if hardware not found.
*/
int
SoundColdInit(unsigned port) /* io port address of sound board (0x388) */
{
  PRINT_FUNC;
} /* SoundColdInit() */

/*
-----------------------------------------------
        Initialize the chip in melodic mode (mode == 0),
        set all 9 voices to electric-piano timbres,
        set the 3 global parameters to zero,
        set the pitch bend range to 1 half-tone,
        set the pitch bend of each voice to 0x2000 (no detune),
        set the volume of each voice to maximum level,
        and enable the wave-select parameter.
-----------------------------------------------
*/
void
SoundWarmInit()
{
  PRINT_FUNC;
} /* SoundWarmInit() */

/*
---------------------------------------------
        Put the chip in melodic mode (mode == 0),
        or in percussive mode  (mode != 0).

        If the melodic mode is chosen, all voices are
        set to electric-piano, else the first 5 are set
        to electric-piano, and the percussion voices
        to their default timbres.
---------------------------------------------
*/
void
SetMode(int mode)
{
  PRINT_FUNC;
} /* SetMode() */

/*
        Enable (state != 0) / disable (state == 0)
        the wave-select parameters.

        If you do not want to use the wave-select parameters, call
        this function with a value of 0 AFTER calling SoundColdInit()
        or SoundWarmInit().
*/
void
SetWaveSel(int state)
{
  PRINT_FUNC;
} /* SetWaveSel() */

/*
        Routine to change the pitch bend range. The value can be from
        1 to 12 (in half-tones).

        For example, the value 12 means that the pitch bend will 
        range from -12 (pitchBend == 0, see function 'SetVoicePitch()')
        to +12 (pitchBend == 0x3fff) half-tones.

        The change will be effective as of the next call to
        'SetVoicePitch()'.
*/
void
SetPitchRange(unsigned pR)
{
  PRINT_FUNC;
} /* SetPitchRange() */

/*
----------------------------------------------
        Set the 3 global parameters AmDepth,
        VibDepth & NoteSel

        The change takes place immediately.
----------------------------------------------
*/
void
SetGParam(int amD, int vibD, int nSel)
{
  PRINT_FUNC;
} /* SetGParam() */

/*
-------------------------------------------------
        Set the parameters of the voice 'voice'.

        In melodic mode, 'voice' varies from 0 to 8.
        In percussive mode, voices 0 to 5 are melodic
        and 6 to 10 are percussive.

        A timbre (melodic or percussive) is defined as follows:
        the 13 first parameters of operator 0  (ksl, multi, feedBack,
        attack, sustain, eg-typem decay, release, level, am, vib, ksr, fm)
        followed by the 13 parameters of operator 1 (if a percussive voice, all
        the parameters are zero), followed by the wave-select parameter for
        the operators 0 and 1.

        'paramArray' is structured as follows:
                struct {
                        int opr0Prm [13];       first 13 parameters
                        int opr1Prm [13];       must be 0 if percussive timbre
                        int     opr0WaveSel;            last parameter
                        int opr1WaveSel;                must be 0 if percussive timbre
                } TimbreDef;

        The old timbre files (*.INS) do not contain the parameters
        'opr0WaveSel' and 'opr1WaveSel'.
        Set these two parameters to zero if you are using the old file
        format.
------------------------------------------------
*/
void
SetVoiceTimbre(unsigned voice, unsigned* paramArray)
{
  PRINT_FUNC;
} /* SetVoiceTimbre() */

/*
--------------------------------------------------
        Set the volume of the voice 'voice' to 'volume'.

        The resulting output level is (timbreVolume * volume / 127).
        The change takes place immediately.

        0 <= volume <= 127
--------------------------------------------------
*/
void
SetVoiceVolume(unsigned voice, unsigned volume) /* 0 - 0x7f */
{
  PRINT_FUNC;
} /* SetVoiceVolume() */

/*
-------------------------------------------------
        Change the pitch value of a voice.

        The variation in pitch is a function of the previous call
        to 'SetPitchRange()' and the value of 'pitchBend'.
        A value of 0 means -half-tone * pitchRange,
        0x2000 means no variation (exact pitch) and
        0x3fff means +half-tone * pitchRange.

        Does not affect the percussive voices, except for the bass drum.

        The change takes place immediately.

        0 <= pitchBend <= 0x3fff, 0x2000 == exact tuning
-------------------------------------------------
*/
SetVoicePitch(voice, pitchBend) unsigned voice;
unsigned pitchBend;
{
  PRINT_FUNC;
} /* SetVoicePitch() */

/*
-----------------------------------------------------------
        Routine to start a note playing.

        0 <= voice <= 8 in melodic mode,
        0 <= voice <= 10 in percussive mode;
        0 <= pitch <= 127, 60 == MID_C  (the card can play between 12 and 107 )
-----------------------------------------------------------
*/
NoteOn(voice, pitch) unsigned voice;
int pitch; /* 0 - 127 */
{
  PRINT_FUNC;
} /* NoteOn() */

/*
        Routine to stop playing the note which was started in 'NoteOn()'.

        0 <= voice <= 8 in melodic mode,
        0 <= voice <= 10 in percussive mode;
*/
NoteOff(voice) unsigned voice;
{
  PRINT_FUNC;
} /* NoteOff() */

/*
------------------------------------------------------------------------
        static functions ...
------------------------------------------------------------------------
*/

/*
        In melodic mode, initialize all voices to electric-pianos.

        In percussive mode, initialize the first 6 voices to electric-pianos
        and the percussive voices to their default timbres.
*/
static void
InitSlotParams()
{
  PRINT_FUNC;
} /* InitSlotParams() */

/*
        Used to change the parameter 'param' of the slot 'slot'
        with the value 'val'. The chip registers are updated.
*/
SetASlotParam(slot, param, val) int slot, val;
int param; /* parameter number */
{
  PRINT_FUNC;
} /* SetASlotParam() */

/*
------------------------------------------------------
        Set the 14 parameters  (13 in 'param', 1 in 'waveSel')
        of slot 'slot'. Update the parameter array and the chip.
------------------------------------------------------
*/
static void SetSlotParam(slot, param, waveSel) unsigned slot, *param, waveSel;
{
  PRINT_FUNC;
} /* SetSlotParam() */

void
SetCharSlotParam(int slot, unsigned char* cParam, int waveSel)
{
  PRINT_FUNC;
} /* SetCharSlotParam() */

/*
-----------------------------------------------
        Update the parameter 'prm' for the slot 'slot'.
        Update the chip registers.
-----------------------------------------------
*/
static void SndSetPrm(slot, prm) int slot, prm;
{
  PRINT_FUNC;
} /* SndSetPrm() */

/*-------------------------------------------------
        Transfer all the parameters from slot 'slot' to
        the chip.
*/
static void SndSetAllPrm(slot)
{
  PRINT_FUNC;
} /* SndSetAllPrm() */

/*
        Write to the register which controls output level and does
        key-on/key-offs for the percussive voice slots.
*/
static void SndSKslLevel(slot)
{
  PRINT_FUNC;
}

/* --------------------------------------------
        Write to the register which controls the note select parameter.
*/
static void
SndSNoteSel()
{
  PRINT_FUNC;
} /* SndSNoteSel() */

/* --------------------------------------------
        FEED-BACK and FM (connection).
        Applicable only to operator 0 in melodic mode.
*/
static void SndSFeedFm(slot)
{
  PRINT_FUNC;
}

/*
        ATTACK, DECAY
*/
static void SndSAttDecay(slot)
{
  PRINT_FUNC;
}

/*
        SUSTAIN, RELEASE
*/
static void SndSSusRelease(slot)
{
  PRINT_FUNC;
}

/*
        AM, VIB, EG-TYP (Sustaining), KSR, MULTI
*/
static void SndSAVEK(slot)
{
  PRINT_FUNC;
} /* SndSAVEK() */

/*
        Set the values: AM Depth, VIB depth & Rhythm (melo/perc mode)
*/
static void
SndSAmVibRhythm()
{
  PRINT_FUNC;
}

/*
        Set the wave-select parameter.
*/
static void SndWaveSelect(slot)
{
  PRINT_FUNC;
} /* SndWaveSelect() */

/*
        Change pitch, pitchBend & keyOn of voices 0 to 8, for melodic
        or percussive mode.
*/

static void UpdateFNums(voice)
{
  PRINT_FUNC;
}

/*
        Return 0 if board is not installed.  The chip's timers are used to
        determined if an Ad Lib card is present.  When being used, the timers
        place specific values in the status register.  If we do not read the
        correct values from the status register, then we can assume that no
        board is present.
*/
static int
BoardInstalled()
{
  PRINT_FUNC;
}

/*----------------------------------------------------------------------*/

/* The following, OutFreq(), is provided as an alternative to SetFreq().
   You may find it easier to understand as SetFreq is written in assembler.
   However, SetFreq is faster so you should definitely use SetFreq. The
   main purpose of including OutFreq() is to show you how to set the
   f-number registers.
*/

static unsigned freqNums[12] = {
  /*  C    C#   D    D#   E    F */
  343, 363, 385, 408, 432, 458,
  /*  F#   G    G#   A    A#   B */
  485, 514, 544, 577, 611, 647
};

unsigned int
SetFreq(int voice, int pitch, int bend, int keyOn)
{
  PRINT_FUNC;
}
