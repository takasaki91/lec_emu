#!/bin/bash
nasm -f bin -o inc_test.bin inc_test.asm
ndisasm -b 32 inc_test.bin
