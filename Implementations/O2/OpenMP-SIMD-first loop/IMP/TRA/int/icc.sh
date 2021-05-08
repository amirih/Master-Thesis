#!/bin/bash
source //opt/intel/compilers_and_libraries_2018/linux/bin/compilervars.sh -arch intel64
message="spliter"
compiler=icc
commonFlags="-D _GNU_SOURCE  -O2  -qopenmp -xHOST"
novecFlags="-no-vec"
pox=.c
echo
echo $message>>fileForSpeedups
echo "Time: $(date)">>fileForSpeedups
echo $compiler>>fileForSpeedups
echo $commonFlags>>fileForSpeedups
echo $novecFlags>>fileForSpeedups
echo "*****************************************ICC*****************************************"
file="IMP1"
echo
echo "Out put for $file scalar:"
$compiler $commonFlags $novecFlags   $file$pox -o $file$cmp && ./$file$cmp

