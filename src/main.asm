format PE64 dll EFI



stack 65536*2
entry EntryPoint

section '.text' code readable executable

include 'uefi_ini.asm'

align37Must 16

; RCX, RDX, R8 and R9
EntryPoint:

	
	call saveRegisters

	call init
	jc	 error

	;uefi_call_wrapper ConOut, OutputString, ConOut, BootString
	mov  rdx, BootStartString
	call Console.Write

	
	call DisableWatchdogTimer

	mov  rdx, PressAnyKey
	call Console.Write

	call Console.WaitForKey

	;mov rcx, 100
	;call halt

	
	call loadRegisters
	xor rax, rax
	RET

error:
	call loadRegisters
	mov rax, 0x8000000000000000

	RET

align37Must 16

halt:
	HLT
	loop halt
	RET

align37Must 512


include 'main_data.asm'
