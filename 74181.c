#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  ================= Conversioni =================

  Queste funzioni servono a convertire numeri:
  - binario_a_decimale: converte un numero formato da cifre binarie (0 e 1)
    in un numero decimale.
  - decimale_a_binario: converte un numero decimale in una rappresentazione
    "binaria" (una sequenza di bit, rappresentata come intero).
*/
int binario_a_decimale(int bin) {
    int dec = 0, base = 1, resto;
    while (bin > 0) {
        // Preleva l'ultima cifra del numero
        resto = bin % 10;
        // Riduce il numero rimuovendo l'ultima cifra
        bin = bin / 10;
        // Aggiunge alla somma il valore della cifra (visti come bit) moltiplicato
        // per la potenza di 2 corrispondente
        dec += resto * base;
        // Aggiorna la base: 1, 2, 4, 8, ...
        base *= 2;
    }
    return dec;
}

int decimale_a_binario(int dec) {
    int bin = 0, base = 1, resto;
    while (dec > 0) {
        // Ottiene il resto della divisione per 2 (0 o 1)
        resto = dec % 2;
        dec = dec / 2;
        // Costruisce il numero binario posizionando il bit nella posizione corretta
        bin += resto * base;
        base *= 10;
    }
    return bin;
}

/*
  ================= Memoria =================

  Queste variabili e funzioni gestiscono la "memoria" in cui salvare i risultati.
  - memoria: array globale per contenere fino a 10 risultati.
  - indice_memoria: indice dell'array per inserire un nuovo valore.
  
  Le funzioni:
  - salva_in_memoria: salva un nuovo risultato, se c'è spazio.
  - stampa_memoria: mostra a video tutti i risultati salvati.
*/
int memoria[10];
int indice_memoria = 0;

void salva_in_memoria(int valore) {
    if (indice_memoria < 10) {
        memoria[indice_memoria++] = valore;
    } else {
        printf("Memoria piena!\n");
    }
}

void stampa_memoria() {
    printf("Contenuto della memoria:\n");
    for (int i = 0; i < indice_memoria; i++) {
        printf("Memoria[%d] = %d\n", i, memoria[i]);
    }
}

/*
  ================= Porte Logiche =================

  Queste funzioni simulano le porte logiche fondamentali usate nell'ALU:
  - porta_not: Inverte il segnale (0 diventa 1, 1 diventa 0).
  - porta_and: Esegue l'AND sui due input.
  - porta_or: Esegue l'OR sui due input, implementata in modo
    da gestire l'operazione logica.
  - porta_exor: Esegue l'operazione XOR (somma modulo 2).
  
  Sono inoltre definite versioni che combinano 3, 4 o 5 ingressi (ad esempio:
  porta_or_3, porta_and_4, ecc.) per semplificare operazioni logiche multiple.
*/
int porta_not(int a) { 
    return 1 - a; 
}

int porta_and(int a, int b) { 
    return a * b; 
}

int porta_or(int a, int b) { 
    // Somma logica meno il caso in cui entrambi i valori sono 1
    return (a + b) - (a * b); 
}

int porta_exor(int a, int b) { 
    // XOR: somma modulo 2 (sottrai due volte il prodotto per eliminare il doppio 1)
    return (a + b) - 2 * (a * b); 
}

// OR per 3, 4 e 5 ingressi
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

// AND per 3, 4 e 5 ingressi
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

// EXOR per 3, 4 e 5 ingressi
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
  ================= Funzione ALU 74181 per un nibble =================

  Questa funzione simula il funzionamento di una ALU 74181 su 4 bit (un nibble).
  Parametri:
    - Cn       : Carry in iniziale.
    - M        : Modalità (seleziona operazione logica o aritmetica).
    - A[4]     : Array con i 4 bit dell'operando A (bit 0 = LSB, bit 3 = MSB).
    - B[4]     : Array con i 4 bit dell'operando B.
    - S[4]     : Array dei segnali di selezione dell'operazione.
  
  Output:
    - F[4]     : Array con i 4 bit del risultato.
    - A_uguale_B, P, Cn_piu_4, G: Flag derivati dalla logica interna dell'ALU.
  
  La funzione riproduce i calcoli logici dell'ALU combinando porte AND, OR, NOT ed XOR.
*/
void alu_74181_calcola(int Cn, int M, int A[4], int B[4], int S[4],
                         int F[4], int *A_uguale_B, int *P, int *Cn_piu_4, int *G) {
    // Calcoli intermedi per creare le combinazioni logiche richieste dal circuito
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
    
    // Calcola operazioni logiche interne (varie combinazioni di porte OR, NOT, etc.)
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
    
    // Gli output F[0]..F[3] sono i 4 bit del risultato
    F[0] = exor0001;
    F[1] = exor0002;
    F[2] = exor0003;
    F[3] = exor0004;
    
    // Flag aggiuntivi calcolati dall'ALU:
    // A_uguale_B: vero (1) se tutti i bit in F sono uguali
    *A_uguale_B = porta_and_4(exor0001, exor0002, exor0003, exor0004);
    // P, Cn_piu_4, G: altri segnali derivati dalla logica del circuito
    *P = nand02;
    int or0001 = porta_or(porta_not(nand03), porta_not(nor004));
    *Cn_piu_4 = or0001;
    *G = nor004;
}

/*
  ================= Simulazione ALU 74181 (Modulo Singolo) =================

  Questa funzione chiede all'utente di inserire i segnali (0 o 1) per:
    - Carry in (Cn)
    - Modalità (M)
    - I 4 bit dell'operando A (A0, A1, A2, A3)
    - I 4 bit dell'operando B (B0, B1, B2, B3)
    - I 4 bit di selezione dell'operazione (S0, S1, S2, S3)

  Per ogni segnale viene controllato, tramite if annidati, che il valore sia 0 o 1.
  Successivamente, vengono creati gli array A, B e S e chiamata la funzione
  alu_74181_calcola() per eseguire il calcolo. Infine, vengono stampati i risultati
  e un flag (ad es. Cn_piu_4) viene salvato in memoria.
*/
void simula_alu_74181() {
    int Cn, M, A0, B0, A1, B1, A2, B2, A3, B3, S0, S1, S2, S3;
    printf("Inserisci i valori degli input (0 o 1):\n");
    
    // Lettura e controllo del segnale Cn
    printf("Cn: "); scanf("%d", &Cn);
    if (Cn == 0) { /* ok */ }
    else { if (Cn == 1) { } else { printf("[!] ERRORE: Cn deve essere 0 o 1.\n"); return; } }
    
    // Lettura e controllo del segnale M
    printf("M:  "); scanf("%d", &M);
    if (M == 0) { } else { if (M == 1) { } else { printf("[!] ERRORE: M deve essere 0 o 1.\n"); return; } }
    
    // Lettura e controllo per ciascun bit dei nibble A e B e per i segnali S
    printf("A0: "); scanf("%d", &A0);
    if (A0 == 0) { } else { if (A0 == 1) { } else { printf("[!] ERRORE: A0 deve essere 0 o 1.\n"); return; } }
    
    printf("B0: "); scanf("%d", &B0);
    if (B0 == 0) { } else { if (B0 == 1) { } else { printf("[!] ERRORE: B0 deve essere 0 o 1.\n"); return; } }
    
    printf("A1: "); scanf("%d", &A1);
    if (A1 == 0) { } else { if (A1 == 1) { } else { printf("[!] ERRORE: A1 deve essere 0 o 1.\n"); return; } }
    
    printf("B1: "); scanf("%d", &B1);
    if (B1 == 0) { } else { if (B1 == 1) { } else { printf("[!] ERRORE: B1 deve essere 0 o 1.\n"); return; } }
    
    printf("A2: "); scanf("%d", &A2);
    if (A2 == 0) { } else { if (A2 == 1) { } else { printf("[!] ERRORE: A2 deve essere 0 o 1.\n"); return; } }
    
    printf("B2: "); scanf("%d", &B2);
    if (B2 == 0) { } else { if (B2 == 1) { } else { printf("[!] ERRORE: B2 deve essere 0 o 1.\n"); return; } }
    
    printf("A3: "); scanf("%d", &A3);
    if (A3 == 0) { } else { if (A3 == 1) { } else { printf("[!] ERRORE: A3 deve essere 0 o 1.\n"); return; } }
    
    printf("B3: "); scanf("%d", &B3);
    if (B3 == 0) { } else { if (B3 == 1) { } else { printf("[!] ERRORE: B3 deve essere 0 o 1.\n"); return; } }
    
    printf("S0: "); scanf("%d", &S0);
    if (S0 == 0) { } else { if (S0 == 1) { } else { printf("[!] ERRORE: S0 deve essere 0 o 1.\n"); return; } }
    
    printf("S1: "); scanf("%d", &S1);
    if (S1 == 0) { } else { if (S1 == 1) { } else { printf("[!] ERRORE: S1 deve essere 0 o 1.\n"); return; } }
    
    printf("S2: "); scanf("%d", &S2);
    if (S2 == 0) { } else { if (S2 == 1) { } else { printf("[!] ERRORE: S2 deve essere 0 o 1.\n"); return; } }
    
    printf("S3: "); scanf("%d", &S3);
    if (S3 == 0) { } else { if (S3 == 1) { } else { printf("[!] ERRORE: S3 deve essere 0 o 1.\n"); return; } }
    
    // Costruzione degli array per i nibble A, B e per i segnali S
    int A[4] = {A0, A1, A2, A3};
    int B[4] = {B0, B1, B2, B3};
    int S[4] = {S0, S1, S2, S3};
    int F[4]; // Array che conterrà il risultato a 4 bit
    int A_uguale_B, P, Cn_piu_4, G; // Flag di output
    
    // Esegue il calcolo dell'ALU sul modulo a 4 bit
    alu_74181_calcola(Cn, M, A, B, S, F, &A_uguale_B, &P, &Cn_piu_4, &G);
    
    // Stampa il risultato ottenuto e i flag calcolati
    printf("___________________________________________\n");
    printf("|         Risultati ALU 74181             |\n");
    printf("|_________________________________________|\n");
    printf("| F0       = %d                         |\n", F[0]);
    printf("| F1       = %d                         |\n", F[1]);
    printf("| A = B    = %d                         |\n", A_uguale_B);
    printf("| F2       = %d                         |\n", F[2]);
    printf("| F3       = %d                         |\n", F[3]);
    printf("| P        = %d                         |\n", P);
    printf("| Cn + 4   = %d                         |\n", Cn_piu_4);
    printf("| G        = %d                         |\n", G);
    printf("|_________________________________________|\n");
    
    // Salva in memoria uno dei flag (ad es. Cn_piu_4)
    salva_in_memoria(Cn_piu_4);
}

/*
  ================= ALU in Modalità PIPO (8 moduli in cascata) =================

  Questa funzione simula una ALU a 32 bit realizzata mediante 8 moduli ALU 74181,
  ciascuno a 4 bit (nibble). Funziona come segue:
    1. L'utente inserisce due operandi a 32 bit (in formato decimale).
    2. L'utente inserisce i segnali comuni (Cn, M e S0-S3) da utilizzare per tutti i moduli.
    3. Il codice estrae da ciascun operando i nibble (gruppi di 4 bit), partendo dal nibble
       meno significativo fino al nibble più significativo.
    4. Per ogni nibble viene chiamata la funzione alu_74181_calcola() passando il carry in attuale;
       il risultato (4 bit) viene poi combinato nel risultato finale a 32 bit.
    5. Il carry out (Cn_piu_4) del modulo corrente viene propagato come carry in per il modulo successivo.
    6. Infine, il risultato finale viene stampato e salvato in memoria.
*/
void alu_pipo_8() {
    unsigned int opA, opB;
    int Cn, M;
    int S[4];
    
    // Lettura degli operandi a 32 bit (in formato decimale)
    printf("Inserisci il primo operando (numero decimale a 32 bit): ");
    scanf("%u", &opA);
    printf("Inserisci il secondo operando (numero decimale a 32 bit): ");
    scanf("%u", &opB);
    
    // Lettura del segnale di Carry In
    printf("Inserisci il segnale di Carry In (Cn, 0 o 1): ");
    scanf("%d", &Cn);
    if (Cn == 0) { /* ok */ }
    else { if (Cn == 1) { } else { printf("[!] ERRORE: Cn deve essere 0 o 1.\n"); return; } }
    
    // Lettura del segnale M (modalità)
    printf("Inserisci il segnale M (0 o 1): ");
    scanf("%d", &M);
    if (M == 0) { } else { if (M == 1) { } else { printf("[!] ERRORE: M deve essere 0 o 1.\n"); return; } }
    
    // Lettura dei segnali di selezione S0, S1, S2, S3 (tutti 0 o 1)
    printf("Inserisci i segnali di selezione S0, S1, S2, S3 (0 o 1, separati da spazi): ");
    scanf("%d %d %d %d", &S[0], &S[1], &S[2], &S[3]);
    for (int i = 0; i < 4; i++) {
        if (S[i] == 0) { /* ok */ }
        else { if (S[i] == 1) { /* ok */ } else { 
            printf("[!] ERRORE: S%d deve essere 0 o 1.\n", i);
            return;
        } }
    }
    
    unsigned int result = 0;  // Variabile per il risultato finale a 32 bit
    int currentCn = Cn;       // Carry in corrente, inizialmente quello inserito
    int F[4];               // Array per il risultato di ciascun modulo a 4 bit
    int A_uguale_B, P, Cn_piu_4, G;  // Flag di uscita per ogni modulo
    
    // Elaborazione per ciascun nibble (8 moduli in totale)
    for (int nibble = 0; nibble < 8; nibble++) {
        int Abits[4], Bbits[4];
        // Estrae i 4 bit (nibble) corrispondenti dal primo e dal secondo operando
        for (int bit = 0; bit < 4; bit++) {
            Abits[bit] = (opA >> (nibble * 4 + bit)) & 1;
            Bbits[bit] = (opB >> (nibble * 4 + bit)) & 1;
        }
        // Calcola il risultato per questo nibble utilizzando l'ALU 74181
        // Il carry in corrente viene passato a ciascun modulo
        alu_74181_calcola(currentCn, M, Abits, Bbits, S, F, &A_uguale_B, &P, &Cn_piu_4, &G);
        
        // Combina i 4 bit di output ottenuti in un nibble (F[0] = bit0, F[1] = bit1, ecc.)
        unsigned int nibbleResult = (F[0] << 0) | (F[1] << 1) | (F[2] << 2) | (F[3] << 3);
        // Posiziona il nibble nel risultato finale secondo la sua posizione
        result |= (nibbleResult << (nibble * 4));
        
        // Propaga il carry out come nuovo carry in per il modulo successivo
        currentCn = Cn_piu_4;
    }
    
    // Stampa il risultato finale a 32 bit in formato decimale
    printf("Risultato ALU PIPO a 32 bit (decimale): %u\n", result);
    // Salva il risultato in memoria
    salva_in_memoria(result);
}

/*
  ================= Operazioni Algebriche =================

  Queste funzioni implementano le operazioni aritmetiche di base:
    - somma: restituisce la somma di due numeri.
    - sottrazione: restituisce la differenza tra due numeri.
    - moltiplicazione: restituisce il prodotto di due numeri.
    - divisione: restituisce il quoziente, con controllo per la divisione per 0.
  
  La funzione operazioni_algebriche() permette all'utente di scegliere:
    - Operazioni su 2 elementi: somma, sottrazione, moltiplicazione, divisione.
    - Operazioni su 3 elementi: supporta somma o moltiplicazione.
*/
int somma(int a, int b) { return a + b; }
int sottrazione(int a, int b) { return a - b; }
int moltiplicazione(int a, int b) { return a * b; }
int divisione(int a, int b) {
    if (b == 0) {
        printf("[!] ERRORE: Divisione per zero.\n");
        return 0;
    }
    return a / b;
}

void operazioni_algebriche() {
    int num_elementi;
    printf("Quanti elementi vuoi utilizzare (2 o 3)? ");
    scanf("%d", &num_elementi);
    if (num_elementi == 2) {
        int a, b;
        printf("Inserisci i due numeri: ");
        scanf("%d %d", &a, &b);
        char operazione[20];
        printf("Scegli l'operazione (somma, sottrazione, moltiplicazione, divisione): ");
        scanf("%s", operazione);
        if (strcmp(operazione, "somma") == 0) {
            int res = somma(a, b);
            printf("Risultato: %d\n", res);
            salva_in_memoria(res);
        } else {
            if (strcmp(operazione, "sottrazione") == 0) {
                int res = sottrazione(a, b);
                printf("Risultato: %d\n", res);
                salva_in_memoria(res);
            } else {
                if (strcmp(operazione, "moltiplicazione") == 0) {
                    int res = moltiplicazione(a, b);
                    printf("Risultato: %d\n", res);
                    salva_in_memoria(res);
                } else {
                    if (strcmp(operazione, "divisione") == 0) {
                        int res = divisione(a, b);
                        printf("Risultato: %d\n", res);
                        salva_in_memoria(res);
                    } else {
                        printf("Operazione non riconosciuta.\n");
                    }
                }
            }
        }
    } else {
        if (num_elementi == 3) {
            int a, b, c;
            printf("Inserisci i tre numeri: ");
            scanf("%d %d %d", &a, &b, &c);
            char operazione[20];
            printf("Scegli l'operazione (somma o moltiplicazione): ");
            scanf("%s", operazione);
            if (strcmp(operazione, "somma") == 0) {
                int res = somma(somma(a, b), c);
                printf("Risultato: %d\n", res);
                salva_in_memoria(res);
            } else {
                if (strcmp(operazione, "moltiplicazione") == 0) {
                    int res = moltiplicazione(moltiplicazione(a, b), c);
                    printf("Risultato: %d\n", res);
                    salva_in_memoria(res);
                } else {
                    printf("Operazione non riconosciuta.\n");
                }
            }
        } else {
            printf("Numero di elementi non valido. Scegli tra 2 o 3.\n");
        }
    }
}

/*
  ================= Funzione Main =================

  Il menu principale offre le varie funzionalità:
    1. Operazioni Logiche (simulazione di un modulo ALU 74181 singolo).
    2. Operazioni Algebriche.
    3. Convertitore Binario -> Decimale.
    4. Convertitore Decimale -> Binario.
    5. ALU in Modalità PIPO: simulazione di una ALU a 32 bit composta da 8 moduli 74181 (4 bit ciascuno).
    6. Visualizza Memoria: visualizza i risultati salvati nella memoria.
    0. Esci: termina il programma.
  
  Ogni scelta viene gestita tramite if annidati (non usando operatori composti) come richiesto.
*/
int main() {
    int scelta;
    while (1) {
        printf("\n--- Menu Principale ---\n");
        printf("1. Operazioni Logiche (ALU 74181 - Singolo modulo)\n");
        printf("2. Operazioni Algebriche\n");
        printf("3. Convertitore Binario -> Decimale\n");
        printf("4. Convertitore Decimale -> Binario\n");
        printf("5. ALU in Modalità PIPO (32 bit, 8 moduli 74181)\n");
        printf("6. Visualizza Memoria\n");
        printf("0. Esci\n");
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);
        
        if (scelta == 0) {
            break;
        } else {
            if (scelta == 1) {
                simula_alu_74181();
            } else {
                if (scelta == 2) {
                    operazioni_algebriche();
                } else {
                    if (scelta == 3) {
                        int bin;
                        printf("Inserisci un numero binario: ");
                        scanf("%d", &bin);
                        int dec = binario_a_decimale(bin);
                        printf("Risultato (decimale): %d\n", dec);
                        salva_in_memoria(dec);
                    } else {
                        if (scelta == 4) {
                            int dec;
                            printf("Inserisci un numero decimale: ");
                            scanf("%d", &dec);
                            int bin = decimale_a_binario(dec);
                            printf("Risultato (binario): %d\n", bin);
                            salva_in_memoria(bin);
                        } else {
                            if (scelta == 5) {
                                alu_pipo_8();
                            } else {
                                if (scelta == 6) {
                                    stampa_memoria();
                                } else {
                                    printf("Scelta non valida.\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
