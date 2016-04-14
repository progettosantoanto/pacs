#!/bin/bash
make clean
make
./main -p parametersRN.pot
./main -p parametersL2.pot
./main -p parametersH1.pot