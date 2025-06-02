# Simulatore ALU 74181 & Unità Aritmetico-Logica

## Descrizione
Progetto per la simulazione software di un'unità aritmetico-logica (ALU) ispirata al chip TTL **74181**, uno dei primi circuiti integrati utilizzati nei processori degli anni '70 per eseguire operazioni su dati a 4 bit. Il programma permette di simulare il comportamento dell'ALU tramite un menù interattivo e supporta anche operazioni su 32 bit usando più ALU collegate in cascata.

L’applicazione è sviluppata in linguaggio C ed è stata progettata per essere didattica, intuitiva e adatta sia per lo studio del funzionamento delle ALU che per l'uso pratico in laboratori informatici o corsi di architettura dei calcolatori.

---

## Funzionalità Principali

| Funzione | Descrizione |
|---------|-------------|
| **Simulazione ALU 74181** | Esegue le operazioni logiche e aritmetiche tipiche dell’ALU 74181. |
| **Input/Output via File** | Legge i valori dagli operandi e dai comandi da file testuali. |
| **Conversione Binario-Decimale** | Converte numeri tra formato binario e decimale. |
| **Operazioni Matematiche Avanzate** | Somma, sottrazione, moltiplicazione e divisione. |
| **ALU 32 Bit (PIPO)** | Simula un'ALU a 32 bit collegando 8 ALU da 4 bit. |
| **Gestione della Memoria** | Salva automaticamente i risultati delle operazioni. |
| **Misurazione del Clock** | Stima la durata di un ciclo di clock simulato. |

---

## Requisiti

- Compilatore C (ad esempio: `gcc`)
- Sistema operativo: Windows, Linux o macOS
- Terminale/console per l'esecuzione

---

## Come Usare il Programma

### 1. Clona il Repository
```bash
git clone https://github.com/il-tuo-nome/il-nome-del-progetto.git 
cd il-nome-del-progetto
```
### 2. Compila il codice
Usando GCC:
```bash
gcc 74181.c -o simulatore_74181
```
### 3. Avvia il programma
```bash
./simulatore_74181
```
### 4. Utilizzo Interattivo
All'avvio ti verrà presentato un menù principale con diverse opzioni:

- Inserisci manualmente i dati oppure compila i file di input (input_alu.txt, input_bin.txt, ecc.)
- Seleziona un'opzione digitando il numero corrispondente.
- I risultati saranno mostrati nella console e salvati nei file di output (risultati_*.txt).
---
## File di Input/Output
Il programma si aspetta alcuni file per leggere gli input:

- input_alu.txt – Per la simulazione ALU 74181
- input_alu32.txt – Per la simulazione ALU 32 bit
- input_bin.txt – Per la conversione binario → decimale
- input_dec.txt – Per la conversione decimale → binario

Se i file non esistono, vengono creati automaticamente con template vuoti. Compilali prima di eseguire nuovamente il programma.

I risultati vengono invece salvati in:

- risultati_alu_74181.txt
- risultati_alu32.txt
- risultati_bin.txt
- risultati_dec.txt
---
## Gestione della memoria
Tutti i risultati calcolati durante le operazioni vengono memorizzati internamente. Puoi visualizzare il contenuto della memoria tramite l'apposita opzione del menù.

---
## Misurazione del Clock
Una funzione dedicata simula e misura la durata di un ciclo di clock, utile per comprendere il concetto di sincronizzazione hardware.

---
## Note Finali
- Tutti i valori di input devono rispettare il formato previsto (es. solo 0 o 1 per i bit).
- Il programma effettua controlli rigorosi sui dati immessi e mostra messaggi chiari in caso di errore.
- È possibile uscire in qualsiasi momento selezionando l’opzione prevista nel menù.

---
## Licenza
Il progetto è fornino con annessa una licenza che è disponibile [qui](https://github.com/Leo-Galli/74181/blob/main/LICENSE)

---
## Allegati
Annessi a questa repository vi sono i seguenti allegati:
- [Report Tecnico](https://docs.google.com/document/d/1t80KM4RDQKBMuIQoPLAFnJRQeKX5ISx1Id5GahRIR-E/edit?usp=sharing)
- [Schema Logico](https://circuitverse.org/users/311719/projects/alu-74181-final)
- [Lista dei bugs](https://github.com/Leo-Galli/74181/blob/main/bugs.txt)
- Istruzioni per l'utilizzo e funzionalità