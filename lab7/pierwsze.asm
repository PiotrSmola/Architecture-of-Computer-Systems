        [bits 32]

        ; 1. wypisz "n = "
        ; 2. pobierz od uzytkownika liczbe n
        ; 3. jesli n = 0 wypisz "0 ma nieskonczenie wiele dzielnikow"
        ; 4. jesli n < 0 zamien n na dodatnia, n = n * -1
        ; 5. wypisz "liczby pierwsze: " bo kazda liczba dzieli sie przez 1
        ; 6. oblicz liczby pierwsze i wypisuj je na ekran
        ; 7. zakoncz program

        ; esp -> [ret] ; ret - adres powrotu do asmloader

        call getaddr
format:
        db "n = ", 0

getaddr:
        ; esp -> [format][ret]

        call [ebx+3*4] ; printf(format);

        ; esp -> [n][ret]

        push esp ; esp -> stack

        ; esp -> [addr_n][n][ret]

        call getaddr1
format1:
        db "%d", 0

getaddr1:
        ; esp -> [format1][addr_n][ret]

        call [ebx+4*4] ; scanf(format1, addr_n);
        add esp, 2*4 ; esp = esp + 8

        ; esp -> [ret]

        pop eax ; eax <- stack
        cmp eax, 0 ; eax - 0 ; OF SF ZF AF PF CF affected
        jne not_zero ; end program if 0

        call getaddr2
format2:
        db "0 ma nieskonczenie wiele dzielnikow", 0

getaddr2:
        call [ebx+3*4] ; printf(format2);
        add esp, 1*4 ; esp = esp + 8
        jmp end

not_zero:
        jge skip_sign_change ; jump if greater or equal ; ZF = 0

        mov ecx, -1 ; ecx = -1
        imul ecx ; edx:eax = edx:eax * -1

skip_sign_change:
        mov ebp, eax ; ebp = eax = n

        call getaddr3
format3:
        db "liczby pierwsze: ", 0

getaddr3:
        ; esp -> [format3][ret]

        call [ebx+3*4] ; printf(format3);
        add esp, 1*4 ; esp = esp + 8

        ; esp -> [ret]

        mov ecx, 2 ; ecx = 2

calc_primes:
        push ecx ; ecx -> stack

        cmp ecx, ebp ; eax - ebp ; OF SF ZF AF PF CF affected
        jg end ; end program if ecx > n

        mov eax, ecx ; eax = ecx = current number to check
        xor edx, edx ; edx = 0 = divisor

check_divisor:
        inc edx ; increment divisor

        cmp edx, eax ; compare divisor with current number
        jg prime ; jump if divisor > current number

        mov ebx, eax ; ebx = eax = current number
        xor edx, edx ; edx = 0 = remainder

        div edx ; eax = current number / divisor
                 ; edx = current number % divisor

        cmp edx, 0 ; edx - 0 ; OF SF ZF AF PF CF affected
        jne not_prime ; jump if remainder != 0

        jmp end_divisor_check

not_prime:
        pop edx ; edx <- stack
        inc ecx ; increment current number
        jmp calc_primes

prime:
        push eax ; eax -> stack

        call getaddr4
format4:
        db "%d ", 0

getaddr4:
        ; esp -> [format4][current_number][ret]

        call [ebx+3*4] ; printf(format4, current_number);
        add esp, 2*4 ; esp = esp + 8

end_divisor_check:
        pop edx ; edx <- stack
        inc ecx ; increment current number
        jmp calc_primes

end:
        push 0 ; esp -> [0][ret]
        call [ebx+0*4] ; exit(0);

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
