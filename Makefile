#ENV VARIABLES
MAKEFLAGS += --no-print-directory
GPPPARAMS = -m32 -g -c -Iinclude -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings -fno-stack-protector -std=c++11 -Dsnprintf=snprintf -D_WIN32_WINNT=0x0501 -D_MSC_VER=1600 -Wno-write-strings
ASPARAMS = --32
LDPARAMS = -T

.PHONY: help

help:
	@echo "OPTIONS"
	@echo "help: list all available commands"
	@echo "clean: delete built files(this files can be regenrated by ninja or make)"
	@echo "compile: compile and generate all project files"
clean:
	@echo "--RM deleting generated objects"
	@rm	-f ./bin/*.o
	@echo "--RM deleting generated binariies"
	@rm	-f ./bin/*.bin
	@echo "--RM deleting generated iso"
	@rm	-f ./build/*.iso
compile:
	@echo "to list options run make help"
	@echo "generating objects"
	@make $(MAKEPARAMS) objects
objects: ./src/kernel.cpp ./bin/kernel.o
	@echo "[1/3]--GCC compiling $< generating $@"
	@gcc $(CPPPARAMS) -c ./src/kernel.cpp -o ./bin/kernel.o
