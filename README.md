
# 🔢 Simulatore ALU 74181

[![C](https://img.shields.io/badge/language-C-blue.svg?logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![GitHub stars](https://img.shields.io/github/stars/Leo-Galli/74181?style=social)](https://github.com/Leo-Galli/74181/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/Leo-Galli/74181?style=social)](https://github.com/Leo-Galli/74181/network/members)
[![GitHub issues](https://img.shields.io/github/issues/Leo-Galli/74181)](https://github.com/Leo-Galli/74181/issues)
[![GitHub last commit](https://img.shields.io/github/last-commit/Leo-Galli/74181)](https://github.com/Leo-Galli/74181/commits/main)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

---

## 📖 Descrizione

Simulatore didattico di un'unità aritmetico-logica (ALU) ispirata al chip TTL **74181**, progettato per eseguire operazioni logiche e aritmetiche su dati a 4 bit. Include anche una versione estesa a 32 bit tramite ALU in cascata.  
Il progetto è pensato per studenti, appassionati di architettura dei calcolatori e chiunque voglia comprendere il funzionamento interno di un'ALU reale.

---

## ✨ Funzionalità

- ✅ Simulazione completa del chip 74181
- ➕ Operazioni logiche e aritmetiche (AND, OR, XOR, somma, sottrazione, ecc.)
- 🔁 Conversione binario ↔ decimale
- 🧩 Simulazione ALU 32 bit (PIPO)
- 📂 Input/output da file
- ⏱️ Misurazione ciclo di clock simulato
- 💾 Salvataggio automatico dei risultati
- 🧠 Visualizzazione memoria interna e stato dei registri

---

## 📂 Struttura File

### Input

- `input_alu.txt` — Operazioni ALU 74181
- `input_alu32.txt` — Operazioni ALU 32 bit
- `input_bin.txt` — Binario → Decimale
- `input_dec.txt` — Decimale → Binario

### Output

- `risultati_alu_74181.txt`
- `risultati_alu32.txt`
- `risultati_bin.txt`
- `risultati_dec.txt`

> I file vengono generati automaticamente se non presenti.

---

## 🚀 Installazione

```bash
git clone https://github.com/Leo-Galli/74181.git
cd 74181
gcc 74181.c -o simulatore_74181
./simulatore_74181
```

---

## 🖥️ Requisiti

- Compilatore C (es. `gcc`)
- Sistema operativo: Windows, Linux, macOS
- Terminale per esecuzione interattiva

---

## 📊 Statistiche

![Star History](https://api.star-history.com/svg?repos=Leo-Galli/74181&type=Date)
![RepoBeats](https://repobeats.axiom.co/api/embed/a576eab04e8ea577550bfb4dd32de862737655ab.svg)

---

## 📅 Storico Versioni

| Badge | Descrizione |
|-------|-------------|
| ![Commit Activity](https://img.shields.io/github/commit-activity/y/Leo-Galli/74181) | Commits per anno |
| ![Last Commit](https://img.shields.io/github/last-commit/Leo-Galli/74181) | Ultimo commit |
| ![Open Issues](https://img.shields.io/github/issues/Leo-Galli/74181) | Issue aperte |
| ![Pull Requests](https://img.shields.io/github/issues-pr/Leo-Galli/74181) | Pull request attive |
| ![Repo Size](https://img.shields.io/github/repo-size/Leo-Galli/74181) | Dimensione repository |
| ![Contributors](https://img.shields.io/github/contributors/Leo-Galli/74181) | Numero di contributori |


---

## 📎 Allegati

- 📘 [Report tecnico](https://docs.google.com/document/d/1t80KM4RDQKBMuIQoPLAFnJRQeKX5ISx1Id5GahRIR-E/edit?usp=sharing)
- 📐 [Schema logico CircuitVerse](https://circuitverse.org/users/311719/projects/alu-74181-final)
- 🐛 [Lista bug](https://github.com/Leo-Galli/74181/blob/main/bugs.txt)
- 🖥️ [Simulazione online Wokwi](https://wokwi.com/projects/439836726113417217)

---

## 🔍 Approfondimenti

- Il chip 74181 è stato il primo ALU TTL integrato, usato in sistemi come PDP-11 e VAX.
- La simulazione include flag come Carry, Overflow, Zero, Negative.
- La versione 32 bit usa 8 ALU in cascata con gestione dei segnali di propagazione.
- Il clock simulato è utile per comprendere la latenza e il parallelismo.

---

## 📜 Licenza

Distribuito sotto licenza MIT. Vedi [LICENSE](LICENSE) per dettagli.

---

## 👥 Contributors

<a href="https://github.com/Leo-Galli/74181/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=Leo-Galli/74181" />
</a>
