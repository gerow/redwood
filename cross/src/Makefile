SOURCES  = binutils-2.25
SOURCES += gcc-5.2.0

all: $(SOURCES)

gcc-5.2.0.tar.gz:
	wget http://www.netgull.com/gcc/releases/gcc-5.2.0/gcc-5.2.0.tar.gz

%: %.tar.gz
	tar xzvf $<

clean:
	rm -rf $(SOURCES)
