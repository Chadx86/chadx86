org 0x7C00
bits 16


jmp start
nop

OEM_ID                db 		"MSDOS5.0"
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

TIMES 12 DB 0 ;jumping to next offset

DriveNumber           db 		0x00
ReservedByte          db   	0x00
Signature             db 		0x29
VolumeID              dd 		0xFFFFFFFF
VolumeLabel           db 		"CHADX  BOOT"
SystemID              db 		"FAT32   "

start:
	mov ah, 0x0e ;change to tty mode
	mov al, 'C' ;int 0x10 looks in al for character to print
	int 0x10 ;call int 0x10 to load character to screen
	mov al, 'H'
	int 0x10
	mov al, 'A'
	int 0x10
	mov al, 'D'
	int 0x10
	mov al, 'X'
	int 0x10
	mov al, '8'
	int 0x10
	mov al, '6'
	int 0x10
	mov al, '-'
	int 0x10
	mov al, 'L'
	int 0x10
	mov al, 'E'
	int 0x10
	mov al, 'G'
	int 0x10
	mov al, 'A'
	int 0x10
	mov al, 'C'
	int 0x10
	mov al, 'Y'
	int 0x/10
	jmp $ ;infinite loop


times 510-($-$$) db 0
db 0x55, 0xAA		;; BIOS bootcode