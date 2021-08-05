#include <uefi.h>

EFI_STATUS main_uefi(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
  SystemTable->ConOut->Reset(SystemTable->ConOut, 1);

  SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Welcome to Chadx86 bootloader\r\n");
  
  while (1){};
  
  return EFI_SUCCESS; //Exits UEFI application (similar to return 0)
}
