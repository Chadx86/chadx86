[BITS 16]
jmp short start
nop
OEM_ID                db 		"QUASI-OS"
BytesPerSector        dw 		0x0200
SectorsPerCluster     db 		0x08
ReservedSectors       dw 		0x0020
TotalFATs             db 		0x02
MaxRootEntries        dw 		0x0000
NumberOfSectors       dw 		0x0000
MediaDescriptor       db 		0xF8
SectorsPerFAT         dw 		0x0000
SectorsPerTrack       dw 		0x003D
SectorsPerHead        dw 		0x0002
HiddenSectors         dd 		0x00000000
TotalSectors     	   dd 		0x00FE3B1F		
BigSectorsPerFAT      dd 		0x00000778
Flags                 dw 		0x0000
FSVersion             dw 		0x0000
RootDirectoryStart    dd 		0x00000002
FSInfoSector          dw 		0x0001
BackupBootSector      dw 		0x0006

start:
jmp $

TIMES 510-($-$$) DB 0
DW 0xAA55