#pragma once
#include <fb.h>
#include <efi.h>

extern EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE *gop;


extern struct EFI_GUID EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
extern struct EFI_GUID EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID;

void Print(CHAR16* str);

Framebuffer* initGOP(){

    Status = SystemTable->BootServices->LocateProtocol(&EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID, 0, (void**)&gop);

    if(Status == EFI_SUCCESS){
        Print(L"The GOP has been loaded successfully!\n\r");
    }

    framebuffer.BaseAddress = ((void*)gop->Mode->FrameBufferBase);

    framebuffer.BufferSize = gop->Mode->FrameBufferSize;

    framebuffer.Width = gop->Mode->Info->HorizontalResolution;

    framebuffer.Height = gop->Mode->Info->VerticalResolution;

    framebuffer.PixelsPerScanLine = gop->Mode->Info->PixelsPerScanLine;

    return &fb;
}