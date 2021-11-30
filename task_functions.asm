global someParameter(animal*)
global swap(animal*, animal*)
global heapify(container*, int, int)
global heapSort(container*)

SECTION .text

someParameter(animal*):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-24], rdi
        mov     DWORD PTR [rbp-4], 0
        mov     DWORD PTR [rbp-8], 0
        jmp     .L2
.L5:
        mov     rdx, QWORD PTR [rbp-24]
        mov     eax, DWORD PTR [rbp-8]
        cdqe
        movzx   eax, BYTE PTR [rdx+4+rax]
        test    al, al
        je      .L7
        mov     rdx, QWORD PTR [rbp-24]
        mov     eax, DWORD PTR [rbp-8]
        cdqe
        movzx   eax, BYTE PTR [rdx+4+rax]
        movsx   eax, al
        add     DWORD PTR [rbp-4], eax
        add     DWORD PTR [rbp-8], 1
.L2:
        cmp     DWORD PTR [rbp-8], 6
        jle     .L5
        jmp     .L4
.L7:
        nop
.L4:
        pxor    xmm0, xmm0
        cvtsi2sd        xmm0, DWORD PTR [rbp-4]
        mov     rax, QWORD PTR [rbp-24]
        mov     eax, DWORD PTR [rax+12]
        pxor    xmm1, xmm1
        cvtsi2sd        xmm1, eax
        divsd   xmm0, xmm1
        movq    rax, xmm0
        movq    xmm0, rax
        pop     rbp
        ret
swap(animal*, animal*):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-40], rdi
        mov     QWORD PTR [rbp-48], rsi
        mov     rcx, QWORD PTR [rbp-40]
        mov     rax, QWORD PTR [rcx]
        mov     rdx, QWORD PTR [rcx+8]
        mov     QWORD PTR [rbp-32], rax
        mov     QWORD PTR [rbp-24], rdx
        mov     eax, DWORD PTR [rcx+16]
        mov     DWORD PTR [rbp-16], eax
        mov     rcx, QWORD PTR [rbp-40]
        mov     rsi, QWORD PTR [rbp-48]
        mov     rax, QWORD PTR [rsi]
        mov     rdx, QWORD PTR [rsi+8]
        mov     QWORD PTR [rcx], rax
        mov     QWORD PTR [rcx+8], rdx
        mov     eax, DWORD PTR [rsi+16]
        mov     DWORD PTR [rcx+16], eax
        mov     rcx, QWORD PTR [rbp-48]
        mov     rax, QWORD PTR [rbp-32]
        mov     rdx, QWORD PTR [rbp-24]
        mov     QWORD PTR [rcx], rax
        mov     QWORD PTR [rcx+8], rdx
        mov     eax, DWORD PTR [rbp-16]
        mov     DWORD PTR [rcx+16], eax
        nop
        pop     rbp
        ret
heapify(container*, int, int):
        push    rbp
        mov     rbp, rsp
        push    rbx
        sub     rsp, 40
        mov     QWORD PTR [rbp-40], rdi
        mov     DWORD PTR [rbp-44], esi
        mov     DWORD PTR [rbp-48], edx
        mov     eax, DWORD PTR [rbp-48]
        mov     DWORD PTR [rbp-20], eax
        mov     eax, DWORD PTR [rbp-48]
        add     eax, eax
        add     eax, 1
        mov     DWORD PTR [rbp-24], eax
        mov     eax, DWORD PTR [rbp-48]
        add     eax, 1
        add     eax, eax
        mov     DWORD PTR [rbp-28], eax
        mov     eax, DWORD PTR [rbp-24]
        cmp     eax, DWORD PTR [rbp-44]
        jge     .L10
        mov     rax, QWORD PTR [rbp-40]
        mov     edx, DWORD PTR [rbp-24]
        movsx   rdx, edx
        mov     rax, QWORD PTR [rax+8+rdx*8]
        mov     rdi, rax
        call    someParameter(animal*)
        movq    rbx, xmm0
        mov     rax, QWORD PTR [rbp-40]
        mov     edx, DWORD PTR [rbp-20]
        movsx   rdx, edx
        mov     rax, QWORD PTR [rax+8+rdx*8]
        mov     rdi, rax
        call    someParameter(animal*)
        movq    xmm1, rbx
        comisd  xmm1, xmm0
        jbe     .L10
        mov     eax, 1
        jmp     .L12
.L10:
        mov     eax, 0
.L12:
        test    al, al
        je      .L13
        mov     eax, DWORD PTR [rbp-24]
        mov     DWORD PTR [rbp-20], eax
.L13:
        mov     eax, DWORD PTR [rbp-28]
        cmp     eax, DWORD PTR [rbp-44]
        jge     .L14
        mov     rax, QWORD PTR [rbp-40]
        mov     edx, DWORD PTR [rbp-28]
        movsx   rdx, edx
        mov     rax, QWORD PTR [rax+8+rdx*8]
        mov     rdi, rax
        call    someParameter(animal*)
        movq    rbx, xmm0
        mov     rax, QWORD PTR [rbp-40]
        mov     edx, DWORD PTR [rbp-20]
        movsx   rdx, edx
        mov     rax, QWORD PTR [rax+8+rdx*8]
        mov     rdi, rax
        call    someParameter(animal*)
        movq    xmm2, rbx
        comisd  xmm2, xmm0
        jbe     .L14
        mov     eax, 1
        jmp     .L16
.L14:
        mov     eax, 0
.L16:
        test    al, al
        je      .L17
        mov     eax, DWORD PTR [rbp-28]
        mov     DWORD PTR [rbp-20], eax
.L17:
        mov     eax, DWORD PTR [rbp-20]
        cmp     eax, DWORD PTR [rbp-48]
        je      .L21
        mov     rax, QWORD PTR [rbp-40]
        mov     edx, DWORD PTR [rbp-20]
        movsx   rdx, edx
        mov     rdx, QWORD PTR [rax+8+rdx*8]
        mov     rax, QWORD PTR [rbp-40]
        mov     ecx, DWORD PTR [rbp-48]
        movsx   rcx, ecx
        mov     rax, QWORD PTR [rax+8+rcx*8]
        mov     rsi, rdx
        mov     rdi, rax
        call    swap(animal*, animal*)
        mov     edx, DWORD PTR [rbp-20]
        mov     ecx, DWORD PTR [rbp-44]
        mov     rax, QWORD PTR [rbp-40]
        mov     esi, ecx
        mov     rdi, rax
        call    heapify(container*, int, int)
.L21:
        nop
        mov     rbx, QWORD PTR [rbp-8]
        leave
        ret
heapSort(container*):
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     QWORD PTR [rbp-24], rdi
        mov     rax, QWORD PTR [rbp-24]
        mov     eax, DWORD PTR [rax]
        mov     DWORD PTR [rbp-12], eax
        mov     eax, DWORD PTR [rbp-12]
        mov     edx, eax
        shr     edx, 31
        add     eax, edx
        sar     eax
        sub     eax, 1
        mov     DWORD PTR [rbp-4], eax
        jmp     .L23
.L24:
        mov     edx, DWORD PTR [rbp-4]
        mov     ecx, DWORD PTR [rbp-12]
        mov     rax, QWORD PTR [rbp-24]
        mov     esi, ecx
        mov     rdi, rax
        call    heapify(container*, int, int)
        sub     DWORD PTR [rbp-4], 1
.L23:
        cmp     DWORD PTR [rbp-4], 0
        jns     .L24
        mov     eax, DWORD PTR [rbp-12]
        sub     eax, 1
        mov     DWORD PTR [rbp-8], eax
        jmp     .L25
.L26:
        mov     rax, QWORD PTR [rbp-24]
        mov     edx, DWORD PTR [rbp-8]
        movsx   rdx, edx
        mov     rdx, QWORD PTR [rax+8+rdx*8]
        mov     rax, QWORD PTR [rbp-24]
        mov     rax, QWORD PTR [rax+8]
        mov     rsi, rdx
        mov     rdi, rax
        call    swap(animal*, animal*)
        mov     ecx, DWORD PTR [rbp-8]
        mov     rax, QWORD PTR [rbp-24]
        mov     edx, 0
        mov     esi, ecx
        mov     rdi, rax
        call    heapify(container*, int, int)
        sub     DWORD PTR [rbp-8], 1
.L25:
        cmp     DWORD PTR [rbp-8], 0
        jns     .L26
        nop
        nop
        leave
        ret