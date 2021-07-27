#include "efi.h"

typedef EFI_STATUS uefi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
  
  CHAR16 *Str; //Str is short for string
  
  Str = L"Welcome to the Chadx86 bootloader! \n";
  
  return EFI_SUCCESS; // exits UEFI application (similar to return 0)
  
}
