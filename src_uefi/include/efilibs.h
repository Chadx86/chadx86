#define EFI_BROWN 0x06
#define EFI_CYAN 0x03
#define NULL (void*)0

EFI_HANDLE ImageHandle;
EFI_SYSTEM_TABLE* SystemTable;
EFI_GRAPHICS_OUTPUT_PROTOCOL* gop;
EFI_GRAPHICS_OUTPUT_BLT_PIXEL GraphicsColor;
EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *Volume;

void SetColor(UINTN Attribute) //change color of text
{
    SystemTable->ConOut->SetAttribute(SystemTable->ConOut, Attribute);
}

void InitializeFILESYSTEM()
{
    EFI_STATUS Status;
    // To load a file, you must have a file system. EFI takes advantage of the FAT32 file system.
    SetColor(EFI_BROWN);
    Print(L"LoadedImage ... ");
    EFI_LOADED_IMAGE_PROTOCOL *LoadedImage;
    Status = SystemTable->BootServices->HandleProtocol(ImageHandle, &EFI_LOADED_IMAGE_PROTOCOL_GUID, (void**)&LoadedImage);
    SetColor(EFI_CYAN);
    Print(CheckStandardEFIError(Status));
    
    SetColor(EFI_BROWN);
    Print(L"DevicePath ... ");
    EFI_DEVICE_PATH_PROTOCOL *DevicePath;
    Status = SystemTable->BootServices->HandleProtocol(LoadedImage->DeviceHandle, &EFI_DEVICE_PATH_PROTOCOL_GUID, (void**)&DevicePath);
    SetColor(EFI_CYAN);
    Print(CheckStandardEFIError(Status));
    
    SetColor(EFI_BROWN);
    Print(L"Volume ... ");
    Status = SystemTable->BootServices->HandleProtocol(LoadedImage->DeviceHandle, &EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID, (void**)&Volume);
    SetColor(EFI_CYAN);
    Print(CheckStandardEFIError(Status));
}

EFI_FILE_PROTOCOL* openFile(CHAR16* FileName)
{
    // opens a file
    EFI_STATUS Status;
    SetColor(EFI_BROWN);
    Print(L"RootFS ... ");
    EFI_FILE_PROTOCOL* RootFS;
    Status = Volume->OpenVolume(Volume, &RootFS);
    SetColor(EFI_CYAN);
    Print(CheckStandardEFIError(Status));
    
    SetColor(EFI_BROWN);
    Print(L"Opening File ... ");
    EFI_FILE_PROTOCOL* FileHandle = NULL;
    Status = RootFS->Open(RootFS, &FileHandle, FileName, 0x0000000000000001, 0);
    SetColor(EFI_CYAN);
    Print(CheckStandardEFIError(Status));
    
    return FileHandle;
}

void closeFile(EFI_FILE_PROTOCOL* FileHandle)
{
    // closes a file
    EFI_STATUS Status;
    SetColor(EFI_BROWN);
    Print(L"Closing File ... ");
    Status = FileHandle->Close(FileHandle);
    SetColor(EFI_CYAN);
    Print(CheckStandardEFIError(Status));
}