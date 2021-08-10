#!/bin/bash

time make -j24
cd ../wasm/
HW_Data=~/projects/HomeworldSDL/wasm/ gdb ../Linux/src/homeworld
