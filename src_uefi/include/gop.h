#pragma once
#include <fb.h>
#include <efi.h>
#include <elf.h>

extern EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE *gop;

extern struct EFI_GUID EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
extern struct EFI_GUID EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID;

void Print(CHAR16* str);

Framebuffer* initGOP(){
    EFI_STATUS Status;

    Status = SystemTable->BootServices->LocateProtocol(&EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID, 0, (void**)&gop);

    if(Status == EFI_SUCCESS){
        Print(L"The GOP has been loaded successfully!\n\r");
    }

    fb.BaseAddress = ((void*)gop->Mode->FrameBufferBase);

    fb.BufferSize = gop->Mode->FrameBufferSize;

    fb.Width = gop->Mode->Info->HorizontalResolution;

    fb.Height = gop->Mode->Info->VerticalResolution;

    fb.PixelsPerScanLine = gop->Mode->Info->PixelsPerScanLine;

    return &fb;
}