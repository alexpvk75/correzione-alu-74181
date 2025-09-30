#!/bin/bash

INSTALL_DIR="$HOME/74181"

echo "============================================"
echo "   INSTALLER PER PROGETTO 74181"
echo "============================================"
echo

# --- Controllo pacchetti ---
if ! command -v gcc &> /dev/null; then
    echo "[INFO] GCC non trovato. Installazione..."
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        sudo apt update && sudo apt install -y build-essential
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        if ! command -v brew &> /dev/null; then
            echo "[INFO] Homebrew non trovato. Installazione..."
            /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
        fi
        brew install gcc
    fi
fi

if ! command -v git &> /dev/null; then
    echo "[INFO] Git non trovato. Installazione..."
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        sudo apt install -y git
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        brew install git
    fi
fi

echo
echo "[OK] GCC e Git disponibili"
echo

# --- Clono repo ---
if [ -d "$INSTALL_DIR" ]; then
    echo "[INFO] Rimuovo vecchia installazione..."
    rm -rf "$INSTALL_DIR"
fi

echo "[INFO] Clono la repository 74181..."
git clone https://github.com/Leo-Galli/74181 "$INSTALL_DIR"

# --- Barra avanzamento finta ---
BAR="##########"
for i in {1..10}; do
    printf "Avanzamento [%-10s] %d%%\r" "${BAR:0:i}" $((i*10))
    sleep 0.2
done
echo

# --- Compilazione ---
cd "$INSTALL_DIR" || exit
echo "[INFO] Compilo i sorgenti..."
for f in *.c; do
    echo "Compilo $f..."
    gcc "$f" -o "${f%.c}.out"
done

echo
echo "============================================"
echo "[SUCCESSO] Installazione completata!"
echo "Programma installato in: $INSTALL_DIR"
echo "============================================"
echo

# --- Apro wiki ---
if [[ "$OSTYPE" == "darwin"* ]]; then
    open "https://github.com/Leo-Galli/74181/wiki"
else
    xdg-open "https://github.com/Leo-Galli/74181/wiki"
fi
