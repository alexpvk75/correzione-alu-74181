/*
 .d888888  dP        dP     dP             d88888P dP   dP d88  .d888b. d88  
d8'    88  88        88     88                 d8' 88   88  88  Y8' `8P  88  
88aaaaa88a 88        88     88                d8'  88aaa88  88  d8bad8b  88  
88     88  88        88     88               d8'        88  88  88` `88  88  
88     88  88        Y8.   .8P              d8'         88  88  8b. .88  88  
88     88  88888888P `Y88888P'             d8'          dP d88P Y88888P d88P                                                                                                                                                      
*/
/*
 ╔══════════════════════════════════════════════════════════════════════════════╗
 ║                                ⇨ ALU 74181 ⇦                                 ║
 ╠══════════════════════════════════════════════════════════════════════════════╣
 ║                                                                              ║
 ║ Codice sviluppato come progetto finale per TPS                               ║
 ║ Sviluppato da:                                                               ║
 ║  • Leonardo Galli                                                            ║
 ║  • Danilo Ambrogio Brusa                                                     ║
 ║  • Oleksandr Pavlyk                                                          ║
 ║  • Angelo Feng                                                               ║
 ║  • Davide (Ling) Yu                                                          ║
 ║                                                                              ║
 ╠══════════════════════════════════════════════════════════════════════════════╣
 ║                              ⇨ DESCRIZIONE ⇦                                 ║
 ╠══════════════════════════════════════════════════════════════════════════════╣
 ║                                                                              ║
 ║ Il 74181 è una rivoluzionaria unità logica aritmetica (ALU) a slice di       ║
 ║ 4 bit, introdotta originariamente da Texas Instruments nel 1970              ║
 ║ È storicamente significativa in quanto:                                      ║
 ║  • La prima ALU completa su un singolo chip                                  ║
 ║  • Una pietra miliare nella transizione dai processori a porte logiche       ║
 ║    discrete (anni '60) ai microprocessori su singolo chip (anni '70)         ║
 ║ Anche se non è più utilizzata commercialmente, rimane uno strumento          ║
 ║ fondamentale per l'insegnamento dell'architettura dei computer               ║
 ║                                                                              ║
 ╠══════════════════════════════════════════════════════════════════════════════╣
 ║                              ⇨ SCOPO CODICE ⇦                                ║
 ╠══════════════════════════════════════════════════════════════════════════════╣
 ║                                                                              ║
 ║  • Simulazione completa dell'ALU 74181 in linguaggio C                       ║
 ║  • La simulazione copre:                                                     ║
 ║    • Operazioni aritmetiche: addizione, sottrazione, ecc.                    ║
 ║    • Operazioni logiche: AND, OR, EXOR.                                      ║
 ║    • Shift di bit: shift a sinistra e a destra                               ║
 ║                                                                              ║
 ╚══════════════════════════════════════════════════════════════════════════════╝
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
/*
 ╔══════════════════════════════════════════════════════════════════════════════╗
 ║                               ⇨ CONVERSIONI ⇦                                ║
 ╠══════════════════════════════════════════════════════════════════════════════╣
 ║                                                                              ║
 ║  Queste funzioni servono a convertire numeri:                                ║
 ║                                                                              ║
 ║  • binario_a_decimale:                                                       ║
 ║      Converte un numero formato da cifre binarie (0 e 1)                     ║
 ║      in un numero decimale.                                                  ║
 ║                                                                              ║
 ║  • decimale_a_binario:                                                       ║
 ║      Converte un numero decimale in una rappresentazione                     ║
 ║      binaria (sequenza di bit rappresentata come intero).                    ║
 ║                                                                              ║
 ╚══════════════════════════════════════════════════════════════════════════════╝
 */
int binario_a_decimale(int bin) {
    int dec = 0, base = 1, resto;
    while (bin > 0) {
        resto = bin % 10;
        bin = bin / 10;
        dec += resto * base;
        base *= 2;
    }
    sleep(10);
    return dec;
}
int decimale_a_binario(int dec) {
    int bin = 0, base = 1, resto;
    while (dec > 0) {
        resto = dec % 2;
        dec = dec / 2;
        bin += resto * base;
        base *= 10;
    }
    sleep(10);
    return bin;
}
/*
 ╔══════════════════════════════════════════════════════════════════════════════╗
 ║                                ⇨ MEMORIA ⇦                                   ║
 ╠══════════════════════════════════════════════════════════════════════════════╣
 ║                                                                              ║
 ║ Queste variabili e funzioni gestiscono la "memoria"                          ║
 ║ in cui salvare i risultati:                                                  ║
 ║                                                                              ║
 ║  • memoria: array globale per contenere fino a 10 valori.                    ║
 ║  • indice_memoria: indice per inserire un nuovo valore.                      ║
 ║                                                                              ║
 ║ Le funzioni:                                                                 ║
 ║  • salva_in_memoria: salva un nuovo risultato, se c'è                        ║
 ║    spazio disponibile.                                                       ║
 ║  • stampa_memoria: mostra a video tutti i risultati.                         ║
 ║                                                                              ║
 ╚══════════════════════════════════════════════════════════════════════════════╝
 */
int memoria[10];
int indice_memoria = 0;
void salva_in_memoria(int valore) {
    if (indice_memoria < 10) {
        memoria[indice_memoria++] = valore;
    } else {
        printf("[!] Memoria piena!\n");
    }
    sleep(10);
}
void attendi_un_ciclo_clock() {
    clock_t start_time = clock();
    clock_t current_time;
    do {
        current_time = clock();
    } while ((current_time - start_time) < CLOCKS_PER_SEC / 1000);
    sleep(10);
}
void stampa_memoria() {
    printf("Contenuto della memoria:\n");
    for (int i = 0; i < indice_memoria; i++) {
        printf("Memoria[%d] = %-3d\n", i, memoria[i]);
    }
    sleep(10);
}
/*
 ╔══════════════════════════════════════════════════════════════════════════════╗
 ║                            ⇨ PORTE LOGICHE ⇦                                 ║
 ╠══════════════════════════════════════════════════════════════════════════════╣
 ║                                                                              ║
 ║  Queste funzioni simulano le porte logiche fondamentali usate nell'ALU:      ║
 ║                                                                              ║
 ║  • porta_not: inverte il segnale (0 diventa 1, 1 diventa 0).                 ║
 ║  • porta_and: esegue l'AND sui due input.                                    ║
 ║  • porta_or: esegue l'OR sui due input.                                      ║
 ║  • porta_exor: esegue l'operazione XOR (somma modulo 2).                     ║
 ║                                                                              ║
 ║  Sono inoltre definite versioni che combinano 3, 4 o 5 ingressi              ║
 ║  (es. porta_or_3, porta_and_4, ecc.) per semplificare operazioni logiche.    ║
 ║                                                                              ║
 ╚══════════════════════════════════════════════════════════════════════════════╝
 */
// Porta logica NOT
int porta_not(int a) { 
    return 1 - a; 
}
// Porta logica AND
int porta_and(int a, int b) { 
    return a * b; 
}
// Porta logica OR
int porta_or(int a, int b) { 
    return (a + b) - (a * b); 
}
// Porta logica EXOR
int porta_exor(int a, int b) { 
    return (a + b) - 2 * (a * b); 
}

int porta_or_3(int a, int b, int c) { 
    int tmp = porta_or(a, b); 
    return porta_or(tmp, c); 
}
int porta_or_4(int a, int b, int c, int d) { 
    int tmp1 = porta_or(a, b);
    int tmp2 = porta_or(c, d);
    return porta_or(tmp1, tmp2);
}
int porta_or_5(int a, int b, int c, int d, int e) { 
    int tmp = porta_or_4(a, b, c, d);
    return porta_or(tmp, e);
}
int porta_and_3(int a, int b, int c) { 
    int tmp = porta_and(a, b);
    return porta_and(tmp, c);
}
int porta_and_4(int a, int b, int c, int d) { 
    int tmp = porta_and(a, b);
    int tmp2 = porta_and(c, d);
    return porta_and(tmp, tmp2);
}
int porta_and_5(int a, int b, int c, int d, int e) {
    int tmp = porta_and_3(a, b, c);
    tmp = porta_and(tmp, d);
    return porta_and(tmp, e);
}
int porta_exor_3(int a, int b, int c) { 
    int tmp = porta_exor(a, b);
    return porta_exor(tmp, c);
}
int porta_exor_4(int a, int b, int c, int d) { 
    int tmp = porta_exor(a, b);
    int tmp2 = porta_exor(c, d);
    return porta_exor(tmp, tmp2);
}
int porta_exor_5(int a, int b, int c, int d, int e) { 
    int tmp = porta_exor_4(a, b, c, d);
    return porta_exor(tmp, e);
}
/*
 ╔══════════════════════════════════════════════════════════════════════════════╗
 ║                   ⇨ FUNZIONE ALU 74181 PER UN NIBBLE ⇦                       ║
 ╠══════════════════════════════════════════════════════════════════════════════╣
 ║                                                                              ║
 ║  Questa funzione simula il funzionamento di una ALU 74181 su 4 bit (nibble). ║
 ║                                                                              ║
 ║  Parametri:                                                                  ║
 ║    • Cn       : Carry in iniziale.                                           ║
 ║    • M        : Modalità (logica o aritmetica).                              ║
 ║    • A[4]     : Array dei 4 bit dell’operando A (bit 0 = LSB, bit 3 = MSB).  ║
 ║    • B[4]     : Array dei 4 bit dell’operando B.                             ║
 ║    • S[4]     : Array dei segnali di selezione dell’operazione.              ║
 ║                                                                              ║
 ║  Output:                                                                     ║
 ║    • F[4]     : Array con i 4 bit del risultato.                             ║
 ║    • A_uguale_B, P, Cn_piu_4, G: Flag derivati dalla logica interna ALU.     ║
 ║                                                                              ║
 ║  La funzione riproduce i calcoli logici usando porte AND, OR, NOT ed XOR.    ║
 ║                                                                              ║
 ╚══════════════════════════════════════════════════════════════════════════════╝
 */
void alu_74181_calcola(int Cn, int M, int A[4], int B[4], int S[4],
                         int F[4], int *A_uguale_B, int *P, int *Cn_piu_4, int *G) {
    int neg1 = porta_not(M);
    int neg2 = porta_not(B[0]);
    int neg3 = porta_not(B[1]);
    int neg4 = porta_not(B[2]);
    int neg5 = porta_not(B[3]);
    int and1 = porta_and(B[0], S[0]);
    int and2 = porta_and(S[1], neg2);
    int and3 = porta_and_3(neg2, S[2], A[0]);
    int and4 = porta_and_3(A[0], B[0], S[3]);
    int and5 = porta_and(B[1], S[0]);
    int and6 = porta_and(S[1], neg3);
    int and7 = porta_and_3(neg3, S[2], A[1]);
    int and8 = porta_and_3(A[1], S[3], B[1]);
    int and9 = porta_and(B[2], S[0]);
    int and10 = porta_and(S[1], neg4);
    int and11 = porta_and_3(neg4, S[2], A[2]);
    int and12 = porta_and_3(A[2], S[3], B[2]);
    int and13 = porta_and(B[3], S[0]);
    int and14 = porta_and(S[1], neg5);
    int and15 = porta_and_3(neg5, S[2], A[3]);
    int and16 = porta_and_3(A[3], S[3], B[3]);
    int nor1 = porta_not(porta_or_3(A[0], and1, and2));
    int nor2 = porta_not(porta_or(and3, and4));
    int nor3 = porta_not(porta_or_3(A[1], and5, and6));
    int nor4 = porta_not(porta_or(and7, and8));
    int nor5 = porta_not(porta_or_3(A[2], and9, and10));
    int nor6 = porta_not(porta_or(and11, and12));
    int nor7 = porta_not(porta_or_3(A[3], and13, and14));
    int nor8 = porta_not(porta_or(and15, and16));
    int nand01 = porta_not(porta_and(Cn, neg1));
    int neg01 = porta_not(nor1);
    int and01 = porta_and(neg1, nor1);
    int and02 = porta_and_3(neg1, nor2, Cn);
    int neg02 = porta_not(nor3);
    int and03 = porta_and(neg1, nor3);
    int and04 = porta_and_3(neg1, nor1, nor4);
    int and05 = porta_and_4(neg1, Cn, nor2, nor4);
    int neg03 = porta_not(nor5);
    int and06 = porta_and(neg1, nor5);
    int and07 = porta_and_3(neg1, nor3, nor6);
    int and08 = porta_and_4(neg1, nor1, nor4, nor6);
    int and09 = porta_and_5(neg1, Cn, nor2, nor4, nor6);
    int neg04 = porta_not(nor7);
    int nand02 = porta_not(porta_and_4(nor2, nor4, nor6, nor8));
    int nand03 = porta_not(porta_and_5(Cn, nor2, nor4, nor6, nor8));
    int and010 = porta_and_4(nor1, nor4, nor6, nor8);
    int and011 = porta_and_3(nor3, nor6, nor8);
    int and012 = porta_and(nor5, nor8);
    int and001 = porta_and(neg01, nor2);
    int nor001 = porta_not(porta_or(and01, and02));
    int and002 = porta_and(neg02, nor4);
    int nor002 = porta_not(porta_or_3(and03, and04, and05));
    int and003 = porta_and(neg03, nor6);
    int nor003 = porta_not(porta_or_4(and06, and07, and08, and09));
    int and004 = porta_and(neg04, nor8);
    int nor004 = porta_not(porta_or_4(and010, and011, and012, nor7));
    int exor0001 = porta_exor(nand01, and001);
    int exor0002 = porta_exor(nor001, and002);
    int exor0003 = porta_exor(nor002, and003);
    int exor0004 = porta_exor(nor003, and004);
    F[0] = exor0001;
    F[1] = exor0002;
    F[2] = exor0003;
    F[3] = exor0004;
    *A_uguale_B = porta_and_4(exor0001, exor0002, exor0003, exor0004);
    *P = nand02;
    int or0001 = porta_or(porta_not(nand03), porta_not(nor004));
    *Cn_piu_4 = or0001;
    *G = nor004;
}
/*
 ╔════════════════════════════════════════════════════════════════════════════════════╗
 ║                    ⇨ SIMULAZIONE ALU 74181 (MODULO SINGOLO) ⇦                      ║
 ╠════════════════════════════════════════════════════════════════════════════════════╣
 ║                                                                                    ║
 ║  Questa funzione chiede all’utente di inserire i segnali (0 o 1) per:              ║
 ║    • Carry in (Cn)                                                                 ║
 ║    • Modalità (M)                                                                  ║
 ║    • I 4 bit dell’operando A (A0, A1, A2, A3)                                      ║
 ║    • I 4 bit dell’operando B (B0, B1, B2, B3)                                      ║
 ║    • I 4 bit di selezione dell’operazione (S0, S1, S2, S3)                         ║
 ║                                                                                    ║
 ║  Per ogni segnale viene controllato, tramite if annidati, che il valore sia 0 o 1. ║
 ║  Successivamente, vengono creati gli array A, B e S e chiamata la funzione         ║
 ║  alu_74181_calcola() per eseguire il calcolo.                                      ║
 ║  Infine, vengono stampati i risultati e un flag (es. Cn_piu_4) viene salvato in    ║
 ║  memoria.                                                                          ║
 ║                                                                                    ║
 ╚════════════════════════════════════════════════════════════════════════════════════╝
 */

 void simula_alu_74181() {
    int Cn, M, A0, B0, A1, B1, A2, B2, A3, B3, S0, S1, S2, S3;
    char scelta[3];

    printf("Inserire dati manualmente? (S/N): ");
    scanf("%s", scelta);
    scelta[0] = toupper(scelta[0]);

    if (scelta[0] == 'S') {
        // Codice originale per input manuale
        printf(">> Inserisci i valori degli input (0 o 1):\n");
        
        // Cn
        printf(">> Cn: ");
        scanf("%d", &Cn);
        if (Cn == 0){}else if(Cn == 1){}else {
            printf("╔════════════════════════════════╗\n");
            printf("║            ERRORE              ║\n");
            printf("╠════════════════════════════════╣\n");
            printf("║                                ║\n");
            printf("║      Cn deve essere 0 o 1      ║\n");
            printf("║                                ║\n");
            printf("╚════════════════════════════════╝\n");
            return;
        }

        // M
        printf(">> M:  ");
        scanf("%d", &M);
        if (M == 0){}else if(M == 1){}else {
            printf("╔════════════════════════════════╗\n");
            printf("║            ERRORE              ║\n");
            printf("╠════════════════════════════════╣\n");
            printf("║                                ║\n");
            printf("║       M deve essere 0 o 1      ║\n");
            printf("║                                ║\n");
            printf("╚════════════════════════════════╝\n");
            return;
        }

        // A0
        printf(">> A0: ");
        scanf("%d", &A0);
        if (A0 == 0){}else if(A0 == 1){}else {
            printf("╔════════════════════════════════╗\n");
            printf("║            ERRORE              ║\n");
            printf("╠════════════════════════════════╣\n");
            printf("║                                ║\n");
            printf("║      A0 deve essere 0 o 1      ║\n");
            printf("║                                ║\n");
            printf("╚════════════════════════════════╝\n");
            return;
        }

        // B0
        printf(">> B0: ");
        scanf("%d", &B0);
        if (B0 == 0){}else if(B0 == 1){}else {
            printf("╔════════════════════════════════╗\n");
            printf("║            ERRORE              ║\n");
            printf("╠════════════════════════════════╣\n");
            printf("║                                ║\n");
            printf("║      B0 deve essere 0 o 1      ║\n");
            printf("║                                ║\n");
            printf("╚════════════════════════════════╝\n");
            return;
        }

        // A1
        printf(">> A1: ");
        scanf("%d", &A1);
        if (A1 == 0){}else if(A1 == 1){}else {
            printf("╔════════════════════════════════╗\n");
            printf("║            ERRORE              ║\n");
            printf("╠════════════════════════════════╣\n");
            printf("║                                ║\n");
            printf("║      A1 deve essere 0 o 1      ║\n");
            printf("║                                ║\n");
            printf("╚════════════════════════════════╝\n");
            return;
        }

        // B1
        printf(">> B1: ");
        scanf("%d", &B1);
        if (B1 == 0){}else if(B1 == 1){}else {
            printf("╔════════════════════════════════╗\n");
            printf("║            ERRORE              ║\n");
            printf("╠════════════════════════════════╣\n");
            printf("║                                ║\n");
            printf("║      B1 deve essere 0 o 1      ║\n");
            printf("║                                ║\n");
            printf("╚════════════════════════════════╝\n");
            return;
        }

        // A2
        printf(">> A2: ");
        scanf("%d", &A2);
        if (A2 == 0){}else if(A2 == 1){}else {
            printf("╔════════════════════════════════╗\n");
            printf("║            ERRORE              ║\n");
            printf("╠════════════════════════════════╣\n");
            printf("║                                ║\n");
            printf("║      A2 deve essere 0 o 1      ║\n");
            printf("║                                ║\n");
            printf("╚════════════════════════════════╝\n");
            return;
        }

        // B2
        printf(">> B2: ");
        scanf("%d", &B2);
        if (B2 == 0){}else if(B2 == 1){}else {
            printf("╔════════════════════════════════╗\n");
            printf("║            ERRORE              ║\n");
            printf("╠════════════════════════════════╣\n");
            printf("║                                ║\n");
            printf("║      B2 deve essere 0 o 1      ║\n");
            printf("║                                ║\n");
            printf("╚════════════════════════════════╝\n");
            return;
        }

        // A3
        printf(">> A3: ");
        scanf("%d", &A3);
        if (A3 == 0){}else if(A3 == 1){}else {
            printf("╔════════════════════════════════╗\n");
            printf("║            ERRORE              ║\n");
            printf("╠════════════════════════════════╣\n");
            printf("║                                ║\n");
            printf("║      A3 deve essere 0 o 1      ║\n");
            printf("║                                ║\n");
            printf("╚════════════════════════════════╝\n");
            return;
        }

        // B3
        printf(">> B3: ");
        scanf("%d", &B3);
        if (B3 == 0){}else if(B3 == 1){}else {
            printf("╔════════════════════════════════╗\n");
            printf("║            ERRORE              ║\n");
            printf("╠════════════════════════════════╣\n");
            printf("║                                ║\n");
            printf("║      B3 deve essere 0 o 1      ║\n");
            printf("║                                ║\n");
            printf("╚════════════════════════════════╝\n");
            return;
        }

        // S0
        printf(">> S0: ");
        scanf("%d", &S0);
        if (S0 == 0){}else if(S0 == 1){}else {
            printf("╔════════════════════════════════╗\n");
            printf("║            ERRORE              ║\n");
            printf("╠════════════════════════════════╣\n");
            printf("║                                ║\n");
            printf("║      S0 deve essere 0 o 1      ║\n");
            printf("║                                ║\n");
            printf("╚════════════════════════════════╝\n");
            return;
        }

        // S1
        printf(">> S1: ");
        scanf("%d", &S1);
        if (S1 == 0){}else if(S1 == 1){}else {
            printf("╔════════════════════════════════╗\n");
            printf("║            ERRORE              ║\n");
            printf("╠════════════════════════════════╣\n");
            printf("║                                ║\n");
            printf("║      S1 deve essere 0 o 1      ║\n");
            printf("║                                ║\n");
            printf("╚════════════════════════════════╝\n");
            return;
        }

        // S2
        printf(">> S2: ");
        scanf("%d", &S2);
        if (S2 == 0){}else if(S2 == 1){}else {
            printf("╔════════════════════════════════╗\n");
            printf("║            ERRORE              ║\n");
            printf("╠════════════════════════════════╣\n");
            printf("║                                ║\n");
            printf("║      S2 deve essere 0 o 1      ║\n");
            printf("║                                ║\n");
            printf("╚════════════════════════════════╝\n");
            return;
        }

        // S3
        printf(">> S3: ");
        scanf("%d", &S3);
        if (S3 == 0){}else if(S3 == 1){}else {
            printf("╔════════════════════════════════╗\n");
            printf("║            ERRORE              ║\n");
            printf("╠════════════════════════════════╣\n");
            printf("║                                ║\n");
            printf("║      S3 deve essere 0 o 1      ║\n");
            printf("║                                ║\n");
            printf("╚════════════════════════════════╝\n");
            return;
        }

    } else {
        FILE *file = fopen("input_alu.txt", "r");
        
        if (file == NULL) {
            file = fopen("input_alu.txt", "w");
            if (file == NULL) {
                printf("ERRORE: Impossibile creare il file\n");
                return;
            }
            
            fprintf(file, "Cn: <0>\n"); 
            fprintf(file, "M: <0>\n"); 
            fprintf(file, "A0: <0>\n"); 
            fprintf(file, "B0: <0>\n"); 
            fprintf(file, "A1: <0>\n"); 
            fprintf(file, "B1: <0>\n"); 
            fprintf(file, "A2: <0>\n"); 
            fprintf(file, "B2: <0>\n"); 
            fprintf(file, "A3: <0>\n"); 
            fprintf(file, "B3: <0>\n"); 
            fprintf(file, "S0: <0>\n"); 
            fprintf(file, "S1: <0>\n"); 
            fprintf(file, "S2: <0>\n"); 
            fprintf(file, "S3: <0>\n");
            fclose(file);
            printf("Creato file input_alu.txt. Compilarlo e riavviare.\n");
            return;
        }
        char line[100];

        // Cn
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_Cn = sscanf(line, "%*[^<]<%d>", &Cn);
        if (sscanf_result_Cn == 1) {} else { printf("ERRORE: Valore non valido in Cn\n"); fclose(file); return; }
        if (Cn == 0) {} else if (Cn == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      Cn deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

        // M
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_M = sscanf(line, "%*[^<]<%d>", &M);
        if (sscanf_result_M == 1) {} else { printf("ERRORE: Valore non valido in M\n"); fclose(file); return; }
        if (M == 0) {} else if (M == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║       M deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

        // A0
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_A0 = sscanf(line, "%*[^<]<%d>", &A0);
        if (sscanf_result_A0 == 1) {} else { printf("ERRORE: Valore non valido in A0\n"); fclose(file); return; }
        if (A0 == 0) {} else if (A0 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      A0 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

        // B0
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_B0 = sscanf(line, "%*[^<]<%d>", &B0);
        if (sscanf_result_B0 == 1) {} else { printf("ERRORE: Valore non valido in B0\n"); fclose(file); return; }
        if (B0 == 0) {} else if (B0 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      B0 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

        // A1
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_A1 = sscanf(line, "%*[^<]<%d>", &A1);
        if (sscanf_result_A1 == 1) {} else { printf("ERRORE: Valore non valido in A1\n"); fclose(file); return; }
        if (A1 == 0) {} else if (A1 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      A1 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

        // B1
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_B1 = sscanf(line, "%*[^<]<%d>", &B1);
        if (sscanf_result_B1 == 1) {} else { printf("ERRORE: Valore non valido in B1\n"); fclose(file); return; }
        if (B1 == 0) {} else if (B1 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      B1 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

        // A2
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_A2 = sscanf(line, "%*[^<]<%d>", &A2);
        if (sscanf_result_A2 == 1) {} else { printf("ERRORE: Valore non valido in A2\n"); fclose(file); return; }
        if (A2 == 0) {} else if (A2 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      A2 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

        // B2
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_B2 = sscanf(line, "%*[^<]<%d>", &B2);
        if (sscanf_result_B2 == 1) {} else { printf("ERRORE: Valore non valido in B2\n"); fclose(file); return; }
        if (B2 == 0) {} else if (B2 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      B2 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

        // A3
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_A3 = sscanf(line, "%*[^<]<%d>", &A3);
        if (sscanf_result_A3 == 1) {} else { printf("ERRORE: Valore non valido in A3\n"); fclose(file); return; }
        if (A3 == 0) {} else if (A3 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      A3 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

        // B3
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_B3 = sscanf(line, "%*[^<]<%d>", &B3);
        if (sscanf_result_B3 == 1) {} else { printf("ERRORE: Valore non valido in B3\n"); fclose(file); return; }
        if (B3 == 0) {} else if (B3 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      B3 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

        // S0
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_S0 = sscanf(line, "%*[^<]<%d>", &S0);
        if (sscanf_result_S0 == 1) {} else { printf("ERRORE: Valore non valido in S0\n"); fclose(file); return; }
        if (S0 == 0) {} else if (S0 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      S0 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

        // S1
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_S1 = sscanf(line, "%*[^<]<%d>", &S1);
        if (sscanf_result_S1 == 1) {} else { printf("ERRORE: Valore non valido in S1\n"); fclose(file); return; }
        if (S1 == 0) {} else if (S1 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      S1 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

        // S2
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_S2 = sscanf(line, "%*[^<]<%d>", &S2);
        if (sscanf_result_S2 == 1) {} else { printf("ERRORE: Valore non valido in S2\n"); fclose(file); return; }
        if (S2 == 0) {} else if (S2 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      S2 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

        // S3
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_S3 = sscanf(line, "%*[^<]<%d>", &S3);
        if (sscanf_result_S3 == 1) {} else { printf("ERRORE: Valore non valido in S3\n"); fclose(file); return; }
        if (S3 == 0) {} else if (S3 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      S3 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

        fclose(file);
    }

    int A[4] = {A0, A1, A2, A3};
    int B[4] = {B0, B1, B2, B3};
    int S[4] = {S0, S1, S2, S3};
    int F[4];
    int A_uguale_B, P, Cn_piu_4, G;

    alu_74181_calcola(Cn, M, A, B, S, F, &A_uguale_B, &P, &Cn_piu_4, &G);

    // Output dei risultati
    printf("\n");
    printf("╔═════════════════════════════════════════════╗\n");
    printf("║           RISULTATI ALU 74181               ║\n");
    printf("╠═════════════════════════════════════════════╣\n");
    printf("║                                             ║\n");
    printf("║  - F0      = %-3d                            ║\n", F[0]);
    printf("║  - F1      = %-3d                            ║\n", F[1]);
    printf("║  - A = B   = %-3d                            ║\n", A_uguale_B);
    printf("║  - F2      = %-3d                            ║\n", F[2]);
    printf("║  - F3      = %-3d                            ║\n", F[3]);
    printf("║  - P       = %-3d                            ║\n", P);
    printf("║  - Cn + 4  = %-3d                            ║\n", Cn_piu_4);
    printf("║  - G       = %-3d                            ║\n", G);
    printf("║                                             ║\n");
    printf("╚═════════════════════════════════════════════╝\n");

    // Salvataggio in memoria
    salva_in_memoria(Cn_piu_4);

    // Salvataggio su file
    FILE *file_out = fopen("risultati_alu_74181.txt", "w");
    if (file_out == NULL) { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║    Impossibile aprire file     ║\n║         di scrittura           ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }

    fprintf(file_out, "╔═════════════════════════════════════════════╗\n");
    fprintf(file_out, "║           RISULTATI ALU 74181               ║\n");
    fprintf(file_out, "╠═════════════════════════════════════════════╣\n");
    fprintf(file_out, "║                                             ║\n");
    fprintf(file_out, "║  - F0      = %-3d                            ║\n", F[0]);
    fprintf(file_out, "║  - F1      = %-3d                            ║\n", F[1]);
    fprintf(file_out, "║  - A = B   = %-3d                            ║\n", A_uguale_B);
    fprintf(file_out, "║  - F2      = %-3d                            ║\n", F[2]);
    fprintf(file_out, "║  - F3      = %-3d                            ║\n", F[3]);
    fprintf(file_out, "║  - P       = %-3d                            ║\n", P);
    fprintf(file_out, "║  - Cn + 4  = %-3d                            ║\n", Cn_piu_4);
    fprintf(file_out, "║  - G       = %-3d                            ║\n", G);
    fprintf(file_out, "║                                             ║\n");
    fprintf(file_out, "╚═════════════════════════════════════════════╝\n");

    fclose(file_out);
    sleep(10);
}
/*
 ╔════════════════════════════════════════════════════════════════════════════════════════╗
 ║                     ⇨ ALU IN MODALITÀ PIPO (8 MODULI IN CASCATA) ⇦                     ║
 ╠════════════════════════════════════════════════════════════════════════════════════════╣
 ║                                                                                        ║
 ║  Questa funzione simula una ALU a 32 bit realizzata mediante 8 moduli ALU 74181,       ║
 ║  ciascuno a 4 bit (nibble). Funziona come segue:                                       ║
 ║                                                                                        ║
 ║    1. L’utente inserisce due operandi a 32 bit (in formato decimale).                  ║
 ║    2. L’utente inserisce i segnali comuni (Cn, M e S0-S3) da utilizzare per tutti      ║
 ║       i moduli.                                                                        ║
 ║    3. Il codice estrae da ciascun operando i nibble (gruppi di 4 bit), partendo dal    ║
 ║       nibble meno significativo fino al nibble più significativo.                      ║
 ║    4. Per ogni nibble viene chiamata la funzione alu_74181_calcola() passando il       ║
 ║       carry in attuale; il risultato (4 bit) viene poi combinato nel risultato finale  ║
 ║       a 32 bit.                                                                        ║
 ║    5. Il carry out (Cn_piu_4) del modulo corrente viene propagato come carry in per    ║
 ║       il modulo successivo.                                                            ║
 ║    6. Infine, il risultato finale viene stampato e salvato in memoria.                 ║
 ║                                                                                        ║
 ╚════════════════════════════════════════════════════════════════════════════════════════╝
 */
 void alu_pipo_8() {
    unsigned int operandoA, operandoB;
    int Cn, M;
    int S[4];
    printf(">> Inserisci il primo operando (numero decimale a 32 bit): ");
    scanf("%u", &operandoA);
    printf(">> Inserisci il secondo operando (numero decimale a 32 bit): ");
    scanf("%u", &operandoB);
    printf(">> Inserisci il segnale di Carry In (Cn, 0 o 1): ");
    scanf("%d", &Cn);
    if (Cn == 0){}else if(Cn == 1){}else{printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      Cn deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");return;}
    printf(">> Inserisci il segnale M (0 o 1): ");
    scanf("%d", &M);
    if (M == 0){}else if(M == 1){}else{printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║       M deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");return;}
    printf(">> Inserisci i segnali di selezione S0, S1, S2, S3 (0 o 1, separati da spazi): ");
    scanf("%d %d %d %d", &S[0], &S[1], &S[2], &S[3]);
    for (int i = 0; i < 4; i++) {
        if (S[i] == 0){}else if(S[i] == 1){}else{printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      S%d deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n", i);return;}
    }
    unsigned int result = 0;
    int currentCn = Cn;
    int F[4];        
    int A_uguale_B, P, Cn_piu_4, G; 
    for (int nibble = 0; nibble < 8; nibble++) {
        int Abits[4], Bbits[4];
        for (int bit = 0; bit < 4; bit++) {
            Abits[bit] = (operandoA >> (nibble * 4 + bit)) & 1;
            Bbits[bit] = (operandoB >> (nibble * 4 + bit)) & 1;
        }
        alu_74181_calcola(currentCn, M, Abits, Bbits, S, F, &A_uguale_B, &P, &Cn_piu_4, &G);
        unsigned int nibbleResult = (F[0] << 0) | (F[1] << 1) | (F[2] << 2) | (F[3] << 3);
        result |= (nibbleResult << (nibble * 4));
        currentCn = Cn_piu_4;
    }
    printf("Risultato ALU PIPO a 32 bit (decimale): %u\n", result);
    salva_in_memoria(result);
    sleep(10);
}
/*
 ╔════════════════════════════════════════════════════════════════════════════════════╗
 ║                              ⇨ OPERAZIONI ALGEBRICHE ⇦                             ║
 ╠════════════════════════════════════════════════════════════════════════════════════╣
 ║                                                                                    ║
 ║  Queste funzioni implementano le operazioni aritmetiche di base:                   ║
 ║                                                                                    ║
 ║  • somma: restituisce la somma di due numeri.                                      ║
 ║  • sottrazione: restituisce la differenza tra due numeri.                          ║
 ║  • moltiplicazione: restituisce il prodotto di due numeri.                         ║
 ║  • divisione: restituisce il quoziente, con controllo per la divisione per 0.      ║
 ║                                                                                    ║
 ║  La funzione operazioni_algebriche() permette all'utente di scegliere:             ║
 ║    • Operazioni su 2 elementi: somma, sottrazione, moltiplicazione, divisione.     ║
 ║    • Operazioni su 3 elementi: supporta somma o moltiplicazione.                   ║
 ║                                                                                    ║
 ╚════════════════════════════════════════════════════════════════════════════════════╝
 */
 int somma(int a, int b) {
    return a + b;
}
int sottrazione(int a, int b) {
    return a - b;
}
int moltiplicazione(int a, int b) {
    return a * b;
}
int divisione(int a, int b) {
    if (b == 0) { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║   Impossibile dividere per 0   ║\n║                                ║\n╚════════════════════════════════╝\n"); return 0; }
    return a / b;
}
void operazioni_algebriche() {
    int num_elementi;
    printf(">> Quanti elementi vuoi utilizzare (2 o 3)? ");
    scanf("%d", &num_elementi);
    if (num_elementi == 2) {
        int a, b;
        printf(">> Inserisci i due numeri: ");
        scanf("%d %d", &a, &b);
        char operazione[20];
        printf(">> Scegli l'operazione (somma, sottrazione, moltiplicazione, divisione): ");
        scanf("%s", operazione);
        if (strcmp(operazione, "somma") == 0) {
            int res = somma(a, b);
            printf("╔════════════════════════════════╗\n║         SOMMA ALGEBRICA        ║\n╚════════════════════════════════╝\nRisultato: %d\n", res);
            salva_in_memoria(res);
        } else if (strcmp(operazione, "sottrazione") == 0) {
            int res = sottrazione(a, b);
            printf("╔════════════════════════════════╗\n║      SOTTRAZIONE ALGEBRICA     ║\n╚════════════════════════════════╝\nRisultato: %d\n", res);
            salva_in_memoria(res);
        } else if (strcmp(operazione, "moltiplicazione") == 0) {
            int res = moltiplicazione(a, b);
            printf("╔════════════════════════════════╗\n║    MOLTIPLICAZIONE ALGEBRICA   ║\n╚════════════════════════════════╝\nRisultato: %d\n", res);
            salva_in_memoria(res);
        } else if (strcmp(operazione, "divisione") == 0) {
            int res = divisione(a, b);
            printf("╔════════════════════════════════╗\n║        DIVISIONE ALGEBRICA     ║\n╚════════════════════════════════╝\nRisultato: %d\n", res);
            salva_in_memoria(res);
        } else { printf("╔════════════════════════════════╗\n║             ERRORE             ║\n╠════════════════════════════════╣\n║                                ║\n║   Operazione non riconosciuta  ║\n║                                ║\n╚════════════════════════════════╝\n"); }
    } else if (num_elementi == 3) {
        int a, b, c;
        printf(">> Inserisci i tre numeri: ");
        scanf("%d %d %d", &a, &b, &c);
        char operazione[20];
        printf(">> Scegli l'operazione (somma o moltiplicazione): ");
        scanf("%s", operazione);
        if (strcmp(operazione, "somma") == 0) {
            int res = somma(somma(a, b), c);
            printf("╔════════════════════════════════╗\n║         SOMMA ALGEBRICA        ║\n╚════════════════════════════════╝\nRisultato: %d\n", res);
            salva_in_memoria(res);
        } else if (strcmp(operazione, "moltiplicazione") == 0) {
            int res = moltiplicazione(moltiplicazione(a, b), c);
            printf("╔════════════════════════════════╗\n║    MOLTIPLICAZIONE ALGEBRICA   ║\n╚════════════════════════════════╝\nRisultato: %d\n", res);
            salva_in_memoria(res);
        } else {
            printf("╔════════════════════════════════╗\n║             ERRORE             ║\n╠════════════════════════════════╣\n║                                ║\n║   Operazione non riconosciuta  ║\n║                                ║\n╚════════════════════════════════╝\n");
        }
    } else {
        printf("╔════════════════════════════════╗\n║             ERRORE             ║\n╠════════════════════════════════╣\n║                                ║\n║ Numero di elementi non valido. ║\n║      Scegli tra 2 oppure 3     ║\n║                                ║\n╚════════════════════════════════╝\n");
    }
    sleep(10);
}

void misura_ciclo_clock() {
    printf("Rilevamento sistema in corso...\n");
    char *sistema = "Sconosciuto";
    int su_windows = 0;
    if (system("ver | findstr /i \"Windows\" > nul 2>&1") == 0) {
        su_windows = 1;
    }
    if (su_windows == 1) {
        sistema = "Windows";
        printf("OS: %s\n", sistema);
        printf("CPU: Informazioni limitate via C puro\n");
        printf("Tipo: Intel/AMD (stimato)\n");
        printf("Frequenza: ~N/D (richiede strumenti esterni)\n");
    }
    int su_linux = 0;
    FILE *fp = fopen("/proc/version", "r");
    if (fp != NULL) {
        char line[256];
        if (fgets(line, sizeof(line), fp)) {
            if (line[0] == 'L' && line[1] == 'i' && line[2] == 'n') {
                su_linux = 1;
            }
        }
        fclose(fp);
    }

    if (su_linux == 1) {
        sistema = "Linux";
        printf("OS: %s\n", sistema);
        printf("CPU: Leggo informazioni da /proc/cpuinfo\n");
        FILE *cpuinfo = fopen("/proc/cpuinfo", "r");
        if (cpuinfo != NULL) {
            char line[256];
            int letti = 0;
            while (fgets(line, sizeof(line), cpuinfo) && letti < 3) {
                if (!strncmp(line, "model name", 10) ||
                    !strncmp(line, "vendor_id", 9) ||
                    !strncmp(line, "cpu cores", 9) ||
                    !strncmp(line, "siblings", 8)) {
                    printf("%s", line);
                    letti++;
                }
            }
            fclose(cpuinfo);
        }
    }
    int su_mac = 0;
    #ifdef __APPLE__
        su_mac = 1;
    #endif
    if (su_mac == 1) {
        sistema = "macOS";
        printf("OS: %s\n", sistema);
        printf("CPU: Apple Silicon o x86 (detected)\n");
        system("sysctl -n machdep.cpu.brand_string");
    }
    printf("\nMisurando la durata di un ciclo di clock (simulato)...\n");
    int i;
    for (i = 0; i < 1000; i++) {
        attendi_un_ciclo_clock(); // Richiama la funzione definita sopra
    }
    printf("\nSimulazione completata.\n");
    printf("Un ciclo di clock richiede circa 1 millisecondo in questa simulazione.\n");
    printf("Questo è solo un valore stimato. La CPU reale lavora molto più velocemente!\n");
    sleep(10);
    return;
}
/*
 ╔════════════════════════════════════════════════════════════════════════════════════╗
 ║                                ⇨ FUNZIONE MAIN ⇦                                   ║
 ╠════════════════════════════════════════════════════════════════════════════════════╣
 ║                                                                                    ║
 ║  Il menu principale offre le varie funzionalità:                                   ║
 ║                                                                                    ║
 ║    1. Operazioni Logiche (simulazione di un modulo ALU 74181 singolo).             ║
 ║    2. Operazioni Algebriche.                                                       ║
 ║    3. Convertitore Binario -> Decimale.                                            ║
 ║    4. Convertitore Decimale -> Binario.                                            ║
 ║    5. ALU in Modalità PIPO: simulazione di una ALU a 32 bit composta da 8 moduli   ║
 ║       74181 (4 bit ciascuno).                                                      ║
 ║    6. Visualizza Memoria: visualizza i risultati salvati nella memoria.            ║
 ║    0. Esci: termina il programma.                                                  ║
 ║                                                                                    ║
 ║  Ogni scelta viene gestita tramite if annidati (non usando operatori composti)     ║
 ║  come richiesto.                                                                   ║
 ║                                                                                    ║
 ╚════════════════════════════════════════════════════════════════════════════════════╝
 */
int main() {
    int scelta;

    while (1) {
        printf("\n╔════════════════════════════════════════════════════════╗");
        printf("\n║                    MENU PRINCIPALE                     ║");
        printf("\n╠════════════════════════════════════════════════════════╣");
        printf("\n║  1. Operazioni Logiche (ALU 74181 - Singolo)           ║");
        printf("\n║  2. Operazioni Logiche (ALU 74181 - Singolo con clock) ║");
        printf("\n║  3. Operazioni Algebriche                              ║");
        printf("\n║  4. Convertitore Binario → Decimale                    ║");
        printf("\n║  5. Convertitore Decimale → Binario                    ║");
        printf("\n║  6. ALU in Modalità PIPO (32 bit - 8x74181)            ║");
        printf("\n║  7. ALU in Modalità PIPO (32 bit - 8x74181 con clock)  ║");
        printf("\n║  8. Visualizza Memoria                                 ║");
        printf("\n║  9. Calcolo del Clock                                  ║");
        printf("\n║  0. Esci                                               ║");
        printf("\n╚════════════════════════════════════════════════════════╝");
        printf("\n>> Inserisci la tua scelta: ");
        scanf("%d", &scelta);

        if (scelta == 0) {
            printf("Uscita dal programma...\n");
            break;
        } else if (scelta == 1) {
            simula_alu_74181();
        } else if (scelta == 2) {
            attendi_un_ciclo_clock();
            simula_alu_74181();
        } else if (scelta == 3) {
            operazioni_algebriche();
        } else if (scelta == 4) {
            int bin;
            printf(">> Inserisci un numero binario: ");
            scanf("%d", &bin);
            printf("Risultato (decimale): %d\n", binario_a_decimale(bin));
        } else if (scelta == 5) {
            int dec;
            printf(">> Inserisci un numero decimale: ");
            scanf("%d", &dec);
            printf("Risultato (binario): %d\n", decimale_a_binario(dec));
        } else if (scelta == 6) {
            alu_pipo_8();
        } else if (scelta == 7) {
            attendi_un_ciclo_clock();
            alu_pipo_8();
        } else if (scelta == 8) {
            stampa_memoria();
        } else if (scelta == 9) {
            misura_ciclo_clock();
        } else {
            printf("Scelta non valida!\n");
        }
    }

    return 0;
}