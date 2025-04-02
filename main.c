#include <stdio.h>

// Porte Logiche basi
int porta_not(int a) { return 1 - a; }
int porta_and(int a, int b) { return (a * b); }
int porta_or(int a, int b) { return (a + b) - (a * b); }
int porta_exor(int a, int b) { return (a + b) - 2 * (a * b); }

// Porta OR per più ingressi
int porta_or_3(int a, int b, int c) { return porta_or(porta_or(a, b), c); }
int porta_or_4(int a, int b, int c, int d) { return porta_or(porta_or(a, b), porta_or(c, d)); }
int porta_or_5(int a, int b, int c, int d, int e) { return porta_or(porta_or_4(a, b, c, d), e); }
// (continua la logica in modo simile)

// Porta AND per più ingressi
int porta_and_3(int a, int b, int c) { return porta_and(porta_and(a, b), c); }
int porta_and_4(int a, int b, int c, int d) { return porta_and(porta_and(a, b), porta_and(c, d)); }
// (continua la logica in modo simile)

// Porta EXOR per più ingressi
int porta_exor_3(int a, int b, int c) { return porta_exor(porta_exor(a, b), c); }
int porta_exor_4(int a, int b, int c, int d) { return porta_exor(porta_exor(a, b), porta_exor(c, d)); } // Corretta parentesi
int porta_exor_5(int a, int b, int c, int d, int e) { return porta_exor(porta_exor_4(a, b, c, d), e); }
// (continua la logica in modo simile)

int main() {
    int a, b;
    int Cn, M, A0, B0, A1, B1, A2, B2, A3, B3, S0, S1, S2, S3; // input ALU
    int C, Cn_piu_4, P, F3, F2, A_uguale_B, F1, F0; // output ALU
    int neg1, neg2, neg3, neg4, neg5;
    int and1, and2, and3, and4, and5, and6, and7, and8, and9, and10, and11, and12, and13, and14, and15, and16;
    int nor1, nor2, nor3, nor4, nor5, nor6, nor7, nor8;
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

    if (Cn == 1 || Cn == 0) {
        if (M == 1 || M == 0) {
            if (A0 == 0 || A0 == 1) {
                if (B0 == 0 || B0 == 1) {
                    if (A1 == 0 || A1 == 1) {
                        if (B1 == 0 || B1 == 1) {
                            if (A2 == 0 || A2 == 1) {
                                if (B2 == 0 || B2 == 1) {
                                    if (A3 == 0 || A3 == 1) {
                                        if (B3 == 0 || B3 == 1) {
                                            if (S0 == 0 || S0 == 1) {
                                                if (S1 == 0 || S1 == 1) {
                                                    if (S2 == 0 || S2 == 1) {
                                                        if (S3 == 0 || S3 == 1) {


                                                            neg1 = porta_not(B3);
                                                            neg2 = porta_not(B2);
                                                            neg3 = porta_not(B1);
                                                            neg4 = porta_not(B0);
                                                            neg5 = porta_not(M);


                                                            and1 = porta_and_3(B3,S3,A3);
                                                            and2 = porta_and_3(neg1,S2,A3);
                                                            and3 = porta_and(neg1,S1);
                                                            and4 = porta_and(S0,B3);
                                                            printf("Ecco i risultati degli output dell' ALU\n");
                                                        } else {
                                                            printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");
                                                        }
                                                    } else {
                                                        printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");
                                                    }
                                                } else {
                                                    printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");
                                                }
                                            } else {
                                                printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");
                                            }
                                        } else {
                                            printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");
                                        }
                                    } else {
                                        printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");
                                    }
                                } else {
                                    printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");
                                }
                            } else {
                                printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");
                            }
                        } else {
                            printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");
                        }
                    } else {
                        printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");
                    }
                } else {
                    printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");
                }
            } else {
                printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");
            }
        } else {
            printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");
        }
    } else {
        printf("[!] ERRORE: Gli input devono essere obbligatoriamente 0 o 1.\n");
    }
}
