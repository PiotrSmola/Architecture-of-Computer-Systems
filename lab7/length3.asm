        [bits 32]

;        esp -> [ret]  ; ret - adres powrotu do asmloader

n        equ -24561

         mov ecx, 0   ; ecx = 0

         mov ebp, 10  ; ebp = 10
         
;        edx:eax = 0:n

         mov eax, n   ; eax = n

         cmp eax, 0   ; eax - 0           ; ZF affected
         
         jl dziel

petla    mov edx, 0  ; edx = 0
         
         idiv ebp    ; eax = edx:eax / ebp
                     ; edx = edx:eax % ebp

;        div arg     ; eax = edx:eax / arg
                     ; edx = edx:eax % arg

                     ; eax - iloraz
                     ; edx - reszta

         inc ecx     ; ecx++
 
         cmp eax, 0  ; eax - 0           ; ZF affected
         jne petla   ; jump if not equal ; jump if ZF = 0

         push ecx

;        esp -> [ecx][ret]

         call getaddr  ; push on the stack the run time address of format and jump getaddr
format:
         db "length = %d", 0xA, 0
getaddr:

;        esp -> [format][ecx][ret]

         call [ebx+3*4] ; printf(format, ecx);
         add esp, 2*4   ; esp = esp + 8

;        esp -> [ret]

         push 0         ; esp -> [0][ret]
         call [ebx+0*4] ; exit(0);
 
dziel:
         imul eax, -1
         jmp petla

; asmloader API
;
; ESP wskazuje na prawidlowy stos
; argumenty funkcji wrzucamy na stos
; EBX zawiera pointer na tablice API
;
; call [ebx + NR_FUNKCJI*4] ; wywolanie funkcji API
;
; NR_FUNKCJI:
;
; 0 - exit
; 1 - putchar
; 2 - getchar
; 3 - printf
; 4 - scanf
;
; To co funkcja zwróci jest w EAX.
; Po wywolaniu funkcji sciagamy argumenty ze stosu.
;
; https://gynvael.coldwind.pl/?id=387