#include <fb.h>

//Open Modes
#define EFI_FILE_MODE_READ      0x0000000000000001

//File Attributes
#define EFI_FILE_READ_ONLY      0x0000000000000001

struct EFI_GUID EFI_LOADED_IMAGE_PROTOCOL_GUID       = {0x5b1b31a1, 0x9562, 0x11d2, {0x8e, 0x3f, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}};
struct EFI_GUID EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID = {0x964e5b22, 0x6459, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}};

extern EFI_GUID gEfiLoadedImageProtocolGuid;
#define LoadedImageProtocol gEfiLoadedImageProtocolGuid
extern EFI_GUID gEfiSimpleTextInProtocolGuid;

EFI_FILE_PROTOCOL* LoadFile(EFI_FILE_PROTOCOL* Directory, CHAR16* Path, EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable){ // uefi treats directories as files 
    EFI_FILE_PROTOCOL* LoadedFile;
        
    EFI_LOADED_IMAGE_PROTOCOL* LoadedImage;
    SystemTable->BootServices->HandleProtocol(ImageHandle, &gEfiLoadedImageProtocolGuid, (void**)&LoadedImage);

    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* FileSystem;
    SystemTable->BootServices->HandleProtocol(LoadedImage->DeviceHandle, &gEfiSimpleTextInProtocolGuid, (void**)&FileSystem);

    if (Directory == NULL){
        FileSystem->OpenVolume(FileSystem, &Directory);
    }

    EFI_STATUS s = Directory->Open(Directory, &LoadedFile, Path, EFI_FILE_MODE_READ, EFI_FILE_READ_ONLY);

    if(s != EFI_SUCCESS){
        return NULL;
    }
    return LoadedFile;
}

FONT* LoadFont(EFI_FILE_PROTOCOL* Directory, CHAR16* Path, EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable){
    EFI_FILE_PROTOCOL* font = LoadFile(Directory, Path, ImageHandle, SystemTable);

    if(font == NULL){
        return NULL;
    }

    FONT_HEADER* fontHeader;

    SystemTable->BootServices->AllocatePool(EfiLoaderData, sizeof(FONT_HEADER), (void**)&fontHeader);
    UINTN size = sizeof(FONT_HEADER);
    font->Read(font, &size, fontHeader);

    if(fontHeader->magic[0] != FONT_MAGIC0 || fontHeader->magic[1] != FONT_MAGIC1){

        return NULL;

    }

    UINTN glyphBufferSize = fontHeader->charsize * 256;

    if(fontHeader->mode == 1) { //512 glyph mode
            
        glyphBufferSize = fontHeader->charsize * 512;

    }

    void* glyphBuffer; {

        font->SetPosition(font, sizeof(FONT_HEADER));

        SystemTable->BootServices->AllocatePool(EfiLoaderData, glyphBufferSize, (void**)&glyphBuffer);

        font->Read(font, &glyphBufferSize, glyphBuffer);

    }

    FONT* finishedFont;

    SystemTable->BootServices->AllocatePool(EfiLoaderData, sizeof(FONT), (void**)&finishedFont);

    finishedFont->fontHdr = fontHeader;

    finishedFont->glyphBuffer = glyphBuffer;

    return finishedFont;
}