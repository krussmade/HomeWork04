# makefile for perimeter.asm
task: main.cpp task_functions.o source/animal.cpp source/container.cpp source/utils.cpp
	gcc -g -o task main.cpp task_functions.o source/animal.cpp source/container.cpp source/utils.cpp -no-pie
task_functions.o: task_functions.asm
	nasm -f elf64 -g -F dwarf task_functions.asm -l task_functions.lst