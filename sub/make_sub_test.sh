#!/bin/bash
nasm -f bin -o sub_test.bin sub_test.asm
ndisasm -b 32 sub_test.bin
