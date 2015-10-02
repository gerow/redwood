all:
	$(MAKE) -C cross
	$(MAKE) -C kern

clean:
	$(MAKE) -C cross clean
