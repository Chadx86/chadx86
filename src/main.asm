format PE64 dll EFI ;the format required by uefi to be written in



stack 65536*2
entry EntryPoint ;tells uefi to load entry point

section '.text' code readable executable

include 'uefi_ini.asm'

align37Must 16

; RCX, RDX, R8 and R9
EntryPoint:

	
	call saveRegisters ;save register for later

	call init
	jc	 error ;shouldnt be executed unless uefi is badly written. like really really badly written

	;uefi_call_wrapper ConOut, OutputString, ConOut, BootString
	mov  rdx, BootStartString ; moves bootstartstring to rdx
	call Console.Write

	
	call DisableWatchdogTimer ;its in the name

	mov  rdx, PressAnyKey ;moves pressanykey from main_data.asm to rdx
	call Console.Write; and then writes it to screen

	call Console.WaitForKey ;chad then will wait for user input via the keyboard

	;mov rcx, 100
	;call halt

	
	call loadRegisters ;reloads the registers from earlier that we saved
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
