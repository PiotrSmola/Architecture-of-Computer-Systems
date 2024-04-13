section .data
    format db "a = ", 0
    format2 db "%d", 0
    format3 db "a = %d", 0xA, 0

section .text
    global _start

_start:
    ; Wywo³anie funkcji printf z formatem "a = "
    push format
    call dword [ebx + 3 * 4]  ; printf(format)
    add esp, 4

    ; Zarezerwowanie miejsca na przechowywanie wartoœci zmiennej a
    sub esp, 4

    ; Wywo³anie funkcji scanf
    push esp
    push format2
    call dword [ebx + 4 * 4]  ; scanf(format2, &a)
    add esp, 8

    ; Wypisanie pobranej wartoœci za pomoc¹ printf
    push dword [esp]  ; Wartoœæ zmiennej a
    push format3
    call dword [ebx + 3 * 4]  ; printf(format3, a)
    add esp, 8

    ; Wywo³anie funkcji exit
    push 0
    call dword [ebx]
