# **Manuale Utente - Simulatore ALU 74181**

### Descrizione breve
Questo programma è un Simulatore di Unità Aritmetica e Logica (ALU) 74181. L'ALU è il "cervello" fondamentale di un computer, responsabile di tutte le operazioni matematiche (Aritmetica) e logiche (come AND, OR). Lo strumento è pensato principalmente per scopi didattici e per testare le funzioni logiche del chip 74181.

### Istruzioni di Avvio

1. Nella pagina del tale progetto premi il tasto "Code" per creare e attivare un nuovo ambiente di sviluppo virtuale (codespace).

2. Una volta che il terminale del codespace è pronto, scrivi il seguente comando per compilare il codice sorgente C e creare il programma eseguibile:
```
gcc main.c -o simulatore
```
3. Avvia l'eseguibile appena creato utilizzando il seguente comando:
```
./simulatore
```
4. All'avvio, ti verrà presentato il Menu Principale. Per selezionare un'opzione, digita il numero corrispondente e premi Invio.
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

### Istruzioni Dettagliate per Opzione

| M | S3 | S2 | S1 | S0 | Cn | Operazione | 
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
