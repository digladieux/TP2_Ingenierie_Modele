#!/bin/bash

make clean
echo 'QUESTION 3' \
    && make exe/generator \
    && ./exe/generator 1 \
    && make run \
    && echo 'Launching the simulation without using the array of number...' \
    && time ./exe/monte_carlo <<< $'1000000\n10\nn\n'
        
echo 'QUESTION 4' \
    && echo 'Generation of 20 000 000 numbers' \
    && ./exe/generator 20000000 \
    && make run \
    && echo 'Launching the simulation using the array of number...' \
    && time ./exe/monte_carlo <<< $'1000000\n10\ny\n'


echo 'QUESTION 5' \
    echo 'Read 20000000 numbers on a file...'
    && time ./exe/monte_carlo y \
    echo 'Generate 20000000 numbers'
    && time ./exe/monte_carlo n \

echo 'QUESTION 6' \
    && echo 'Launching the simulation without using the array of number...' \
    && time ./exe/monte_carlo <<< $'1000000000\n10\nn\n'
    && make exe/generator \
    && ./exe/generator 20000000000 \
    && make run \
    && echo 'Launching the simulation using the array of number...' \
    && time ./exe/monte_carlo <<< $'1000000000\n10\nn\n'