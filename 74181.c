#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

int BIN_DEC_DECODER(const char *binario) {
    int decimale = 0;
    int lunghezza = strlen(binario);
    for ( int i = 0; i < lunghezza; i++) {
        if (binario[i] == '1') {
            decimale = decimale * 2 + 1;
        } else if ( binario[i] == '0') {
            decimale = decimale * 2;
        } else {
            printf("Input non valido. Solo 0 e 1 sono accettati.\n");
            return -1;
        }
    }
    return decimale;
}
int DEC_BIN_CODER(int numero) {
    int binario[33];
    int i = 0;
    if (numero == 0) {
        printf("0");
        return;
    }
    while (numero > 0) {
        binario[i] = numero % 2;
        numero = numero / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
}
int memoria[10];
int indice_memoria = 0;
void salva_in_memoria(int valore) {
    if (indice_memoria < 10) {
        memoria[indice_memoria++] = valore;
    } else {
        printf("[!] Memoria piena!\n");
    }
}
void attendi_un_ciclo_clock() {
    clock_t start_time = clock();
    clock_t current_time;
    do {
        current_time = clock();
    } while ((current_time - start_time) < CLOCKS_PER_SEC / 1000);
}
void stampa_memoria() {
    printf("Contenuto della memoria:\n");
    for (int i = 0; i < indice_memoria; i++) {
        printf("Memoria[%d] = %-3d\n", i, memoria[i]);
    }
}
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

void n_ALU74181(int Cn, int M, int A[4], int B[4], int S[4],
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
int not_nand03 = porta_not(nand03);
int not_nor004 = porta_not(nor004);
int or0001 = porta_or(not_nand03, not_nor004);
*Cn_piu_4 = or0001;
*G = nor004;
}
void stampa_tabella_verita_74181() {
    printf("\n");
    printf("╔════╦════╦════╦════╦════╦══════════════════════════════════════════════╗\n║ S3 ║ S2 ║ S1 ║ S0 ║ Cn ║               Operazione ALU 74181           ║\n╠════╬════╬════╬════╬════╬══════════════════════════════════════════════╣\n║  0 ║  0 ║  0 ║  0 ║  0 ║ F = A - 1           | M = 0 (Aritmetico)     ║\n║  0 ║  0 ║  0 ║  1 ║  0 ║ F = A + B           | M = 0 (Aritmetico)     ║\n║  0 ║  0 ║  1 ║  0 ║  0 ║ F = A + B̄           | M = 0 (Aritmetico)     ║\n║  0 ║  0 ║  1 ║  1 ║  0 ║ F = -1              | M = 0 (Aritmetico)     ║\n║  0 ║  1 ║  0 ║  0 ║  0 ║ F = A + B̄           | M = 0 (Aritmetico)     ║\n║  0 ║  1 ║  0 ║  1 ║  0 ║ F = A + B           | M = 0 (Aritmetico)     ║\n║  0 ║  1 ║  1 ║  0 ║  0 ║ F = A - B           | M = 0 (Aritmetico)     ║\n║  0 ║  1 ║  1 ║  1 ║  0 ║ F = A·B - 1         | M = 0 (Aritmetico)     ║\n║  1 ║  0 ║  0 ║  0 ║  0 ║ F = A + B̄           | M = 0 (Aritmetico)     ║\n║  1 ║  0 ║  0 ║  1 ║  0 ║ F = A + B̄ + 0       | M = 0 (Aritmetico)     ║\n║  1 ║  0 ║  1 ║  0 ║  0 ║ F = A + B̄           | M = 0 (Aritmetico)     ║\n║  1 ║  0 ║  1 ║  1 ║  0 ║ F = A·B + 0         | M = 0 (Aritmetico)     ║\n║  1 ║  1 ║  0 ║  0 ║  0 ║ F = A + B̄           | M = 0 (Aritmetico)     ║\n║  1 ║  1 ║  0 ║  1 ║  0 ║ F = A + B̄ + 0       | M = 0 (Aritmetico)     ║\n║  1 ║  1 ║  1 ║  0 ║  0 ║ F = A + B̄           | M = 0 (Aritmetico)     ║\n║  1 ║  1 ║  1 ║  1 ║  0 ║ F = A · B           | M = 0 (Aritmetico)     ║\n╠════╬════╬════╬════╬════╬══════════════════════════════════════════════╣\n║  0 ║  0 ║  0 ║  0 ║  1 ║ F = A - 1 + Cn      | M = 0 (Aritmetico)     ║\n║  0 ║  0 ║  0 ║  1 ║  1 ║ F = A + B + Cn      | M = 0 (Aritmetico)     ║\n║  0 ║  0 ║  1 ║  0 ║  1 ║ F = A + B̄ + Cn      | M = 0 (Aritmetico)     ║\n║  0 ║  0 ║  1 ║  1 ║  1 ║ F = -1 + Cn         | M = 0 (Aritmetico)     ║\n║  0 ║  1 ║  0 ║  0 ║  1 ║ F = A + B̄ + Cn      | M = 0 (Aritmetico)     ║\n║  0 ║  1 ║  0 ║  1 ║  1 ║ F = A + B + Cn      | M = 0 (Aritmetico)     ║\n║  0 ║  1 ║  1 ║  0 ║  1 ║ F = A - B + Cn      | M = 0 (Aritmetico)     ║\n║  0 ║  1 ║  1 ║  1 ║  1 ║ F = A·B - 1 + Cn    | M = 0 (Aritmetico)     ║\n║  1 ║  0 ║  0 ║  0 ║  1 ║ F = A + B̄ + Cn      | M = 0 (Aritmetico)     ║\n║  1 ║  0 ║  0 ║  1 ║  1 ║ F = A + B̄ + Cn      | M = 0 (Aritmetico)     ║\n║  1 ║  0 ║  1 ║  0 ║  1 ║ F = A + B̄ + Cn      | M = 0 (Aritmetico)     ║\n║  1 ║  0 ║  1 ║  1 ║  1 ║ F = A·B + Cn        | M = 0 (Aritmetico)     ║\n║  1 ║  1 ║  0 ║  0 ║  1 ║ F = A + B̄ + Cn      | M = 0 (Aritmetico)     ║\n║  1 ║  1 ║  0 ║  1 ║  1 ║ F = A + B̄ + Cn      | M = 0 (Aritmetico)     ║\n║  1 ║  1 ║  1 ║  0 ║  1 ║ F = A + B̄ + Cn      | M = 0 (Aritmetico)     ║\n║  1 ║  1 ║  1 ║  1 ║  1 ║ F = A · B + Cn      | M = 0 (Aritmetico)     ║\n╠════╬════╬════╬════╬════╬══════════════════════════════════════════════╣\n║  0 ║  0 ║  0 ║  0 ║  X ║ F = A               | M = 1 (Logico)         ║\n║  0 ║  0 ║  0 ║  1 ║  X ║ F = AB              | M = 1 (Logico)         ║\n║  0 ║  0 ║  1 ║  0 ║  X ║ F = A + B̄           | M = 1 (Logico)         ║\n║  0 ║  0 ║  1 ║  1 ║  X ║ F = 1               | M = 1 (Logico)         ║\n║  0 ║  1 ║  0 ║  0 ║  X ║ F = A · B̄           | M = 1 (Logico)         ║\n║  0 ║  1 ║  0 ║  1 ║  X ║ F = A ⊕ B           | M = 1 (Logico)         ║\n║  0 ║  1 ║  1 ║  0 ║  X ║ F = A · B̄           | M = 1 (Logico)         ║\n║  0 ║  1 ║  1 ║  1 ║  X ║ F = A · B̄           | M = 1 (Logico)         ║\n║  1 ║  0 ║  0 ║  0 ║  X ║ F = Ā               | M = 1 (Logico)         ║\n║  1 ║  0 ║  0 ║  1 ║  X ║ F = Ā               | M = 1 (Logico)         ║\n║  1 ║  0 ║  1 ║  0 ║  X ║ F = Ā               | M = 1 (Logico)         ║\n║  1 ║  0 ║  1 ║  1 ║  X ║ F = Ā               | M = 1 (Logico)         ║\n║  1 ║  1 ║  0 ║  0 ║  X ║ F = Ā + B̄           | M = 1 (Logico)         ║\n║  1 ║  1 ║  0 ║  1 ║  X ║ F = Ā + B̄           | M = 1 (Logico)         ║\n║  1 ║  1 ║  1 ║  0 ║  X ║ F = Ā + B̄           | M = 1 (Logico)         ║\n║  1 ║  1 ║  1 ║  1 ║  X ║ F = 0               | M = 1 (Logico)         ║\n╚════╩════╩════╩════╩════╩══════════════════════════════════════════════╝\n\nSimboli speciali:\n• B̄ = NOT di B\n• Ā = NOT di A\n• X = Indifferente (non usato)\n");
}
 void simula_alu_74181() {
    int Cn, M, A0, B0, A1, B1, A2, B2, A3, B3, S0, S1, S2, S3;
    char scelta[3];
    printf("Inserire dati manualmente? (S/N): ");
    scanf("%s", scelta);
    scelta[0] = toupper(scelta[0]);
    if (scelta[0] == 'S') {
        printf(">> Inserisci i valori degli input (0 o 1):\n");
        printf(">> Cn: ");
        scanf("%d", &Cn);
        if (Cn == 0){}else if(Cn == 1){}else {
            printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      Cn deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");
            return;
        }
        printf(">> M:  ");
        scanf("%d", &M);
        if (M == 0){}else if(M == 1){}else {
            printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║       M deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");
            return;
        }
        printf(">> A0: ");
        scanf("%d", &A0);
        if (A0 == 0){}else if(A0 == 1){}else {
            printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      A0 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");
            return;
        }
        printf(">> B0: ");
        scanf("%d", &B0);
        if (B0 == 0){}else if(B0 == 1){}else {
            printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      B0 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");
            return;
        }
        printf(">> A1: ");
        scanf("%d", &A1);
        if (A1 == 0){}else if(A1 == 1){}else {
            printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      A1 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");
            return;
        }
        printf(">> B1: ");
        scanf("%d", &B1);
        if (B1 == 0){}else if(B1 == 1){}else {
            printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      B1 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");
            return;
        }
        printf(">> A2: ");
        scanf("%d", &A2);
        if (A2 == 0){}else if(A2 == 1){}else {
            printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      A2 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");
            return;
        }
        printf(">> B2: ");
        scanf("%d", &B2);
        if (B2 == 0){}else if(B2 == 1){}else {
            printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      B2 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");
            return;
        }
        printf(">> A3: ");
        scanf("%d", &A3);
        if (A3 == 0){}else if(A3 == 1){}else {
            printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      A3 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");
            return;
        }
        printf(">> B3: ");
        scanf("%d", &B3);
        if (B3 == 0){}else if(B3 == 1){}else {
            printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      B3 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");
            return;
        }
        printf(">> S0: ");
        scanf("%d", &S0);
        if (S0 == 0){}else if(S0 == 1){}else {
            printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      S0 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");
            return;
        }
        printf(">> S1: ");
        scanf("%d", &S1);
        if (S1 == 0){}else if(S1 == 1){}else {
            printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      S1 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");
            return;
        }
        printf(">> S2: ");
        scanf("%d", &S2);
        if (S2 == 0){}else if(S2 == 1){}else {
            printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      S2 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");
            return;
        }
        printf(">> S3: ");
        scanf("%d", &S3);
        if (S3 == 0){}else if(S3 == 1){}else {
            printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      S3 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n");
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
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_Cn = sscanf(line, "%*[^<]<%d>", &Cn);
        if (sscanf_result_Cn == 1) {} else { printf("ERRORE: Valore non valido in Cn\n"); fclose(file); return; }
        if (Cn == 0) {} else if (Cn == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      Cn deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_M = sscanf(line, "%*[^<]<%d>", &M);
        if (sscanf_result_M == 1) {} else { printf("ERRORE: Valore non valido in M\n"); fclose(file); return; }
        if (M == 0) {} else if (M == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║       M deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_A0 = sscanf(line, "%*[^<]<%d>", &A0);
        if (sscanf_result_A0 == 1) {} else { printf("ERRORE: Valore non valido in A0\n"); fclose(file); return; }
        if (A0 == 0) {} else if (A0 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      A0 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_B0 = sscanf(line, "%*[^<]<%d>", &B0);
        if (sscanf_result_B0 == 1) {} else { printf("ERRORE: Valore non valido in B0\n"); fclose(file); return; }
        if (B0 == 0) {} else if (B0 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      B0 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_A1 = sscanf(line, "%*[^<]<%d>", &A1);
        if (sscanf_result_A1 == 1) {} else { printf("ERRORE: Valore non valido in A1\n"); fclose(file); return; }
        if (A1 == 0) {} else if (A1 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      A1 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_B1 = sscanf(line, "%*[^<]<%d>", &B1);
        if (sscanf_result_B1 == 1) {} else { printf("ERRORE: Valore non valido in B1\n"); fclose(file); return; }
        if (B1 == 0) {} else if (B1 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      B1 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_A2 = sscanf(line, "%*[^<]<%d>", &A2);
        if (sscanf_result_A2 == 1) {} else { printf("ERRORE: Valore non valido in A2\n"); fclose(file); return; }
        if (A2 == 0) {} else if (A2 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      A2 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_B2 = sscanf(line, "%*[^<]<%d>", &B2);
        if (sscanf_result_B2 == 1) {} else { printf("ERRORE: Valore non valido in B2\n"); fclose(file); return; }
        if (B2 == 0) {} else if (B2 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      B2 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_A3 = sscanf(line, "%*[^<]<%d>", &A3);
        if (sscanf_result_A3 == 1) {} else { printf("ERRORE: Valore non valido in A3\n"); fclose(file); return; }
        if (A3 == 0) {} else if (A3 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      A3 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_B3 = sscanf(line, "%*[^<]<%d>", &B3);
        if (sscanf_result_B3 == 1) {} else { printf("ERRORE: Valore non valido in B3\n"); fclose(file); return; }
        if (B3 == 0) {} else if (B3 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      B3 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_S0 = sscanf(line, "%*[^<]<%d>", &S0);
        if (sscanf_result_S0 == 1) {} else { printf("ERRORE: Valore non valido in S0\n"); fclose(file); return; }
        if (S0 == 0) {} else if (S0 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      S0 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_S1 = sscanf(line, "%*[^<]<%d>", &S1);
        if (sscanf_result_S1 == 1) {} else { printf("ERRORE: Valore non valido in S1\n"); fclose(file); return; }
        if (S1 == 0) {} else if (S1 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      S1 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }
        if (fgets(line, sizeof(line), file) == NULL) { printf("ERRORE: Formato file incompleto\n"); fclose(file); return; }
        int sscanf_result_S2 = sscanf(line, "%*[^<]<%d>", &S2);
        if (sscanf_result_S2 == 1) {} else { printf("ERRORE: Valore non valido in S2\n"); fclose(file); return; }
        if (S2 == 0) {} else if (S2 == 1) {} else { printf("╔════════════════════════════════╗\n║            ERRORE              ║\n╠════════════════════════════════╣\n║                                ║\n║      S2 deve essere 0 o 1      ║\n║                                ║\n╚════════════════════════════════╝\n"); return; }
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
    n_ALU74181(Cn, M, A, B, S, F, &A_uguale_B, &P, &Cn_piu_4, &G);
    printf("\n");
    printf("╔═════════════════════════════════════════════╗\n║           RISULTATI ALU 74181               ║\n╠═════════════════════════════════════════════╣\n║                                             ║\n║  - F0      = %-3d                            ║\n║  - F1      = %-3d                            ║\n║  - A = B   = %-3d                            ║\n║  - F2      = %-3d                            ║\n║  - F3      = %-3d                            ║\n║  - P       = %-3d                            ║\n║  - Cn + 4  = %-3d                            ║\n║  - G       = %-3d                            ║\n║                                             ║\n╚═════════════════════════════════════════════╝\n",F[0],F[1],A_uguale_B,F[2],F[3],P,Cn_piu_4,G);
    salva_in_memoria(Cn_piu_4);
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
    sleep(2);
    stampa_tabella_verita_74181();
}

 void ALU32() {
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
        n_ALU74181(currentCn, M, Abits, Bbits, S, F, &A_uguale_B, &P, &Cn_piu_4, &G);
        unsigned int nibbleResult = (F[0] << 0) | (F[1] << 1) | (F[2] << 2) | (F[3] << 3);
        result |= (nibbleResult << (nibble * 4));
        currentCn = Cn_piu_4;
    }
    printf("Risultato ALU PIPO a 32 bit (decimale): %u\n", result);
    salva_in_memoria(result);
}

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
        printf(">> Scegli l'operazione (1 - Somma, 2 - Sottrazione, 3 - Moltiplicazione, 4 - Divisione): ");
        scanf("%s", operazione);

        int scelta = 0;

        // Verifica se è stato inserito un numero
        if (strlen(operazione) == 1 && isdigit(operazione[0])) {
            scelta = operazione[0] - '0';
        } else {
            // Converte in minuscolo per confronto case-insensitive
            for (int i = 0; operazione[i]; i++) {
                operazione[i] = tolower(operazione[i]);
            }

            if (strcmp(operazione, "somma") == 0)
                scelta = 1;
            else if (strcmp(operazione, "sottrazione") == 0)
                scelta = 2;
            else if (strcmp(operazione, "moltiplicazione") == 0)
                scelta = 3;
            else if (strcmp(operazione, "divisione") == 0)
                scelta = 4;
        }

        switch (scelta) {
            case 1:
                if (strcmp(operazione, "somma") != 0) break; // solo per sicurezza
                {
                    int res = somma(a, b);
                    printf("╔════════════════════════════════╗\n║         SOMMA ALGEBRICA        ║\n╚════════════════════════════════╝\nRisultato: %d\n", res);
                    salva_in_memoria(res);
                }
                break;
            case 2:
                {
                    int res = sottrazione(a, b);
                    printf("╔════════════════════════════════╗\n║      SOTTRAZIONE ALGEBRICA     ║\n╚════════════════════════════════╝\nRisultato: %d\n", res);
                    salva_in_memoria(res);
                }
                break;
            case 3:
                {
                    int res = moltiplicazione(a, b);
                    printf("╔════════════════════════════════╗\n║    MOLTIPLICAZIONE ALGEBRICA   ║\n╚════════════════════════════════╝\nRisultato: %d\n", res);
                    salva_in_memoria(res);
                }
                break;
            case 4:
                {
                    if (b == 0) {
                        printf("Errore: divisione per zero.\n");
                    } else {
                        int res = divisione(a, b);
                        printf("╔════════════════════════════════╗\n║        DIVISIONE ALGEBRICA     ║\n╚════════════════════════════════╝\nRisultato: %d\n", res);
                        salva_in_memoria(res);
                    }
                }
                break;
            default:
                printf("╔════════════════════════════════╗\n║             ERRORE             ║\n╠════════════════════════════════╣\n║                                ║\n║   Operazione non riconosciuta  ║\n║                                ║\n╚════════════════════════════════╝\n");
                return;
        }

    } else if (num_elementi == 3) {
        int a, b, c;
        printf(">> Inserisci i tre numeri: ");
        scanf("%d %d %d", &a, &b, &c);

        char operazione[20];
        printf(">> Scegli l'operazione (somma o moltiplicazione): ");
        scanf("%s", operazione);
        int scelta = 0;
        if (strlen(operazione) == 1 && isdigit(operazione[0])) {
            scelta = operazione[0] - '0';
        } else {
            for (int i = 0; operazione[i]; i++) {
                operazione[i] = tolower(operazione[i]);
            }
            if (strcmp(operazione, "somma") == 0)
                scelta = 1;
            else if (strcmp(operazione, "moltiplicazione") == 0)
                scelta = 3;
        }
        switch (scelta) {
            case 1:
                {
                    int res = somma(somma(a, b), c);
                    printf("╔════════════════════════════════╗\n║         SOMMA ALGEBRICA        ║\n╚════════════════════════════════╝\nRisultato: %d\n", res);
                    salva_in_memoria(res);
                }
                break;
            case 3:
                {
                    int res = moltiplicazione(moltiplicazione(a, b), c);
                    printf("╔════════════════════════════════╗\n║    MOLTIPLICAZIONE ALGEBRICA   ║\n╚════════════════════════════════╝\nRisultato: %d\n", res);
                    salva_in_memoria(res);
                }
                break;
            default:
                printf("╔════════════════════════════════╗\n║             ERRORE             ║\n╠════════════════════════════════╣\n║                                ║\n║   Operazione non riconosciuta  ║\n║                                ║\n╚════════════════════════════════╝\n");
                return;
        }

    } else {
        printf("╔════════════════════════════════╗\n║             ERRORE             ║\n╠════════════════════════════════╣\n║                                ║\n║ Numero di elementi non valido. ║\n║      Scegli tra 2 oppure 3     ║\n║                                ║\n╚════════════════════════════════╝\n");
    }
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
        attendi_un_ciclo_clock();
    }
    printf("\nSimulazione completata.\nUn ciclo di clock richiede circa 1 millisecondo in questa simulazione.\nQuesto è solo un valore stimato. La CPU reale lavora molto più velocemente!\n");
    return;
}
int main() {
    int scelta;
    while (1) {
        printf("\n╔════════════════════════════════════════════════════════╗\n║                    MENU PRINCIPALE                     ║\n╠════════════════════════════════════════════════════════╣\n║  1. Operazioni Logiche (ALU 74181 - Singolo)           ║\n║  2. Operazioni Logiche (ALU 74181 - Singolo con clock) ║\n║  3. Operazioni Algebriche                              ║\n║  4. Convertitore Binario → Decimale                    ║\n║  5. Convertitore Decimale → Binario                    ║\n║  6. ALU in Modalità PIPO (32 bit - 8x74181)            ║\n║  7. ALU in Modalità PIPO (32 bit - 8x74181 con clock)  ║\n║  8. Visualizza Memoria                                 ║\n║  9. Calcolo del Clock                                  ║\n║  0. Esci                                               ║\n╚════════════════════════════════════════════════════════╝\n>> Inserisci la tua scelta: ");
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
            char bin[33];
            printf(">> Inserisci un numero binario: ");
            scanf("%32s", bin);
            printf("Risultato (decimale): %d\n", BIN_DEC_DECODER(bin));
        } else if (scelta == 5) {
            int dec;
            printf(">> Inserisci un numero decimale: ");
            scanf("%d", &dec);
            printf("Risultato (binario): %d\n", DEC_BIN_CODER(dec));
        } else if (scelta == 6) {
            ALU32();
        } else if (scelta == 7) {
            attendi_un_ciclo_clock();
            ALU32();
        } else if (scelta == 8) {
            stampa_memoria();
        } else if (scelta == 9) {
            misura_ciclo_clock();
        } else {
            printf("Scelta non valida!\n");
        }
        sleep(6);
    }

    return 0;
}