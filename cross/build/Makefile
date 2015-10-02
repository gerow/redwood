TARGETS  = ../bin/i686-elf-as
TARGETS += ../bin/i686-elf-gcc

all: $(TARGETS)


../bin/i686-elf-as: ../src/binutils-2.25
	cd binutils-2.25 && ../../src/binutils-2.25/configure --target=$(TARGET) --prefix="$(PREFIX)" --with-sysroot --disable-nls --disable-werror
	cd binutils-2.25 && make
	cd binutils-2.25 && make install

../bin/i686-elf-gcc:  ../src/gcc-5.2.0
	cd gcc-5.2.0 && ../../src/gcc-5.2.0/configure --target=$(TARGET) --prefix="$(PREFIX)" --disable-nls --enable-languages=c --without-headers
	cd gcc-5.2.0 && make all-gcc
	cd gcc-5.2.0 && make all-target-libgcc
	cd gcc-5.2.0 && make install-gcc
	cd gcc-5.2.0 && make install-target-libgcc

clean:
	rm -rf ../bin ../i686-elf ../share ../include ../libexec
