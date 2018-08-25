#!/bin/bash
gcc -Wl,--entry=func,--oformat=binary -nostdlib -fno-asynchronous-unwind-tables -o tmp.bin func.c
