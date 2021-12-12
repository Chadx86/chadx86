//everything is defined in efi.h
#define NULL (void*)0 //defining NULL as 0

//Page 509 in UEFI 2.8b

//*******************************************************
// Open Modes
//*******************************************************
#define EFI_FILE_MODE_READ     0x0000000000000001
#define EFI_FILE_MODE_WRITE    0x0000000000000002
#define EFI_FILE_MODE_CREATE   0x8000000000000000
//*******************************************************
// File Attributes
//*******************************************************
#define EFI_FILE_READ_ONLY     0x0000000000000001
#define EFI_FILE_HIDDEN        0x0000000000000002
#define EFI_FILE_SYSTEM        0x0000000000000004
#define EFI_FILE_RESERVED      0x0000000000000008
#define EFI_FILE_DIRECTORY     0x0000000000000010
#define EFI_FILE_ARCHIVE       0x0000000000000020
#define EFI_FILE_VALID_ATTR    0x0000000000000037

EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *Volume;

EFI_LOAD_FILE* LoadFile(EFI_LOAD_FILE* Directory, CHAR16* Path, EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable){
    
}

void InitializeFILESYSTEM()
{
    // you need a file system to load a file, EFI uses FAT32
    
    Print(L"LoadedImage ... ");
    EFI_LOADED_IMAGE_PROTOCOL *LoadedImage;
    SystemTable->BootServices->HandleProtocol(ImageHandle, &EFI_LOADED_IMAGE_PROTOCOL_GUID, (void**)&LoadedImage);
    
    Print(L"DevicePath ... ");
    EFI_DEVICE_PATH_PROTOCOL *DevicePath;
    SystemTable->BootServices->HandleProtocol(LoadedImage->DeviceHandle, &EFI_DEVICE_PATH_PROTOCOL_GUID, (void**)&DevicePath);

    Print(L"Volume ... ");
    SystemTable->BootServices->HandleProtocol(LoadedImage->DeviceHandle, &EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID, (void**)&Volume);
}

EFI_FILE_PROTOCOL* openFile(CHAR16* FileName)
{
    // This opens a file from the EFI FAT32 file system volume.

    Print(L"RootFS ... ");
    EFI_FILE_PROTOCOL* RootFS;
    Volume->OpenVolume(Volume, &RootFS);

    Print(L"Opening File ... ");
    EFI_FILE_PROTOCOL* FileHandle = NULL;
    RootFS->Open(RootFS, &FileHandle, FileName, 0x0000000000000001, 0);
    
    return FileHandle;
}

void closeFile(EFI_FILE_PROTOCOL* FileHandle)
{
    // This closes the file.

    Print(L"Closing File ... ");
    FileHandle->Close(FileHandle);
}