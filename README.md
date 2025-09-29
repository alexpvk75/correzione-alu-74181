# Simulatore ALU 74181 & Unità Aritmetico-Logica

[![C](https://img.shields.io/badge/language-C-blue.svg?logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![GitHub](https://img.shields.io/badge/version-GitHub-black.svg?logo=github)](https://github.com/Leo-Galli/74181)
[![Visual Studio Code](https://img.shields.io/badge/editor-VSCode-0078d7.svg?logo=visualstudiocode&logoColor=white)](https://code.visualstudio.com/)
[![Debian](https://img.shields.io/badge/OS-Debian-A81D33?logo=debian&logoColor=white)](https://www.debian.org/)
[![Arch Linux](https://img.shields.io/badge/OS-Arch%20Linux-1793D1?logo=archlinux&logoColor=white)](https://archlinux.org/)
[![Ubuntu](https://img.shields.io/badge/OS-Ubuntu-E95420?logo=ubuntu&logoColor=white)](https://ubuntu.com/)
[![Windows](https://img.shields.io/badge/OS-Windows-0078D6?logo=windows&logoColor=white)](https://www.microsoft.com/windows)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
[![Lingua](https://img.shields.io/badge/Lingua-Italiano-red.svg)](https://it.wikipedia.org/wiki/Lingua_italiana)

---

## 📖 Descrizione
Progetto per la simulazione software di un'unità aritmetico-logica (ALU) ispirata al chip TTL **74181**, uno dei primi circuiti integrati utilizzati nei processori degli anni '70 per eseguire operazioni su dati a 4 bit.  
Il programma permette di simulare il comportamento dell'ALU tramite un **menù interattivo** e supporta anche operazioni su 32 bit usando più ALU collegate in cascata.

L’applicazione è sviluppata in linguaggio **C** ed è stata progettata per essere **didattica**, intuitiva e adatta sia per lo studio del funzionamento delle ALU che per l'uso pratico in laboratori informatici o corsi di architettura dei calcolatori.

---

## ✨ Funzionalità Principali

| Funzione | Descrizione |
|---------|-------------|
| ⚙️ **Simulazione ALU 74181** | Esegue le operazioni logiche e aritmetiche tipiche dell’ALU 74181. |
| 📂 **Input/Output via File** | Legge i valori dagli operandi e dai comandi da file testuali. |
| 🔄 **Conversione Binario-Decimale** | Converte numeri tra formato binario e decimale. |
| ➕➖ **Operazioni Matematiche Avanzate** | Somma, sottrazione, moltiplicazione e divisione. |
| 🖥️ **ALU 32 Bit (PIPO)** | Simula un'ALU a 32 bit collegando 8 ALU da 4 bit. |
| 💾 **Gestione della Memoria** | Salva automaticamente i risultati delle operazioni. |
| ⏱️ **Misurazione del Clock** | Stima la durata di un ciclo di clock simulato. |

---

## 📊 Activity & Statistiche
![Alt](https://repobeats.axiom.co/api/embed/a576eab04e8ea577550bfb4dd32de862737655ab.svg "Repobeats analytics image")

**Statistiche Repository:**  
![GitHub stars](https://img.shields.io/github/stars/Leo-Galli/74181?style=social)  
![GitHub forks](https://img.shields.io/github/forks/Leo-Galli/74181?style=social)  
![GitHub issues](https://img.shields.io/github/issues/Leo-Galli/74181)  
![GitHub pull requests](https://img.shields.io/github/issues-pr/Leo-Galli/74181)  
![GitHub last commit](https://img.shields.io/github/last-commit/Leo-Galli/74181)  

---

## 🛠️ Requisiti

- Compilatore **C** (ad esempio: `gcc`)
- Sistema operativo: **Windows, Linux o macOS**
- Terminale/console per l'esecuzione

---

## 🚀 Come Usare il Programma

### 1️⃣ Clona il Repository
```bash
git clone https://github.com/Leo-Galli/74181.git 
cd 74181
```

### 2️⃣ Compila il codice
Usando GCC:
```bash
gcc 74181.c -o simulatore_74181
```

### 3️⃣ Avvia il programma
```bash
./simulatore_74181
```

### 4️⃣ Utilizzo Interattivo
All'avvio ti verrà presentato un menù principale con diverse opzioni:

- Inserisci manualmente i dati oppure compila i file di input (`input_alu.txt`, `input_bin.txt`, ecc.)
- Seleziona un'opzione digitando il numero corrispondente.
- I risultati saranno mostrati nella console e salvati nei file di output (`risultati_*.txt`).

---

## 📂 File di Input/Output

**Input:**
- `input_alu.txt` – Per la simulazione ALU 74181
- `input_alu32.txt` – Per la simulazione ALU 32 bit
- `input_bin.txt` – Per la conversione binario → decimale
- `input_dec.txt` – Per la conversione decimale → binario

**Output:**
- `risultati_alu_74181.txt`
- `risultati_alu32.txt`
- `risultati_bin.txt`
- `risultati_dec.txt`

> Se i file non esistono, vengono creati automaticamente con template vuoti.

---

## 💾 Gestione della memoria
Tutti i risultati calcolati durante le operazioni vengono memorizzati internamente.  
Puoi visualizzare il contenuto della memoria tramite l'apposita opzione del menù.

---

## ⏱️ Misurazione del Clock
Una funzione dedicata simula e misura la durata di un ciclo di clock, utile per comprendere il concetto di **sincronizzazione hardware**.

---

## ⚠️ Note Finali
- Tutti i valori di input devono rispettare il formato previsto (es. solo 0 o 1 per i bit).
- Il programma effettua controlli rigorosi sui dati immessi e mostra messaggi chiari in caso di errore.
- È possibile uscire in qualsiasi momento selezionando l’opzione prevista nel menù.

---

## 📜 Licenza
Questo progetto è distribuito sotto licenza **MIT**.  
Leggi il file [LICENSE](https://github.com/Leo-Galli/74181/blob/main/LICENSE) per maggiori dettagli.

---

## 👥 Contributors
Grazie a chi contribuisce a migliorare il progetto ❤️  

<a href="https://github.com/Leo-Galli/74181/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=Leo-Galli/74181" />
</a>

---

## 📎 Allegati
📄 [Report Tecnico](https://docs.google.com/document/d/1t80KM4RDQKBMuIQoPLAFnJRQeKX5ISx1Id5GahRIR-E/edit?usp=sharing)  
📐 [Schema Logico](https://circuitverse.org/users/311719/projects/alu-74181-final)  
🐛 [Lista dei bugs](https://github.com/Leo-Galli/74181/blob/main/bugs.txt)  
🖥️ [Simulazione ALU](https://wokwi.com/projects/439836726113417217)  
📘 Istruzioni per l'utilizzo e funzionalità

---
_Gli allegati sono disponibili sotto forma di link data la loro dimensione considerevole._
