section '.data' data readable writeable

align37 64

; ImageHandle
efi_handler		dq			0
align37Must 16

; pointer to SystemTable			EFI_SYSTEM_TABLE
efi_ptr			dq			0
align37Must 16

BootServices	dq			0
align37Must 16

efi_rsp			dq			0


align37Must 16

BootStartString du 'Chadx86 test', 13, 10, 0

align37Must 16
error_WaitForKey_message du 'Wait for key event is null', 13, 10, 0

align37Must 16
PressAnyKey du 'Press any key to continue...', 13, 10, 0

align37Must 4096
