#!/bin/bash
nasm -f bin -o add_test.bin add_test.asm
ndisasm -b 32 add_test.bin
