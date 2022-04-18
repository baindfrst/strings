section .text
global simetric_change
simetric_change:
    push ebp
    mov ebp, esp
    mov edx, dword[ebp + 8]
.cycle:
    cmp byte[edx], 0; проверка на конец строки
    je .end
    cmp byte[edx], 65; (char)65 - 'A'
    jb .pass
    cmp byte[edx], 90; (char)90 - 'Z'
    jg .pass
    mov eax, 155; что бы найти противоположный элемент, вычитаем из суммы минимального и мас=ксимального элемента нынешний
    sub eax, dword[edx]
    mov dword[edx], eax
    .pass:
    inc edx
    jmp .cycle
.end:
    leave
    ret
     