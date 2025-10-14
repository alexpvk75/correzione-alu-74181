# **Manuale Utente - Simulatore ALU 74181**

### Descrizione breve
Questo programma simula il funzionamento di un'unità aritmetica e logica (ALU) come il chip 74181, che è il "cervello" dei computer per fare calcoli.

### Come Usare il Programma

1. Nella pagine del progetto premi tasto "Code" per creare e attivare un nuovo codespace

2. Dentro terminale del codespace
scrivi:

gcc main.c -o simulatore

3. Avvia il programma con
./simulatore

4. All'avvio ti verrà presentato un menù principale con diverse opzioni:
```
============================
MENU PRINCIPALE
============================
[1] Operazioni Logiche (ALU 74181 - Singolo)
[2] Operazioni Logiche (ALU 74181 - Singolo con clock)
[3] Operazioni Algebriche   
[4] Convertitore Binario → Decimale 
[5] Convertitore Decimale → Binario 
[6] ALU in Modalità PIPO (32 bit - 8x74181)
[7] ALU in Modalità PIPO (32 bit - 8x74181 con clock)
[8] Visualizza Memoria   
[9] Calcolo del Clock  
[0] Esci
```
5. Le scelte
   5.1 Operazioni Logiche (ALU 74181 - Singolo)
   Tale opzione esegue calcoli a 4 bit
   Al seguito di selezione di questa opzione il programma chiederà:
   `Inserire dati manualmente? (S/N): `
   L'utente può scegliere modalità del inserimento dei dati scrivendo `S` per "si" oppure `N` per no (non dipende lowercase o uppercase)
   - Inserendo manualmente -
     Il programma chiederà i valori per i seguneti variabili:
     ```
     Cn - segnale di carry in
     M - modalita (aritmetica/logica)
     A0-A3 - i bit della variabile A a 4 bit
     B0-B3 - i bit della variabile B a 4 bit
     S0-S3 - i segnali di selezione del operazione
     ```
     Sotto c'e elenco delle operazioni e seguenti risultati:
     ```
     | M | S3 | S2 | S1 | S0 | Cn | Operazione | 
     |---|----|----|----|----|----|------------|
     | 1 | 0  | 0  | 0  | 0  | X  | F = NOT(A)|
     | 1 | 0  | 0  | 0  | 1  | X  | F = NOT(A + B) |
     | 1 | 0  | 0  | 1  | 0  | X  | F = NOT(A) x B |
     | 1 | 0  | 0  | 1  | 1  | X  | F = 0 |
     | 1 | 0  | 1  | 0  | 0  | X  | F = NOT(AB) |
     | 1 | 0  | 1  | 0  | 1  | X  | F = NOT(B) |
     | 1 | 0  | 1  | 1  | 0  | X  | F = A ⊕ B |
     | 1 | 0  | 1  | 1  | 1  | X  | F = A x NOT(B) |
     | 1 | 1  | 0  | 0  | 0  | X  | F = NOT(A)+B |
     | 1 | 1  | 0  | 0  | 1  | X  | F = NOT(A ⊕ B) |
     | 1 | 1  | 0  | 1  | 0  | X  | F = B |
     | 1 | 1  | 0  | 1  | 1  | X  | F = AB |
     | 1 | 1  | 1  | 0  | 0  | X  | F = 1 |
     | 1 | 1  | 1  | 0  | 1  | X  | F = A + NOT(B) |
     | 1 | 1  | 1  | 1  | 0  | X  | F = A + B |
     | 1 | 1  | 1  | 1  | 1  | X  | F = A |
     | 0 | 0  | 0  | 0  | 0  | 0  | F = A PLUS 1 |
     | 0 | 0  | 0  | 0  | 1  | 0  | F = (A + B) PLUS 1 |
     | 0 | 0  | 0  | 1  | 0  | 0  | F = (A + NOT(B)) PLUS 1 |
     | 0 | 0  | 0  | 1  | 1  | 0  | F = 0 |
     | 0 | 0  | 1  | 0  | 0  | 0  | F = A PLUS (A x NOT(B)) PLUS 1 |
     | 0 | 0  | 1  | 0  | 1  | 0  | F = (A+B) PLUS A x NOT(B) PLUS 1 |
     | 0 | 0  | 1  | 1  | 0  | 0  | F = A MINUS B |
     | 0 | 0  | 1  | 1  | 1  | 0  | F = A x NOT(B) |
     | 0 | 1  | 0  | 0  | 0  | 0  | F = A PLUS AB PLUS 1 |
     | 0 | 1  | 0  | 0  | 1  | 0  | F = A PLUS B PLUS 1 |
     | 0 | 1  | 0  | 1  | 0  | 0  | F = (A+NOT(B)) PLUS AB PLUS 1 |
     | 0 | 1  | 0  | 1  | 1  | 0  | F = AB |
     | 0 | 1  | 1  | 0  | 0  | 0  | F = A PLUS A PLUS 1 |
     | 0 | 1  | 1  | 0  | 1  | 0  | F = (A+B) PLUS A PLUS 1 |
     | 0 | 1  | 1  | 1  | 0  | 0  | F = (A+NOT(B)) PLUS A PLUS 1 |
     | 0 | 1  | 1  | 1  | 1  | 0  | F = A |
     | 0 | 0  | 0  | 0  | 0  | 1  | F = A |
     | 0 | 0  | 0  | 0  | 1  | 1  | F = A + B |
     | 0 | 0  | 0  | 1  | 0  | 1  | F = A + NOT(B) |
     | 0 | 0  | 0  | 1  | 1  | 1  | F = -1 |
     | 0 | 0  | 1  | 0  | 0  | 1  | F = A PLUS A x NOT(B) |
     | 0 | 0  | 1  | 0  | 1  | 1  | F = (A+B) PLUS A x NOT(B) |
     | 0 | 0  | 1  | 1  | 0  | 1  | F = A MINUS B MINUS 1 |
     | 0 | 0  | 1  | 1  | 1  | 1  | F = A x NOT(B) MINUS 1 |
     | 0 | 1  | 0  | 0  | 0  | 1  | F = A PLUS AB |
     | 0 | 1  | 0  | 0  | 1  | 1  | F = A PLUS B |
     | 0 | 1  | 0  | 1  | 0  | 1  | F = (A+NOT(B)) PLUS AB|
     | 0 | 1  | 0  | 1  | 1  | 1  | F = AB MINUS 1 |
     | 0 | 1  | 1  | 0  | 0  | 1  | F = A PLUS A |
     | 0 | 1  | 1  | 0  | 1  | 1  | F = (A+B) PLUS A |
     | 0 | 1  | 1  | 1  | 0  | 1  | F = (A+NOT(B) PLUS A |
     | 0 | 1  | 1  | 1  | 1  | 1  | F = A MINUS 1 |
     ```
     > Nota: “X” indica valore indifferente
     > Nella tabella seguente, AND è indicato con il segno x, OR con il segno +, XOR con ⊕, e più e meno aritmetici utilizzando le parole PLUS e MINUS.
