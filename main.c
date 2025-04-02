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
    int or1;
    int x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20;
    int x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40;
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
                                                            x1 = porta_not(M);
                                                            x2 = porta_not(B0);
                                                            x3 = porta_not(B1);
                                                            x4 = porta_not(B2);
                                                            x5 = porta_not(B3);
                                                            x6 = porta_and(B0, S0);
                                                            x7 = porta_and(S1, x2);
                                                            x8 = porta_and_3(x2, S2, A0);
                                                            x9 = porta_and_3(A0, B0, S3);
                                                            x10 = porta_and(B1, S0);
                                                            x11 = porta_and(S1, x3);
                                                            x12 = porta_and_3(x3, S2, A1);
                                                            x13 = porta_and_3(A1, B1, S3);
                                                            x14 = porta_and(B2, S0);
                                                            x15 = porta_and(S1, x5);
                                                            x16 = porta_and_3(x5, S2, S3);
                                                            x17 = porta_and_3(A3, B3, S3);
                                                            x18 = porta_or_3(A0, x6, x7);
                                                            x19 = porta_not(x18);
                                                            x20 = porta_or(x8, x9);
                                                            x21 = porta_not(x20);
                                                            x22 = porta_or_3(A1, x10, x11);
                                                            x23 = porta_not(x22);
                                                            x24 = porta_or(x12, x13);
                                                            x25 = porta_not(x24);
                                                            x26 = porta_or_3(A2, x14, x15);
                                                            x27 = porta_not(x26);
                                                            x28 = porta_or(x12, x13);
                                                            x29 = porta_not(x28);
                                                            x30 = porta_or_3(A3, x14, x15);
                                                            x31 = porta_not(x30);
                                                            x32 = porta_or(x16, x17);
                                                            x33 = porta_not(x32);
                                                            x34 = porta_and(Cn, x1);
                                                            x35 = porta_not(x34);
                                                            x36 = porta_not(x18);
                                                            x37 = porta_and(x1, x18);
                                                            x38 = porta_and_3(x1, x19, Cn);


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
