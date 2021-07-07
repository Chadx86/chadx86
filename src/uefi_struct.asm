macro struct name
{
  virtual at 0
    name name
  end virtual
}

macro align37 size
{
	virtual
		align size
		a = $ - $$
	end virtual

	db a dup 37h
}

macro align37Must size
{
	db 37h
	align37 size
}

struc int8
{
  . db ?
}

struc int16
{
  align37 2
  . dw ?
}

struc int32
{
  align37 4
  . dd ?
}

struc int64
{
  align37 8
  . dq ?
}

struc intn
{
  align37 8
  . dq ?
}

struc dptr
{
  align37 8
  . dq ?
}

struc EFI_TABLE_HEADER
{
	.Signature    		int64
	.Revision     		int32
	.HeaderSize   		int32
	.CRC32        		int32
	.Reserved     		int32
}
struct EFI_TABLE_HEADER

EFI_SYSTEM_TABLE_SIGNATUREQ equ	5453595320494249h

struc EFI_SYSTEM_TABLE
{
	.Hdr		        	EFI_TABLE_HEADER
	.FirmwareVendor        	dptr
	.FirmwareRevision      	int32
	.ConsoleInHandle       	dptr
	.ConIn 	        		dptr
	.ConsoleOutHandle      	dptr
	.ConOut	        		dptr
	.StandardErrorHandle   	dptr
	.StdErr	        		dptr
	.RuntimeServices       	dptr
	.BootServices	        dptr
	.NumberOfTableEntries  	intn
	.ConfigurationTable    	dptr
}
struct EFI_SYSTEM_TABLE

struc SIMPLE_TEXT_OUTPUT_INTERFACE
{
	.Reset 	    			dptr
	.OutputString	    	dptr
	.TestString	    		dptr
	.QueryMode	    		dptr
	.SetMode	    		dptr
	.SetAttribute	    	dptr
	.ClearScreen	    	dptr
	.SetCursorPosition 		dptr
	.EnableCursor	    	dptr
	.Mode		    		dptr
}
struct SIMPLE_TEXT_OUTPUT_INTERFACE

struc SIMPLE_INPUT_INTERFACE
{
	.Reset				dptr
	.ReadKeyStroke		dptr
	.WaitForKey			dptr
}
struct SIMPLE_INPUT_INTERFACE


struc EFI_BOOT_SERVICES_TABLE
{
	.Hdr		       			EFI_TABLE_HEADER
	.RaisePriority				dptr
	.RestorePriority			dptr
	.AllocatePages				dptr
	.FreePages					dptr
	.GetMemoryMap				dptr
	.AllocatePool				dptr
	.FreePool					dptr
	.CreateEvent				dptr
	.SetTimer					dptr
	.WaitForEvent				dptr
	.SignalEvent				dptr
	.CloseEvent					dptr
	.CheckEvent					dptr
	.InstallProtocolInterface 	dptr
	.ReInstallProtocolInterface dptr
	.UnInstallProtocolInterface dptr
	.HandleProtocol				dptr
	.Void						dptr
	.RegisterProtocolNotify 	dptr
	.LocateHandle				dptr
	.LocateDevicePath			dptr
	.InstallConfigurationTable 	dptr
	.ImageLoad					dptr
	.ImageStart					dptr
	.Exit						dptr
	.ImageUnLoad				dptr
	.ExitBootServices			dptr
	.GetNextMonotonicCount		dptr
	.Stall						dptr
	.SetWatchdogTimer			dptr
	.ConnectController			dptr
	.DisConnectController		dptr
	.OpenProtocol				dptr
	.CloseProtocol				dptr
	.OpenProtocolInformation 	dptr
	.ProtocolsPerHandle			dptr
	.LocateHandleBuffer			dptr
	.LocateProtocol				dptr
	.InstallMultipleProtocolInterfaces dptr
	.UnInstallMultipleProtocolInterfaces dptr
	.CalculateCrc32				dptr
	.CopyMem					dptr
	.SetMem						dptr
}
struct EFI_BOOT_SERVICES_TABLE
