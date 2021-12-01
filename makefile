# makefile for task_functions.asm
task: main.c task_functions.o source/animal.c source/container.c source/utils.c
	gcc -g -o task main.c task_functions.o source/animal.c source/container.c source/utils.c -no-pie
task_functions.o: task_functions.asm
	nasm -f elf64 -g -F dwarf task_functions.asm -l task_functions.lst