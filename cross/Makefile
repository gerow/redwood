export PREFIX = $(abspath .)
export TARGET = i686-elf

all:
	$(MAKE) -C src
	$(MAKE) -C build

clean:
	$(MAKE) -C build clean
	$(MAKE) -C src clean
