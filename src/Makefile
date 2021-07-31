CFLAGS :=
CFLAGS += -target x86_64-unknown-windows -ffreestanding -fno-builtin -fshort-wchar -fwrapv -mno-red-zone -fno-delete-null-pointer-checks
CFLAGS += -I. -I../i
CFLAGS += -std=gnu2x -g -O2
CFLAGS += -Wall -Wextra -Werror -Wno-unused-parameter
LDFLAGS := -target x86_64-unknown-windows -nostdlib -Wl,-entry:efi_main -Wl,-subsystem:efi_application -fuse-ld=lld-link
O := 0.o
EFICC ?= clang
EFICCLD ?= $(EFICC)

default: bootx64.efi

bootx64.efi: $(O)
	$(EFICCLD) $(LDFLAGS) -o bootx64.efi $(O)

%.o: %.c
	$(EFICC) $(CFLAGS) -c -o 0.o 0.c

clean:
  rm -f bootx64.efi $(O)
