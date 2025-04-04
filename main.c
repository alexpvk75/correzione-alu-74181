#include <stdio.h>
/***********************************************************\
|                      ALU 74181                            |
|                                                           |
| Realizzata da Leonardo, Danilo, Oleksandr, Davide, Angelo |
|                                                           |
| Questo codice implementa una simulazione dell'ALU 74181,  |
| essa può eseguire operazioni logiche e aritmetiche a 4 bit|
| tramite le porte logiche AND, OR, XOR e altre funzioni.   |
| La struttura dell'ALU segue le specifiche del circuito    |
| originale, simulando le porte logiche necessarie.         |
\***********************************************************/

// Porte Logiche
int porta_not(int a) { return 1 - a; }
int porta_and(int a, int b) { return (a * b); }
int porta_or(int a, int b) { return (a + b) - (a * b); }
int porta_exor(int a, int b) { return (a + b) - 2 * (a * b); }

// Porta OR per più ingressi
int porta_or_3(int a, int b, int c) { return porta_or(porta_or(a, b), c); }
int porta_or_4(int a, int b, int c, int d) { return porta_or(porta_or(a, b), porta_or(c, d)); }
int porta_or_5(int a, int b, int c, int d, int e) { return porta_or(porta_or_4(a, b, c, d), e); }

// Porta AND per più ingressi
int porta_and_3(int a, int b, int c) { return porta_and(porta_and(a, b), c); }
int porta_and_4(int a, int b, int c, int d) { return porta_and(porta_and(a, b), porta_and(c, d)); }
int porta_and_5(int a, int b, int c, int d, int e) {return porta_and(porta_and(porta_and(a, b), porta_and(c, d)), e);}


// Porta EXOR per più ingressi
int porta_exor_3(int a, int b, int c) { return porta_exor(porta_exor(a, b), c); }
int porta_exor_4(int a, int b, int c, int d) { return porta_exor(porta_exor(a, b), porta_exor(c, d)); } // Corretta parentesi
int porta_exor_5(int a, int b, int c, int d, int e) { return porta_exor(porta_exor_4(a, b, c, d), e); }

int main() {
    int Cn,M,A0,B0,A1,B1,A2,B2,A3,B3,S0,S1,S2,S3;
    printf("Inserisci i valori degli input di ingresso:\n");
    printf("Cn: "); scanf("%d", &Cn);
    printf("M: "); scanf("%d", &M);
    printf("A0: "); scanf("%d", &A0);
    printf("B0: "); scanf("%d", &B0);
    printf("A1: "); scanf("%d", &A1);
    printf("B1: "); scanf("%d", &B1);
    printf("A2: "); scanf("%d", &A2);
    printf("B2: "); scanf("%d", &B2);
    printf("A3: "); scanf("%d", &A3);
    printf("B3: "); scanf("%d", &B3);
    printf("S0: "); scanf("%d", &S0);
    printf("S1: "); scanf("%d", &S1);
    printf("S2: "); scanf("%d", &S2);
    printf("S3: "); scanf("%d", &S3);

    if ((Cn == 0 || Cn == 1) &&(M == 0 || M == 1) &&(A0 == 0 || A0 == 1) &&(B0 == 0 || B0 == 1) &&(A1 == 0 || A1 == 1) &&(B1 == 0 || B1 == 1) &&(A2 == 0 || A2 == 1) &&(B2 == 0 || B2 == 1) &&(A3 == 0 || A3 == 1) &&(B3 == 0 || B3 == 1) &&(S0 == 0 || S0 == 1) &&(S1 == 0 || S1 == 1) &&(S2 == 0 || S2 == 1) &&(S3 == 0 || S3 == 1)) {
    int neg1 = porta_not(M);
    int neg2 = porta_not(B0);
    int neg3 = porta_not(B1);
    int neg4 = porta_not(B2);
    int neg5 = porta_not(B3);
    int and1 = porta_and(B0,S0);
    int and2 = porta_and(S1,neg2);
    int and3 = porta_and_3(neg2,S2,A0);
    int and4 = porta_and_3(A0,B0,S3);
    int and5 = porta_and(B1,S0);
    int and6 = porta_and(S1,neg3);
    int and7 = porta_and_3(neg3,S2,A1);
    int and8 = porta_and_3(A1,S3,B1);
    int and9 = porta_and(B2,S0);
    int and10 = porta_and(S1,neg4);
    int and11 = porta_and_3(neg4,S2,A2);
    int and12 = porta_and_3(A2,S3,B2);
    int and13 = porta_and(B3,S0);
    int and14 = porta_and(S1,neg5);
    int and15 = porta_and_3(neg5,S2,A3);
    int and16 = porta_and_3(A3,S3,B3);
    int nor1 = porta_not(porta_or_3(A0,and1,and2));
    int nor2 = porta_not(porta_or(and3,and4));
    int nor3 = porta_not(porta_or_3(A1,and5,and6));
    int nor4 = porta_not(porta_or(and7,and8));
    int nor5 = porta_not(porta_or_3(A2,and9,and10));
    int nor6 = porta_not(porta_or(and11,and12));
    int nor7 = porta_not(porta_or_3(A3,and13,and14));
    int nor8 = porta_not(porta_or(and15,and16));
    int nand01 = porta_not(porta_and(Cn,neg1));
    int neg01 = porta_not(nor1);
    int and01 = porta_and(neg1,nor1);
    int and02 = porta_and_3(neg1,nor2,Cn);
    int neg02 = porta_not(nor3);
    int and03 = porta_and(neg1,nor3);
    int and04 = porta_and_3(neg1,nor1,nor4);
    int and05 = porta_and_4(neg1,Cn,nor2,nor4);
    int neg03 = porta_not(nor5);
    int and06 = porta_and(neg1,nor5);
    int and07 = porta_and_3(neg1,nor3,nor6);
    int and08 = porta_and_4(neg1,nor1,nor4,nor6);
    int and09 = porta_and_5(neg1,Cn,nor2,nor4,nor6);
    int neg04 = porta_not(nor7);
    int nand02 = porta_not(porta_and_4(nor2,nor4,nor6,nor8));
    int nand03 = porta_not(porta_and_5(Cn,nor2,nor4,nor6,nor8));
    int and010 = porta_and_4(nor1,nor4,nor6,nor8);
    int and011 = porta_and_3(nor3,nor6,nor8);
    int and012 = porta_and(nor5,nor8);
    int and001 = porta_and(neg01,nor2);
    int nor001 = porta_not(porta_or(and01,and02));
    int and002 = porta_and(neg02,nor4);
    int nor002 = porta_not(porta_or_3(and03,and04,and05));
    int and003 = porta_and(neg03,nor6);
    int nor003 = porta_not(porta_or_4(and06,and07,and08,and09));
    int and004 = porta_and(neg04,nor8);
    int nor004 = porta_not(porta_or_4(and010,and011,and012,nor7));
    int exor0001 = porta_exor(nand01,and001);
    int exor0002 = porta_exor(nor001,and002);
    int exor0003 = porta_exor(nor002,and003);
    int exor0004 = porta_exor(nor003,and004);
    int and0001 = porta_and_4(exor0001,exor0002,exor0003,exor0004);
    int or0001 = porta_or(porta_not(nand03),porta_not(nor004));


    int F0 = exor0001;
    int F1 = exor0002;
    int A_uguale_B = and0001;
    int F2 = exor0003;
    int F3 = exor0004;
    int P = nand02;
    int Cn_piu_4 = or0001;
    int G = nor004;
    printf("________________________________________\n");
    printf("Ecco i risultati degli output dell' ALU\n");
    printf("________________________________________\n");
    printf("  \n");
    printf("Output F0 -> %i\n", F0);
    printf("Output F1 -> %i\n", F1);
    printf("Output A=B -> %i\n", A_uguale_B);
    printf("Output F2 -> %i\n", F2);
    printf("Output F3 -> %i\n", F3);
    printf("Output P -> %i\n", P);
    printf("Output Cn+4 -> %i\n", Cn_piu_4);
    printf("Output G -> %i\n", G);
    printf("________________________________________\n");
    } else {printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");}
}
