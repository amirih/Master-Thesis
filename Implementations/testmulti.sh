#!/bin/bash
DIM=128
echo "#define MAXD " $DIM > file.h
sh allresults-multi-core.sh
