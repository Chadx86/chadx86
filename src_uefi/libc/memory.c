#include "../include/efi.h"
#include "memory.h"

void malloc(void**buffer,UINT32 sz){
    SystemTable->BootServices->AllocatePool(2, sz, buffer); 
}
void free(void**buffer){
    SystemTable->BootServices->FreePool(buffer);
}