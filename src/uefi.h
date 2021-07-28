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

tyoedef UINT64 EFI_STATUS;

typedef void *EFI_HANDLE; //A collection of related interfaces

//We are using void * since that is the type the uefi specs said it should be

typedef unsigned char BOOLEAN; //Logical Boolean. 1-byte value containing a 0 for FALSE or a 1 for TRUE. (just a regular boolean)

typedef uint16_t CHAR16; //2-byte Character

struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL; //Protocol interfaces for devices that support console style text displaying.

typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL //Output text
{
    EFI_TEXT_RESET Reset;
    EFI_TEXT_STRING OutputString;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef struct EFI_SYSTEM_TABLE
{
    EFI_TABLE_HEADER hrd;
    CHAR16 *FirmwareVendor;
    UINT32 FirmwareVersion;
    EFI_HANDLE ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn; //EFI_SIMPLE_TEXT_INPUT_PROTOCOL is similar to ConIn in c++
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut; //EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL is similar to ConOut in c++
  
} EFI_SYSTEM_TABLE ;
