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

### Descrizione delle Funzioni del Simulatore

Il simulatore offre un'insieme di strumenti avanzati per l'analisi e calcoli logici. Le funzioni sono raggruppate in base alla loro utilità.

| Opzione | Nome della Funzione | Descrizione |
|---------|---------------------|--------------------------|
| 1 | Operazioni Logiche (ALU 74181 - Singolo) | Esegue la simulazione di un singolo chip ALU 74181. L'utente deve fornire manualmente i due operandi A e B (a 4 bit) e tutti i segnali di controllo (Cn, M, S0-S3) per definire l'operazione logica o aritmetica da eseguire |
| 2 | Operazioni Logiche (ALU 74181 - Singolo con clock) | Esegue la stessa simulazione a 4 bit dell'opzione 1, ma introduce un ritardo fisso per simulare il tempo di elaborazione del circuito, utile per studi sul timing del sistema |
| 3 | Operazioni Algebriche | Permette di usare il programma come una Calcolatrice Avanzata. Puoi inserire liste di numeri per Somma, Sottrazione, Moltiplicazione o, in modo più semplice, digitare un'intera Espressione Matematica (es. (10 + 5) * 2) per ottenere il risultato |
| 4 | Convertitore Binario → Decimale | Converte un numero scritto in codice binario (composto solo da 0 e 1, come 1101) nel suo equivalente nel sistema numerico standard |
| 5 | Convertitore Decimale → Binario | Converte un numero standard (decimale, es. 25) nel suo equivalente in codice binario (es. 11001) |
| 6 | ALU in Modalità PIPO (32 bit - 8x74181) | Simula una catena di 8 chip 74181 interconnessi per creare un'unità logica e aritmetica più potente, capace di eseguire operazioni su numeri più grandi (32 bit). Richiede input binari a 32 bit e segnali di controllo |
| 7 | ALU in Modalità PIPO (32 bit - 8x74181 con clock) | Esegue la stessa simulazione a 32 bit dell'opzione 6, ma con un ritardo di tempo fisso |
| 8 | Visualizza Memoria | Mostra lo storico dei risultati (output) salvati dal programma dopo ogni operazione di calcolo (algebraica o ALU). Funziona come un registro delle operazioni recenti |
| 9 | Calcolo del Clock | Misura il tempo effettivo di un ciclo di clock del processore (CPU) del computer su cui è in esecuzione il simulatore. Questo è utilizzato per calibrare e rendere più realistiche le simulazioni temporizzate (come opzioni 2 e 7]) |
| 0 | Esci | Termina l'esecuzione del programma e chiude l'interfaccia a riga di comando |

### Istruzioni Dettagliate per Opzione



### Riferimento Funzioni ALU (Opzioni 1, 2, 6, 7)
La seguente tabella mostra come i segnali di controllo M, Cn e S0-S3 selezionano l'operazione eseguita.

| M | S3 | S2 | S1 | S0 | Cn | Operazione | 
|---|----|----|----|----|----|------------|
| 1 | 0  | 0  | 0  | 0  | X  | F = NOT(A)|
| 1 | 0  | 0  | 0  | 1  | X  | F = NOT(A + B) |
| 1 | 0  | 0  | 1  | 0  | X  | F = NOT(A)*B |
| 1 | 0  | 0  | 1  | 1  | X  | F = 0 |
| 1 | 0  | 1  | 0  | 0  | X  | F = NOT(AB) |
| 1 | 0  | 1  | 0  | 1  | X  | F = NOT(B) |
| 1 | 0  | 1  | 1  | 0  | X  | F = A ⊕ B |
| 1 | 0  | 1  | 1  | 1  | X  | F = A*NOT(B) |
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
| 0 | 0  | 1  | 0  | 0  | 0  | F = A PLUS (A*NOT(B)) PLUS 1 |
| 0 | 0  | 1  | 0  | 1  | 0  | F = (A+B) PLUS A*NOT(B) PLUS 1 |
| 0 | 0  | 1  | 1  | 0  | 0  | F = A MINUS B |
| 0 | 0  | 1  | 1  | 1  | 0  | F = A*NOT(B) |
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
| 0 | 0  | 1  | 0  | 0  | 1  | F = A PLUS A*NOT(B) |
| 0 | 0  | 1  | 0  | 1  | 1  | F = (A+B) PLUS A*NOT(B) |
| 0 | 0  | 1  | 1  | 0  | 1  | F = A MINUS B MINUS 1 |
| 0 | 0  | 1  | 1  | 1  | 1  | F = A*NOT(B) MINUS 1 |
| 0 | 1  | 0  | 0  | 0  | 1  | F = A PLUS AB |
| 0 | 1  | 0  | 0  | 1  | 1  | F = A PLUS B |
| 0 | 1  | 0  | 1  | 0  | 1  | F = (A+NOT(B)) PLUS AB|
| 0 | 1  | 0  | 1  | 1  | 1  | F = AB MINUS 1 |
| 0 | 1  | 1  | 0  | 0  | 1  | F = A PLUS A |
| 0 | 1  | 1  | 0  | 1  | 1  | F = (A+B) PLUS A |
| 0 | 1  | 1  | 1  | 0  | 1  | F = (A+NOT(B) PLUS A |
| 0 | 1  | 1  | 1  | 1  | 1  | F = A MINUS 1 |


> Nota: “X” indica valore indifferente
> Nella tabella seguente, AND è indicato come prodotto, OR con il segno +, XOR con ⊕, e più e meno aritmetici utilizzando le parole PLUS e MINUS.
