#!/bin/bash

make clean
echo 'QUESTION 3' \
    && echo 'Launching the simulation without using the array of number...' \
    && make run n=1 && time ./exe/monte_carlo <<< $'1000000\n10\nn\n'
        
echo 'QUESTION 4' \
    && echo 'Generation of 20 000 000 numbers & Launching the simulation using the array of number...' \
    && time (make run n=20000000 ; ./exe/monte_carlo <<< $'1000000\n10\ny\n')

echo 'QUESTION 5.1' \
    && echo 'Read 20000000 numbers on a file...' \
    && time ./exe/monte_carlo y 
echo 'QUESTION 5.2' \
    && echo 'Generate 20000000 numbers' \
    && time ./exe/monte_carlo n 

echo 'QUESTION 6.1' \
    && echo 'Launching the simulation without using the array of number...' \
    && time ./exe/monte_carlo <<< $'1000000000\n10\nn\n' 
echo 'QUESTION 6.2' \
    && echo 'Impossible to generate enough number.. Uncomment if you want to try' \
#     && make run n=20000000000 \
#     && echo 'Launching the simulation using the array of number...' \
#     && time ./exe/monte_carlo <<< $'1000000000\n10\ny\n'