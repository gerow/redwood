TARGETS = ../bin/i686-elf-as

all: $(TARGETS)


../bin/i686-elf-as: ../src/binutils-2.25
	cd binutils-2.25 && ../../src/binutils-2.25/configure --target=$(TARGET) --prefix="$(PREFIX)" --with-sysroot --disable-nls --disable-werror
	cd binutils-2.25 && make
	cd binutils-2.25 && make install

clean:
	rm -rf ../bin ../i686-elf ../share
