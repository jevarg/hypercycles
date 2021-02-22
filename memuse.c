/*
         MEMORY.C - This example shows how to get information
         about free memory using DPMI call 0500h under DOS/4GW.
         Note that only the first field of the structure is
         guaranteed to contain a valid value; any field that
         is not returned by DOS/4GW is set to -1 (0FFFFFFFFh).

         Compile & Link: wcl386 /l=dos4g memory
      */
#include <stdio.h>
#include <string.h>
#include "dos.h"
#include "i86.h"

#define DPMI_INT 0x31

struct meminfo
{

  unsigned LargestBlockAvail;
  unsigned MaxUnlockedPage;
  unsigned LargestLockablePage;
  unsigned LinAddrSpace;
  unsigned NumFreePagesAvail;
  unsigned NumPhysicalPagesFree;
  unsigned TotalPhysicalPages;
  unsigned FreeLinAddrSpace;
  unsigned SizeOfPageFile;
  unsigned Reserved[3];
} MemInfo;

void
memuse()
{
  union REGS regs;
  struct SREGS sregs;

  regs.x.ax = 0x00000500;
  memset(&sregs, 0, sizeof(sregs));

  sregs.es = FP_SEG(&MemInfo);
  regs.x.di = FP_OFF(&MemInfo);

  int386x(DPMI_INT, &regs, &regs, &sregs);
  printf("Largest available block (in bytes): %lu\n", MemInfo.LargestBlockAvail);
  printf("Maximum unlocked page allocation: %lu\n", MemInfo.MaxUnlockedPage);
  printf("Pages that can be allocated and locked: %lu\n", MemInfo.LargestLockablePage);
  printf("Total linear address space including allocated pages: %lu\n", MemInfo.LinAddrSpace);
  printf("Number of free pages available: %lu\n", MemInfo.NumFreePagesAvail);

  printf("Number of physical pages not in use: %lu\n", MemInfo.NumPhysicalPagesFree);
  printf("Total physical pages managed by host: %lu\n", MemInfo.TotalPhysicalPages);
  printf("Free linear address space (pages): %lu\n", MemInfo.FreeLinAddrSpace);
  printf("Size of paging/file partition (pages): %lu\n", MemInfo.SizeOfPageFile);
}

int
mem_ok()
{
  return 1;

  union REGS regs;
  struct SREGS sregs;

  regs.x.ax = 0x00000500;
  memset(&sregs, 0, sizeof(sregs));

  sregs.es = FP_SEG(&MemInfo);
  regs.x.di = FP_OFF(&MemInfo);

  int386x(DPMI_INT, &regs, &regs, &sregs);
  if (MemInfo.NumFreePagesAvail >= 275)
    return (1);
  return (0);
}
