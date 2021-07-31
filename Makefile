#ENV VARIABLES
GPPPARAMS = -m32 -g -c -Iinclude -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings -fno-stack-protector -std=c++11 -Dsnprintf=snprintf -D_WIN32_WINNT=0x0501 -D_MSC_VER=1600
ASPARAMS = --32
LDPARAMS = -T

.PHONY: help

help:
	@echo "OPTIONS"
	@echo "help: list all available commands"
	@echo "clean: delete built files(this files can be regenrated by ninja or make)"
	@echo "compile: compile and generate all project files"
clean:
	if test -f "./bin/*.o"; then
		@echo "--RM deleting generated objects"
		@rm	./bin/*.o
	else
		@echo "--RM deleting generated binariies"
		@rm	./bin/*.bin
	fi
	@echo "--RM deleting generated iso"
	@rm	./build/*.iso
compile:
	@echo "to list options run make help"
	@echo "generating objects"
	@make objects
objects: ./src/kernel.cpp
	gcc $(CPPPARAMS) -c ./src/kernel.cpp -o ./bin/kernel.o
