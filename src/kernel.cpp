void printf(char* str){
	unsigned short* videoMemory = (unsigned short*)0xb8000;

	for(int i = 0; str[i] != '\0'; ++i)
		videoMemory[i] = (videoMemory[i] & 0xFF0) | str[i];
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;

extern "C" void KernelMain(void* multiboot_structure, unsigned int){
    printf("hell world!");

	while (1);
}