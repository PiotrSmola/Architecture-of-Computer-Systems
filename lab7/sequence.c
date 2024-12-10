#include<stdio.h>

/*

seq0 	seq1    seq2
|-------|-------|       
0   	1     	2   	3   	4   	5   	6    indeksy
3		3		4		8		12		22		??   wartości
    	|-------|-------|
      seq0    seq1    seq2

Przesunięcie ramki w prawo:

seq0 = seq1
seq1 = seq2
seq2 = seq1 + seq0

- ile razy należy przesunąć ramkę w prawo, aby wyznaczyć wartość n-tego wyrazu ciągu w funkcji seq dla n >= 3 ?
należy dokonać n-2 przejść

*/

int seq1(int n) {
	int seq1 = 3;
	int seq2 = 4;
	
	if (n==1) return seq1;
	if (n==2) return seq2;
	
	int i;
	for (i = 2; i < n; i++) {
		int seq0 = seq1;
        seq1 = seq2;
        seq2 = 0.5*seq1 + 2*seq0;
    }
    
    return seq2;
}

/*- dokonaj analizy wywołania seq1(4).

seq(4) =
seq0 = 3
seq1 = 3
seq2 = 4

4 == 0  false 
4 == 1  false
4 == 2  false

i
i = 2
2 < 4   seq0 = 3
         seq1 = 4
         seq2 = 0.5*seq1 + 2*seq0 = 8   i = 3

3 < 4   seq0 = 4
		 seq1 = 8
		 seq2 = 0.5*seq1 + 2*seq0 = 12 i = 4

4 <  4 	false

return seq2 = 12  

- narysuj graf obliczeń dla seq1(4).

          f(0)  f(1)    f(2)
                 \   /  |
                  f(3)  |
                     \  |
                      f(4)  

*/

int main() {
	
	printf("sequence = %d", seq1(4));
	
	return 0;
}
