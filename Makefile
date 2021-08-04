CC = x86_64-w64-mingw32-gcc
AS = fasm
BUILDDIR=bin
SRCDIR=src_uefi
CFLAGS=-Wall  -Werror -fno-builtin -m64 -mabi=ms -nostdlib -ffreestanding -I$(SRCDIR)/include
LFLAGS=-Wall -Werror -m64 -fno-builtin -ffreestanding -mabi=ms -nostdlib -shared -Wl,-dll -Wl,--subsystem,10 -e efi_main
CFILES  = $(shell find $(SRCDIR) -name '*.c')
OBJ = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(CFILES))
ASMFILES  = $(shell find $(SRCDIR) -name '*.s')
OBJ  += $(patsubst $(SRCDIR)/%.s,$(BUILDDIR)/%.s.o,$(ASMFILES))


all: build

build: BOOTX64.EFI

BOOTX64.EFI: setupDirs $(OBJ)
	@echo [$(CC)][LINKING ALL]
	@$(CC) $(LFLAGS) $(OBJ) -o $@

setupDirs:
	@mkdir -p $(BUILDDIR)
	@cd $(SRCDIR) \
	&& dirs=$$(find -type d) \
	&& cd ../$(BUILDDIR) \
	&& mkdir -p $$dirs
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@echo "[$(CC)][$<]"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/%.s.o: $(SRCDIR)/%.s
	@echo [$(AS)][$<]
	@$(AS) $(ASFLAGS) $< -o $@

clean:
	@rm -rf $(BUILDDIR) *.EFI
