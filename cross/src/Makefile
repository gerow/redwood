SOURCES  = binutils-2.25
SOURCES += gcc-5.2.0

all: $(SOURCES)


%: %.tar.gz
	tar xzvf $<

clean:
	rm -rf $(SOURCES)
