#include <stdio.h>
#include <stdlib.h>

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
	
	if (n == 1) return seq1;
	if (n == 2) return seq2;
	
	int i;
	for (i = 1; i <= n-2; i++) {
		int seq0 = seq1;
		seq1 = seq2;
		seq2 = 2*seq0 + 0.5*seq1;
	}
	
	return seq2;
}
/*
- dokonaj analizy wywołania seq1(4)

* seq1(4) =
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
        seq2 = 0.5*seq1 + 2*seq0 = 8 i = 3

3 < 4   seq0 = 4
		seq1 = 8
		seq2 = 0.5*seq1 + 2*seq0 = 12 i = 4

4 <  4 	false

return seq2 = 12  

- narysuj graf obliczeń dla seq1(4)

seq(0)    seq(1)  seq(2)
            \    /   |
            seq(3)   |
               \     |
                seq(4)  
*/

/* 
Funkcja seq2 wylicza wartości ciągu {seqn} metodą programowania dynamicznego przy pomocy ramki dwuzębnej.

- ile razy należy przesunąć ramkę w prawo, aby wyznaczyć wartość n-tego wyrazu ciągu w funkcji seq2 dla n >= 2 ?
należy dokonać n-2 przejść

- dokonaj analizy wywołania seq2(4).
  seq0 = 3
  seq1 = 4
  
  i = 3
  seq2 = 2*seq0 + 0.5*seq1 = 8

  i = 4
  seq0 = 4
  seq1 = 8
  seq2 = 2*seq0 + 0.5*seq1 = 12

- narysuj graf obliczeń dla seq2(4).

seq(0)    seq(1)  seq(2)
            \    /   |
            seq(3)   |
               \     |
                seq(4)

- która funkcja ma mniejszą złożoność obliczeniową seq1 czy seq2 
Obie funkcje mają złożoność O(n), ponieważ każda iteracja pętli jest wykonywana n-2 razy. 
Jednakże w przypadku seq2 używamy tablicy do przechowywania wyników pośrednich, co może nieznacznie zwiększyć zużycie pamięci.
*/

int seq2(int n) {
	if (n == 1) return 3;
	if (n == 2) return 4;

	int seq0 = 3;
	int seq1 = 4;
	int seq2 = 0;

	for (int i = 3; i <= n; i++) {
		seq2 = 2*seq0 + 0.5*seq1;
		seq0 = seq1;
		seq1 = seq2;
	}

	return seq2;
}

int main() {
    printf("sequence.c\n\n");
    
    int n = 5;
    
    printf("seq1(%d) = %d\n", n, seq1(n));
    printf("seq2(%d) = %d\n", n, seq2(n));
    
    return 0;
}
