#include <stdio.h>

// Funkcja wyliczająca wartość wielomianu w sposób klasyczny
int polinomial(unsigned char *p, int n) {
    int result = 0;
    int i;
    for (i = 0; i < n; i++) {
        result += p[i] << (8 * i);
    }
    return result;
}

// Funkcja wyliczająca wartość wielomianu schematem Hornera
int horner(unsigned char *p, int n) {
    int result = 0;
    int i;
    for (i = n - 1; i >= 0; i--) {
        result = (result << 8) | p[i];
    }
    return result;
}

int main() {
    unsigned char number1[] = {0x00, 0x00, 0x01, 0x00}; // 4 bajty, liczba 256
    unsigned char number2[] = {0x00, 0x00, 0xFF};       // 3 bajty, liczba 255

    printf("number(0x0061FE94, 4) = %d\n", polinomial(number1, 4));
    printf("number(0x0061FE94, 4) = %d\n", horner(number1, 4));

    printf("number(0x0061FE94, 3) = %d\n", polinomial(number2, 3));
    printf("number(0x0061FE94, 3) = %d\n", horner(number2, 3));

    return 0;
}

