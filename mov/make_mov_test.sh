#!/bin/bash
nasm -f bin -o mov_test.bin mov_test.asm
ndisasm -b 32 mov_test.bin
