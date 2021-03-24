x86_64_asm_source_files := $(shell find bootloader -name *.asm)
x86_64_asm_source_files := $(shell find kernel -name *.asm)
x86_64_asm_object_files := $(patsubst bootloader/bin -name *.o, $(x86_64_asm_source_files))
x86_64_asm_object_files := $(patsubst kernel/bin/%.o, $(x86_64_asm_source_files))

$(x86_64_asm_object_files): build/x86_64/%.o : bootloadr/%.asm
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst bootloader/bin/%.o, bootloader/%.asm, $@) -o $@
	nasm -f elf64 $(patsubst kernel/bin/%.o, kernel/%.asm, $@) -o $@

.PHONY: build-x86_64
build-x86_64: $(x86_64_asm_object_files)
	mkdir -p dist/x86_64 && \
	x86_64-elf-ld -n -o dist/x86_64/kernel.bin -T kernel/linker.ld $(x86_64_asm_object_files) && \
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin && \
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/kernel.iso targets/x86_64/iso