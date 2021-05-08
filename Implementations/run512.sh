#!/bin/bash
DIM=512
echo "#define MAXD " $DIM > file.h
sh allresults-single-core.sh

DIM=$DIM*2
echo "#define MAXD " $DIM > file.h
sh allresults-single-core.sh
