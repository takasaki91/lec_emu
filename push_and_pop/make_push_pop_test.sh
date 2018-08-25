#!/bin/bash
nasm -f bin -o push_pop_test.bin push_pop_test.asm
ndisasm -b 32 push_pop_test.bin
