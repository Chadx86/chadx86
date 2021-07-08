
AS=fasm
BUILDDIR=./build
SRCDIR=./src

all: main


main:
	$(AS) $(SRCDIR)/main.asm $(BUILDDIR)/bootx64.efi
