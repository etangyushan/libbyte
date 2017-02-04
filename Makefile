#Makefile bytes
CC = gcc 
CFLAGS =-Wall -D_SVID_SOURCE -std=gnu99


TOOLS=/root/workdir/fileparserc/tools/gperftools
TOOLSLIB=-lprofiler -L$(TOOLS)/lib
#TOOLSLIB=-L$(TOOLS)/lib -ltcmalloc

LIBDIR=/opt/libfpenv
LIBS =  -lzlog  -L$(LIBDIR)/lib $(TOOLSLIB)
INCLUDE =  
OO=*.c


all:test

.PHONY : release  g1 debug test

release:
	$(CC) $(CFLAGS) -o release/bytes $(OO) $(INCLUDE) $(LIBS) 
	$(CC) $(CFLAGS) -shared  -fpic  -o release/libbytes.so $(OO) $(INCLUDE) $(LIBS)
	cp release/libbytes.so example -f
g1:
	$(CC) $(CFLAGS) -o g1/bytes $(OO) $(INCLUDE) $(LIBS)  -g1
	$(CC) $(CFLAGS) -shared  -fpic -o g1/libbytes.so $(OO) $(INCLUDE) $(LIBS)  -g1 
	cp g1/libbytes.so example -f
debug:
	$(CC) $(CFLAGS) -o debug/bytes $(OO) $(INCLUDE) $(LIBS)  -g
	$(CC) $(CFLAGS) -shared -fpic -o debug/libbytes.so $(OO) $(INCLUDE) $(LIBS)   -g
	cp debug/libbytes.so example -f
test:
	$(CC) $(CFLAGS)  -o bytes $(OO) $(INCLUDE) $(LIBS)  -g
#	$(CC) $(CFLAGS)  -shared -fpic -o libbytes.so $(OO) $(INCLUDE) $(LIBS)   -g
	#cp libbytes.so example -f


clean:
	rm -f bytes
	rm -f libbytes.so
#	rm -f release/libbytes.so
#	rm -f g1/libbytes.so
#	rm -f debug/libbytes.so
#	rm -f release/bytes
#	rm -f g1/bytes
#	rm -f debug/bytes
#	rm -f file_parser.log
#	mkdir -p release
#	mkdir -p debug 
#	mkdir -p g1 
	rm -f *.o 
	rm -f *.tmp
	rm -f *.txt
	rm -f child_* 
	rm -f vgcore*
	rm -f core.* 
	rm -f log/*
