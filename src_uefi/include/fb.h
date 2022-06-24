void framebuffer(){

    typedef struct {

        void* BaseAddress; // a void pointer holds the address of any type of variable

        size_t BufferSize; // controls how big the buffer is (a buffer is a little place of data)

        // A framebuffer (frame buffer, or sometimes framestore) is a portion of random-access memory (RAM) containing a bitmap that drives a video display.

        // Signed vales can be both negative and positive (-50/50)

        // Unsigned values on the other hand, don't allow negative numbers (0/100)

        unsigned int Width;

        // screen height and width

        unsigned int Height;

        unsigned int PixelsPerScanLine; // Pixels per scan line is how you determinine your refresh rate

    } Framebuffer; // the name of the class and what this class does is outputs the pixels

    Framebuffer fb;

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
}

FONT* LoadFont(EFI_FILE* Directory, CHAR16* Path, EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable){

        EFI_FILE* font = LoadFile(Directory, Path, ImageHandle, SystemTable);

        if(font == NULL){
            return NULL;
        }

        FONT_HEADER* fontHeader;

        SystemTable->BootServices->AllocatePool(EfiLoaderData, sizeof(FONTHEADER), (void**)&fontHeader);
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