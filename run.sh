#!/bin/sh
ulimit -c unlimited .
make clean
make
LIBPATH=/opt/libfpenv

export LD_LIBRARY_PATH=$LIBPATH/lib/:$LD_LIBRARY_PATH:tools/gperftools/lib/
export CPATH=$LIBPATH/include:$CPATH
export TESSDATA_PREFIX=$LIBPATH/share/tessdata

#export HEAPCHECK=normal
#export CPUPROFILE=./test.prof


#time ./bytes

env CPUPROFILE=./test.prof ./bytes
 
#valgrind --tool=memcheck --leak-check=full -v --track-origins=yes --trace-children=yes --show-possibly-lost=no ./bytes
