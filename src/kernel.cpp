void printf(char* str){
	unsigned short* videoMemory = (unsigned short*)0xb8000;

	for(int i = 0; str[i] != '\0'; ++i)
		videoMemory[i] = (videoMemory[i] & 0xFF0) | str[i];
}
void KernelMain(void* multiboot_structure, unsigned int magicnumber){
    printf("hell world!");

	while (1);
}