section .text
bits 64
default rel
global dotProduct_SIMD

dotProduct_SIMD:
    mov r12, rdx
    mov r13, r8
    shr rcx, 0       ; Update the shift value to divide by 4 (number of elements in each iteration)
    xor rax, rax

dotProduct_loop:
    cmp rcx, 0
    jle dotProduct_exit
    vmovq xmm0, qword [r12]    ; Load 64 bits (1 element) from [r12] into xmm0
    vmovq xmm1, qword [r13]    ; Load 64 bits (1 element) from [r13] into xmm1
    vpmuludq xmm0, xmm0, xmm1  ; Multiply xmm0 and xmm1
    vpextrq r14, xmm0, 0       ; Extract the lower 64 bits (1 element) from xmm0 into r14
    add rax, r14               ; Add r14 to rax
    add r12, 8                ; Increment r12 by 8 (64 bits) to point to the next element in rdx
    add r13, 8                ; Increment r13 by 8 (64 bits) to point to the next element in r8
    dec rcx
    jnz dotProduct_loop

dotProduct_exit:
    mov [r9],rax
    ret
