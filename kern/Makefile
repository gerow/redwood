export CC = $(abspath ../cross/bin/i686-elf-gcc)
export AS = $(abspath ../cross/bin/i686-elf-as)
export LD = $(abspath ../cross/bin/i686-elf-ld)
export AR = $(abspath ../cross/bin/i686-elf-ar)
export RANLIB = $(abspath ../cross/bin/i686-elf-ranlib)

export CFLAGS  = -L$(abspath ../cross/lib)
export CFLAGS += -I$(abspath ../cross/include)

OBJS = start.o

all: redwood


%.o: %.s
	$(AS) $< -o $@

redwood: $(OBJS)
	$(CC) $(CFLAGS) -T linker.ld -o $@ -ffreestanding -O2 -nostdlib $^


clean:
	rm -f *.o
	rm -f redwood
