#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("endian.c\n\n");
    
    printf("sizeof(char) = %u\n",sizeof(char));
    printf("sizeof(short) = %u\n\n",sizeof(short));
    
    short x = 1;
    
    short *w = &x; // w to wskaŸnik na short (word) 
    
    printf("*w = %d\n\n", *w);
    
    char *b = (char*)&x; // b to wskaŸnik na char (byte)
    
    // wskaŸniki w i b przechowuj¹ ten sam adres 
    
    printf("w = %p\n", *w);
    printf("b = %p\n\n", *b);
    
    // Test Architektury
    
    printf("*b = %d\n", *b);
    printf("*(b+1) = %d\n", *(b+1));

    /*
    - little endian

    w     w+1
    |     |        wskazniki na short (word)
    [1][0][m][s]
    |  |           wskazniki na char (byte)
    b  b+1

    w -> [1][0]  *w = 1

    b   -> [1]   *b     = 1
    b+1 -> [0]   *(b+1) = 0

    - big endian

    w     w+1
    |     |        wskazniki na short (word)
    [0][1][s][m]
    |  |           wskazniki na char (byte)
    b  b+1

    w -> [0][1]   *w = 1

    b   -> [0]    *b     = 0
    b+1 -> [1]    *(b+1) = 1
    */
    
    return 0;
}
