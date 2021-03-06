#include <gop.h>

EFI_GRAPHICS_OUTPUT_PROTOCOL *gop;


struct EFI_GUID EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID    = {0x9042a9de, 0x23dc, 0x4a38, {0x96, 0xfb, 0x7a, 0xde, 0xd0, 0x80, 0x51, 0x6a}};
struct EFI_GUID EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID = {0x387477c2,0x69c7,0x11d2, {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}};

void Print(CHAR16* str)
{
    SystemTable->ConOut->OutputString(SystemTable->ConOut, str);
}

Framebuffer* initGOP(){
    EFI_STATUS Status;

    Status = SystemTable->BootServices->LocateProtocol(&EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID, 0, (void**)&gop);

    if(Status == EFI_SUCCESS){
        Print(L"The GOP has been loaded successfully!\n\r");
    }
    else{
        Print(L"The GOP has either failed to load or can not be located");
    }

    fb.BaseAddress = ((void*)gop->Mode->FrameBufferBase);
    fb.BufferSize = gop->Mode->FrameBufferSize;
    fb.Width = gop->Mode->Info->HorizontalResolution;
    fb.Height = gop->Mode->Info->VerticalResolution;
    fb.PixelsPerScanLine = gop->Mode->Info->PixelsPerScanLine;

    return &fb;
}