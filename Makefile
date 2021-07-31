#ENV VARIABLES
GPPPARAMS = -m32 -g -c -Iinclude -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings -fno-stack-protector -std=c++11 -Dsnprintf=snprintf -D_WIN32_WINNT=0x0501 -D_MSC_VER=1600
ASPARAMS = --32
LDPARAMS = -T

help:           ## Show this help.
	@fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##//'
.PHONY: clean
clean:
	@echo "--RM deleting generated objects"
	@rm	./bin/*.o
	@echo "--RM deleting generated binariies"
	@rm	./bin/*.bin
	@echo "--RM deleting generated iso"
	@rm	./build/*.iso
