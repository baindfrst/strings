section .text
global just_once

just_once:
    push ebp
    mov ebp, esp
    mov edx, dword[ebp + 8]; основной указатель, для прохода по всей строчке (1-ый)
    push esi
    mov esi, edx; дополнительный указатель на строчку, для того, что бы пройти по всей строчке в поиске на уникальность символа
    mov ch, 0; счетчик, котороый хранит данный, сколько символов назад встречался уникальный символ
.cycle:
    cmp byte[edx], 0; проверка на конец строки
    je .end
    .cycle_search:
        cmp esi, edx; если 2-ой указатель стоит на том же элементе, что и основной, то сразуже переходим к след. элементу
        jne .pass
        inc esi
        .pass:
        cmp byte[esi], 0; проверка на окончание строчки, по которой ищут
        je .end_search_once; выход, если 1-ый указатель указывает на уникальный элемент
        mov cl, byte[esi]
        cmp cl, byte[edx]; смотрим, совпадает ли нынешний символ с символом, на который смотрит указатель, пробегающий по всему массиву
        je .end_search_copy; если совпадает, выходим и увеличиваем расстояние до последнего уникального символа на 1
        inc esi;переход к следующиму символу
        jmp .cycle_search
    .end_search_copy:
    inc ch
    jmp .p
    .end_search_once:
    mov cl, byte[edx]
    movzx eax, ch
    sub edx, eax
    mov byte[edx], cl; стамив после последнего поставленного уникального элемента новый уникальный элемент
    add edx, eax
    .p:
    inc edx; переходим к следующему элементу
    mov esi, edx
    movzx eax, ch
    sub esi, eax; ставим 2-ой указатель после последнего уникального символа
    jmp .cycle
.end:
    mov cl, byte[edx]
    movzx eax, ch
    sub edx, eax
    mov byte[edx], cl; ставим после последнего уникального элемента символ конца строки
    leave
    ret
