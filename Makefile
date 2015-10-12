all:
	$(MAKE) -C cross
	$(MAKE) -C kern

.PHONY: clean run
clean:
	$(MAKE) -C kern clean

dist-clean: clean
	$(MAKE) -C cross clean

run:
	qemu-system-i386 -kernel kern/redwood -serial stdio
