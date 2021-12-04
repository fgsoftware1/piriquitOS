include Makefile.inc

.PHONY: all clean kernel bootloader

all: kernel

clean:
	@$(ECHO) cleaning up
	@$(RM) build/bin/*.o \
				build/fgOS.iso \
				build/fgOS.flp \
				isodir/boot/kernel.bin

kernel: $(KERNELDIR)
	cd $(KERNELDIR) && $(MAKE) all
