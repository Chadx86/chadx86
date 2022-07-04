#include "stdint.h"
#include "stddef.h"
#include <efi.h>
#include <elf.h>

extern struct EFI_GUID EFI_LOADED_IMAGE_PROTOCOL_GUID;
extern struct EFI_GUID EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;

typedef struct {
    void* BaseAddress; // a void pointer holds the address of any type of variable
    size_t BufferSize; // controls how big the buffer is (a buffer is a little place of data)
    unsigned int Width, Height;
    // screen height and width
    unsigned int PixelsPerScanLine; // Pixels per scan line is how you determinine your refresh rate
} Framebuffer; // the name of the class and what this class does is outputs the pixels

extern Framebuffer fb;

#define FONT_MAGIC0 0x36
#define FONT_MAGIC1 0x04

typedef struct {
    unsigned char magic[2]; // we call it magic because this is the bytes the header stores that lets us identify that the psf file is a psf file
    unsigned char mode; // the mode that the psf font is in
    unsigned char charsize; // defines how large the characters are in bytes
} FONT_HEADER;

typedef struct {
    FONT_HEADER* fontHdr;
    void* glyphBuffer; // keeps data about the piece of text or character
} FONT;

EFI_FILE_PROTOCOL* LoadFile(EFI_FILE_PROTOCOL* Directory, CHAR16* Path, EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable);
FONT* LoadFont(EFI_FILE_PROTOCOL* Directory, CHAR16* Path, EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable);