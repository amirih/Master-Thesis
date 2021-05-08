#!/bin/bash
DIM=128
echo "#define MAXD " $DIM > file.h
sh allresults-multi-core.sh

DIM=256
echo "#define MAXD " $DIM > file.h
sh allresults-multi-core.sh

DIM=512
echo "#define MAXD " $DIM > file.h
sh allresults-multi-core.sh

DIM=1024
echo "#define MAXD " $DIM > file.h
sh allresults-multi-core.sh
