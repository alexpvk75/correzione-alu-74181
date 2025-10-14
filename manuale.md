# **Manuale Utente - Simulatore ALU 74181**

### Descrizione breve
Questo programma simula il funzionamento di un'unità aritmetica e logica (ALU) come il chip 74181, che è il "cervello" dei computer per fare calcoli.

### Come Usare il Programma

1. Clona il Repository
git clone https://github.com/il-tuo-nome/il-nome-del-progetto.git 
cd il-nome-del-progetto

2. Compila il codice
Usando GCC:

gcc main.c -o simulatore

3. Avvia il programma
./simulatore

4. Utilizzo Interattivo
All'avvio ti verrà presentato un menù principale con diverse opzioni:
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
