#include <stdio.h>

int main() {
    int a = 1, b = 2;
    int c, d;
    int e = 3, f;
    int g, h = 4;

    printf("&var1 [%p]   var1\n", (void*)&a);
    printf("&var2 [%p]   var2\n", (void*)&b);
    printf("&var3 [%p]   var3\n", (void*)&c);
    printf("&var4 [%p]   var4\n", (void*)&d);
    printf("\n");
    printf("&var5 [%p]   var5\n", (void*)&e);
    printf("&var6 [%p]   var6\n", (void*)&f);
    printf("&var7 [%p]   var7\n", (void*)&g);
    printf("&var8 [%p]   var8\n", (void*)&h);

    return 0;
}

