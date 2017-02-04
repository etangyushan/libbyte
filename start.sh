#!/bin/sh
ulimit -c unlimited .

#库搜索路径设置
LIBPATH=/opt/libfpenv
export LD_LIBRARY_PATH=$LIBPATH/lib/:$LD_LIBRARY_PATH:tools/gperftools/lib/
export CPATH=$LIBPATH/include:$CPATH
export TESSDATA_PREFIX=$LIBPATH/share/tessdata

export HEAPCHECK=normal
export CPUPROFILE=./test.prof

time ./bytes
#valgrind --tool=memcheck --leak-check=full -v --track-origins=yes --trace-children=yes --show-possibly-lost=no ./bytes 

