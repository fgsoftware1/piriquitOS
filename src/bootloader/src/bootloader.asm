BITS 16

start:
	mov ax, 07C0h  
	add ax, 20h    
	mov ss, ax     
	mov sp, 4096   

	mov ax, 07C0h   
	mov ds, ax   

	mov si, message 

    mov al, 0x03    ;
    mov ah, 0       ;clear screen
    int 0x10        ;

	call print_msg
	cli             
	hlt         

data:
	message db 'bootloader loaded', 0

print_msg:
	mov ah, 0Eh     
	              
.printchar:
	lodsb           
	cmp al, 0
	je .done      
	int 10h         
	jmp .printchar  

.done:
	ret

times 510-($-$$) db 0 
dw 0xAA55	    