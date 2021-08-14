//Alot of the comments are from the UEFI Specs 2.9, some comments are added in
//UEFI Specs is the reference I used for the code (PedroElFrijol)

#define EFI_SUCCESS 0 //Also similar to Return 0, you could use that if you'd like
#define EFIAPI
#define EFI_BROWN 0x06
#define EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID \ {0x9042a9de,0x23dc,0x4a38,\  {0x96,0xfb,0x7a,0xde,0xd0,0x80,0x51,0x6a}}

//UEFI Data Types
typedef unsigned short int uint16_t; //2 byte unsigned integer

typedef unsigned int uint32_t; //4 byte unsigned integer

typedef signed long long INTN; //Signed value of native width

typedef unsigned long long UINTN; //Unsigned value of native width

typedef void *EFI_HANDLE; //this is here as a pointer

//We are using and unsigned short int since that is equal to 16 bits

typedef signed char INT8; //1-byte signed value

typedef unsigned char UINT8; //1-byte unsigned value

//Set to a char sice it is just 1 byte

typedef signed short INT16; //2-byte signed value

typedef unsigned short UINT16; //2-byte unsigned value

//Set it to short since it is just 2 bytes

typedef signed int INT32; //4-byte signed value

typedef unsigned int UINT32; //4-byte unsigned value

//Regular unsigned int

typedef signed long long INT64; //8-byte signed value

typedef unsigned long long UINT64; //8-byte unsigned value

//It is set to long long instead of int because it is 8 bytes (64 bits) and it is larger

typedef UINT64 EFI_STATUS;

typedef void *EFI_HANDLE; //A collection of related interfaces

//We are using void * since that is the type the uefi specs said it should be

typedef unsigned char BOOLEAN; //Logical Boolean. 1-byte value containing a 0 for FALSE or a 1 for TRUE. (just a regular boolean)

typedef uint16_t CHAR16; //2-byte Character

typedef struct EFI_TABLE_HEADER
{
    UINT64 Signature;
    UINT32 Revision;
    UINT32 HeaderSize;
    UINT32 CRC32;
    UINT32 Reserved;
} EFI_TABLE_HEADER;

typedef unsigned short int  uint16_t;
typedef unsigned short int  uint_least16_t;
typedef uint_least16_t          CHAR16;

typedef unsigned int        UINT32;
typedef unsigned long long  UINT64;

typedef unsigned char       BOOLEAN;

typedef void                *EFI_HANDLE;
typedef UINT64              EFI_STATUS;

typedef UINT64 EFI_PHYSICAL_ADDRESS;


typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef EFI_STATUS (*EFI_TEXT_RESET)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, BOOLEAN ExtendedVerification);

typedef EFI_STATUS (*EFI_TEXT_STRING)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, CHAR16 *String);

typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
{
    EFI_TEXT_RESET      Reset;
    EFI_TEXT_STRING     OutputString;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef struct EFI_SYSTEM_TABLE
{
    EFI_TABLE_HEADER Hdr; //The table header for the EFI System Table
    CHAR16 *FirmwareVendor; //A pointer to a null terminated string that identifies the vendor that produces the system firmware for the platform.
    UINT32 FirmwareVersion; //A firmware vendor specific value that identifies the revision of the system firmware for the platform.
    EFI_HANDLE ConsoleInHandle; //The handle for the active console input device, if there is no active console, these protocols must still be present
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn; //A pointer to the EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL interface that is associated with ConsoleOutHandle.
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut; //A pointer to the EFI_SIMPLE_TEXT_INPUT_PROTOCOL interface that is associated with ConsoleInHandle.
} EFI_SYSTEM_TABLE;

//12.9 Graphics Output Protocol in UEFI specs 2.8B
typedef struct EFI_GRAPHICS_OUTPUT_PROTCOL { //GOP
    EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE QueryMode; //Returns information for an available graphics mode that the graphics device and the set of active video output devices supports.
    EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE SetMode; //Set the video device into the specified mode and clears the visible portions of the output display to black.
    EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT Blt; //Software abstraction to draw on the video device’s frame buffer
    EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE *Mode; //Pointer to EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE data.
} EFI_GRAPHICS_OUTPUT_PROTOCOL

EFI_GRAPHICS_OUTPUT_PROTOCOL* gop;

//Defining MODE INFORMATION
typedef struct{
    UINT32 Version; //The version of this data structure 
    UINT32 HorizontalResolution; //The size of video screen in pixels in the X dimension.
    UINT32 VerticalResolution; //The size of video screen in pixels in the Y dimension.
    EFI_GRAPHICS_PIXEL_FORMAT PixelFormat; //Enumeration that defines the physical format of the pixel
    EFI_PIXEL_BITMASK PixelInformation; //This bit-mask is only valid if PixelFormat is set to PixelPixelBitMask
    UINT32 PixelsPerScanLine; //Defines the number of pixel elements per video memory line
} EFI_GRAPHICS_OUTPUT_MODE_INFORMATION;

//Defining QUERY MODE
typedef EFI_STATUS (*EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE) (
 EFI_GRAPHICS_OUTPUT_PROTOCOL *This, //The EFI_GRAPHICS_OUTPUT_PROTOCOL instance. Type EFI_GRAPHICS_OUTPUT_PROTOCOL is defined in this section.
 UINT32 ModeNumber, //The mode number to return information on.
 UINTN *SizeOfInfo //A pointer to the size, in bytes, of the Info buffer. 
 EFI_GRAPHICS_OUTPUT_MODE_INFORMATION **Info //A pointer to a callee allocated buffer that returns information about ModeNumber.
 );

//bitmask is data that is used for bitwise operations, particularly in a bit field

//Defining SET MODE
 typedef EFI_STATUS(*EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE) (
    EFI_GRAPHICS_OUTPUT_PROTOCOL *This,
    UINT32 ModeNumber //Abstraction that defines the current video mode
 );

typedef struct{ 
    UINT8  Blue;
    UINT8  Green;
    UINT8  Red;
    UINT8  Reserved;
} EFI_GRAPHICS_OUTPUT_BLT_PIXEL;

 typedef enum { //Enumeration (enum) is a user defined datatype in C language
    EfiBltVideoFill, 
    EfiBltVideoToBltBuffer, 
    EfiBltBufferToVideo,  
    EfiBltVideoToVideo, 
    EfiGraphicsOutputBltOperationMax
} EFI_GRAPHICS_OUTPUT_BLT_OPERATION;

typedef EFI_STATUS(*EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT) (
    EFI_GRAPHICS_OUTPUT_PROTOCOL *This,
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL *BltBuffer, OPTIONAL //The data to transfer to the graphics screen. 
    EFI_GRAPHICS_OUTPUT_BLT_OPERATION BltOperation, //The operation to perform when copying BltBuffer on to the graphics screen.
    UINTN SourceX, //The X coordinate of the source for the BltOperation. The origin of the screen is 0, 0 and that is the upper left-hand corner of the screen.
    UINTN SourceY, //The Y coordinate of the source for the BltOperation. The origin of the screen is 0, 0 and that is the upper left-hand corner of the screen.
    UINTN DestinationX, //The X coordinate of the destination for the BltOperation
    UINTN DestinationY, //The Y coordinate of the destination for the BltOperation
    UINTN Width, //The width of a rectangle in the blt rectangle in pixels. Each pixel is represented by an EFI_GRAPHICS_OUTPUT_BLT_PIXEL element.
    UINTN Height, //The height of a rectangle in the blt rectangle in pixels. Each pixel is represented by an EFI_GRAPHICS_OUTPUT_BLT_PIXEL element.
    UINTN Delta OPTIONAL //Not used for EfiBltVideoFill or the EfiBltVideoToVideo operation. If a Delta of zero is used, the entire BltBuffer is being operated on.
);

typedef struct {  
    UINT32 MaxMode; //The number of modes supported by QueryMode() and SetMode()
    UINT32 Mode; //Current Mode of the graphics device. Valid mode numbers are 0 to MaxMode -1.
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION  *Info; //Pointer to read-only EFI_GRAPHICS_OUTPUT_MODE_INFORMATION data.
    UINTN SizeOfInfo; //Size of Info structure in bytes. Future versions of this specification may increase the size of the EFI_GRAPHICS_OUTPUT_MODE_INFORMATION data.
    EFI_PHYSICAL_ADDRESS FrameBufferBase; //Base address of graphics linear frame buffer
    UINTN FrameBufferSize; //Amount of frame buffer needed to support the active mode as defined by PixelsPerScanLine x VerticalResolution x PixelElementSize.
} EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE;
