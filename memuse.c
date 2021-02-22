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
  //FIXME: This function had a lot of assembly code inside
  // It need to be replaced for UNIX OSes (macOS, GNU/Linux) 

  printf("Largest available block (in bytes): %u\n", MemInfo.LargestBlockAvail);
  printf("Maximum unlocked page allocation: %u\n", MemInfo.MaxUnlockedPage);
  printf("Pages that can be allocated and locked: %u\n", MemInfo.LargestLockablePage);
  printf("Total linear address space including allocated pages: %u\n", MemInfo.LinAddrSpace);
  printf("Number of free pages available: %u\n", MemInfo.NumFreePagesAvail);

  printf("Number of physical pages not in use: %u\n", MemInfo.NumPhysicalPagesFree);
  printf("Total physical pages managed by host: %u\n", MemInfo.TotalPhysicalPages);
  printf("Free linear address space (pages): %u\n", MemInfo.FreeLinAddrSpace);
  printf("Size of paging/file partition (pages): %u\n", MemInfo.SizeOfPageFile);
}

int
mem_ok()
{
  return 1;
}
