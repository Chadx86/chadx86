#include "uefi.h"

typedef EFI_STATUS main_uefi(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
  ConOut->OutputString, L"Welcome to the Chadx86 bootloader!\n"; //Prints to the screen
  
  return EFI_SUCCESS; //Exits UEFI application (similar to return 0)
}
