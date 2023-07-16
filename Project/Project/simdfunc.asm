section .text
default rel
bits 64
global dotProduct_SIMD

dotProduct_SIMD:
   push     rbp
   mov      rbp, rsp
   sub      rsp, 8
   mov      r12, rdx
   mov      r13, r8
   xor      rax, rax
   xor      ecx, ecx
   mov      eax, ecx
   shr      eax, 4             
   vpxor    ymm2, ymm2, ymm2  

   dotProduct_loop:
        cmp      eax, 0
        jle      dotProduct_exit
        vmovdqu  ymm0, [r12]    
        vmovdqu  ymm1, [r13]    
        vpmulld  ymm0, ymm0, ymm1 
        vpaddd   ymm2, ymm2, ymm0 
        add      r12, 32         
        add      r13, 32        
        sub      eax, 1         
        jmp      dotProduct_loop

   dotProduct_exit:
        vextracti128 xmm0, ymm2, 1 
        vpaddq   xmm2, xmm2, xmm0  
        vpermilps xmm1, xmm2, 0xE  
        vpaddq   xmm2, xmm2, xmm1  
        movq     qword [rsp], xmm2  
        mov      rax, qword [rsp]   
        mov      qword [r9], rax    
        add      rsp, 8
        pop      rbp
        ret