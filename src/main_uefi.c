//Alot of the comments are from the UEFI Specs 2.9, some comments are added in

//UEFI Data Types
typedef unsigned short int uint16_t; //uint16 is UINT16 for uefi

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

typedef void *EFI_HANDLE; //A collection of related interfaces

//We are using void * since that is the type the uefi specs said it should be

typedef unsigned char BOOLEAN; //Logical Boolean. 1-byte value containing a 0 for FALSE or a 1 for TRUE. Other values are undefined.

typedef uint16_t CHAR16; //2-byte Character. Unless otherwise specified all characters and strings are stored in the UCS-2 encoding format as defined by Unicode 2.1 and ISO/IEC 10646 standards.

CHAR16 *Str; //Str is short for string

Str = L"Welcome to the Chadx86 bootloader! \n";

//We would call return 0 so it exits the efi application, I will add this soon
