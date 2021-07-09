AS = fasm # assembler variable
BUILDDIR = ./build
SRCDIR = ./src

main: 
	@$(AS) $(SRCDIR)/main.asm $(BUILDDIR)/bootx64.efi # also equal to fasm src\main.asm build\bootx64.efi
