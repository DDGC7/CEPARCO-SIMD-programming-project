section .text
Default rel 
bits 64
global dotProduct_ASM

dotProduct_ASM:
   push     rbp
   mov      rbp, rsp
   add      rbp, 16
   mov      r12,rdx
   mov      r13,r8
   xor      rax,rax

   dotProduct_loop:
        cmp     rcx,0  
        jle     dotProduct_exit
        mov     r14, qword[r12]
        mov     r15, qword[r13]
        imul    r14,r15
        add     rax,r14
        add     r12,8
        add     r13,8
        dec     rcx
        jmp     dotProduct_loop

   dotProduct_exit:
        mov     qword [r9],rax      
        pop     rbp                 
        ret                         
