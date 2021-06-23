mov al, 02h 
mov ah, 00h 
int 10h  

void ClearScreen()
{
    __asm
    {
    mov al, 02h 
    mov ah, 00h 
    int 10h   
    }
}