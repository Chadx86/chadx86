#include <uefi.h>

EFI_STATUS main_uefi(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
  SystemTable->ConOut->Reset(SystemTable->ConOut, 1);

  SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Welcome to Chadx86 bootloader\r\n");

   //GOP

    EFI_STATUS Status;

    Status = SystemTable->BootServices->LocateProtocol(&EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID, 0, (void**)&gop);
    if(Status == EFI_SUCCESS)
    {
      Print(L"The GOP has been loaded successfully!");
    }
  
  while (1){};
  
  return EFI_SUCCESS; //Exits UEFI application (similar to return 0)
}