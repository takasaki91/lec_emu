#!/bin/bash
nasm -f bin -o call_test.bin call_test.asm
ndisasm -b 32 call_test.bin
