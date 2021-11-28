# chadx86
UEFI Bootloader for x86 and x64 systems

All of the x86 assembly was written by 0xol

Makefile written by InsaneMiner

The chadx86 logo, main_uefi.c, uefi.h created by PedroElFrijol

## Things being worked on
 - GOP and printing text to the screen
 - Boot a kernel with the bootloader

## Requirements to build chadx86
 - Nasm (legacy only)
 - Mingw-w64 C compiler
 - QEMU Virtual Machine
 - GNU Make
 - python 3
 - mtools
 
## Understanding of the UEFI
UEFI Specs 2.9: https://uefi.org/sites/default/files/resources/UEFI_Spec_2_9_2021_03_18.pdf

## UEFI Boot:
![chadx86 uefi](https://user-images.githubusercontent.com/45809332/143669314-b3d1fa26-9908-413e-895b-d79c93c3e97e.PNG)

## BIOS Boot:
![chadx86 bios](https://user-images.githubusercontent.com/45809332/143669321-18526921-350e-410b-8c57-51e9e721d7a2.PNG)
