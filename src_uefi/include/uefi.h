//Alot of the comments are from the UEFI Specs 2.9, some comments are added in
//UEFI Specs is the reference I used for the code (PedroElFrijol)

#define EFI_SUCCESS 0; //Also similar to Return 0, you could use that if you'd like
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
