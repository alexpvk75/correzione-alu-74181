/*
VERIFICA DI TPS 
Leonardo Galli 3C INF
28/04/2025


Costruire un simulatore C-codificato che implementi la seguente rete di calcolo (circuito) booleano 
ridondante (i.e. simmetrica rispetto all'asse sinistra-destra),
(immagine accessibile anche al seguente link
https://drive.google.com/file/d/11O3N-fYPoAqOCsXY7vGJyOp-_UY2FOPe/view?usp=sharing)
utilizzando gli analoghi algebrici C-codificati delle porte logiche elementari ed avendo cura di
testarne il funzionamento sulla base della relativa tavola di verità associabile alla
corrispondente espressione logica formale (i.e. funzione di commutazione).
Il codice, una volta eseguito, dovrà impedire l'immissione di valori di ingresso non logicamente
coerenti da parte dell'utente, restituendo ogni volta un messaggio di errore e replicando la
richiesta di immissione dei valori di ingresso fino ad un numero massimo di tentativi pari a 5.
Nel caso di 5 errori di immissione consecutivi, l'esecuzione del codice dovrà essere interrotta
con un relativo messaggio ulteriore all'utente circa il numero massimo di tentativi di immissione
raggiunto.
Nota - si rende necessario calcolare la funzione di commutazione del circuito logico rappresentato in figura, la quale andrà riportata nello spazio sottostante, unitamente al codice sorgente C del programma di simulazione

*/

#include <stdio.h>

// Porte logiche elementari utilizzate per lo svolgimento della traccia con le rispettive tavole della verità per il controllo e la simulazione
int porta_not(int a) { return 1 - a; }
/*
 a | 1 - a  |
 0 |    1   |
 1 |    0   |
*/

int porta_and(int a, int b) { return a * b; }
/*
 a | b | a * b |
 0 | 0 |   0   |
 0 | 1 |   0   |
 1 | 0 |   0   |
 1 | 1 |   1   |
*/

int porta_or(int a, int b) { return a + b - a * b; }
/*
 a | b | a + b - a * b |
 0 | 0 |       0       |
 0 | 1 |       1       |
 1 | 0 |       1       |
 1 | 1 |       1       |
*/

int porta_exor(int a, int b) { return a + b - 2 * a * b; }
/*
 a | b | a + b - 2 * a * b |
 0 | 0 |          0        |
 0 | 1 |          1        |
 1 | 0 |          1        |
 1 | 1 |          0        |
*/

int main() {
    int p, q, tentativi, x1, x2, y, z;

    for (tentativi = 0; tentativi < 5; tentativi++) {
        printf("Inserisci i valori di input:\n");
        printf("p: "); scanf("%d", &p);
        printf("q: "); scanf("%d", &q);

        if (p == 0) {
            if (q == 0) {
                x1 = porta_not(porta_exor(p, q));
                x2 = porta_or(x1, porta_and(x1, x1));
                y = x2;
                z = x2;
                printf("Risultati:\n");
                printf("y = %d\n", y);
                printf("z = %d\n", z);
                return 0;
            } else if (q == 1) {
                x1 = porta_not(porta_exor(p, q));
                x2 = porta_or(x1, porta_and(x1, x1));
                y = x2;
                z = x2;
                printf("Risultati:\n");
                printf("y = %d\n", y);
                printf("z = %d\n", z);
                return 0;
            } else {
                printf("Valori inseriti non validi\n");
            }
        } else if (p == 1) {
            if (q == 0) {
                x1 = porta_not(porta_exor(p, q));
                x2 = porta_or(x1, porta_and(x1, x1));
                y = x2;
                z = x2;
                printf("Risultati:\n");
                printf("y = %d\n", y);
                printf("z = %d\n", z);
                return 0;
            } else if (q == 1) {
                x1 = porta_not(porta_exor(p, q));
                x2 = porta_or(x1, porta_and(x1, x1));
                y = x2;
                z = x2;
                printf("Risultati:\n");
                printf("y = %d\n", y);
                printf("z = %d\n", z);
                return 0;
            } else {
                printf("Valori inseriti non validi\n");
            }
        } else {
            printf("Valori inseriti non validi\n");
        }
    }

    printf("Numero massimo di tentativi raggiunto. Il programma è stato terminato.\n");
    return 0;
}

/*
Tavola di verità della rete (non richiesta, inserita per verificare il funzionamento del codice):

 p | q | p + q - 2 * p * q | x1 = 1 - (...) | x1 * x1 | x2 = x1 + x1*x1 - x1*x1*x1 | y | z |
 0 | 0 |        0          |       1        |    1    |            1              | 1 | 1 |
 0 | 1 |        1          |       0        |    0    |            0              | 0 | 0 |
 1 | 0 |        1          |       0        |    0    |            0              | 0 | 0 |
 1 | 1 |        0          |       1        |    1    |            1              | 1 | 1 |
*/

/*

y = 1 - (p + q - 2 * a * b) + (1 - (p + q - 2 * a * b) * 1 - (p + q - 2 * a * b)) - 1 - (p + q - 2 * a * b) * (1 - (p + q - 2 * a * b) * 1 - (p + q - 2 * a * b))
z = 1 - (p + q - 2 * a * b) + (1 - (p + q - 2 * a * b) * 1 - (p + q - 2 * a * b)) - 1 - (p + q - 2 * a * b) * (1 - (p + q - 2 * a * b) * 1 - (p + q - 2 * a * b))

Semplificazione delle funzioni di commutazione:
y = z = 1 - (p + q - 2 * a * b) + (1 - (p + q - 2 * a * b) * 1 - (p + q - 2 * a * b)) - 1 - (p + q - 2 * a * b) * (1 - (p + q - 2 * a * b) * 1 - (p + q - 2 * a * b))
1 - (p + q - 2 * a * b) * 1 - (p + q - 2 * a * b) = 1 - (p + q - 2 * a * b) + (p + q - 2 * a * b)^2
y = z = 1 - (p + q - 2 * a * b) + 1 - (p + q - 2 * a * b) + (p + q - 2 * a * b)^2 - 1 - (p + q - 2 * a * b) * (1 - (p + q - 2 * a * b) + (p + q - 2 * a * b)^2)
y = z = - (p + q - 2 * a * b) + (p + q - 2 * a * b)^2 - (p + q - 2 * a * b) * (1 - (p + q - 2 * a * b) + (p + q - 2 * a * b)^2)
(p + q - 2 * a * b) * (1 - (p + q - 2 * a * b) + (p + q - 2 * a * b)^2) = (p + q - 2 * a * b) - (p + q - 2 * a * b)^2 + (p + q - 2 * a * b)^3
y = z = - (p + q - 2 * a * b) + (p + q - 2 * a * b)^2 - ((p + q - 2 * a * b) - (p + q - 2 * a * b)^2 + (p + q - 2 * a * b)^3)
y = z = - (p + q - 2 * a * b) + (p + q - 2 * a * b)^2 - (p + q - 2 * a * b) + (p + q - 2 * a * b)^2 - (p + q - 2 * a * b)^3
y = z = - 2(p + q - 2 * a * b) + 2(p + q - 2 * a * b)^2 - (p + q - 2 * a * b)^3

Dunque le funzioni di commutazione semplificata
y = - 2(p + q - 2 * a * b) + 2(p + q - 2 * a * b)^2 - (p + q - 2 * a * b)^3
z = - 2(p + q - 2 * a * b) + 2(p + q - 2 * a * b)^2 - (p + q - 2 * a * b)^3

*/
