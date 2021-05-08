#!/bin/bash
cd "IMP"
echo $PWD
sh allresults.sh
cd ..

cd "O2/OpenMP-SIMD-first loop/IMP"
echo $PWD
sh allresults.sh
cd ..
cd ..

cd "OpenMP-SIMD-inner loop/IMP"
echo $PWD
sh allresults.sh
cd ..
cd ..
cd ..

cd "OpenMP-SIMD-first loop/IMP"
echo $PWD
sh allresults.sh
cd ..
cd ..

cd "OpenMP-SIMD-inner loop/IMP"
echo $PWD
sh allresults.sh
cd ..
cd ..
