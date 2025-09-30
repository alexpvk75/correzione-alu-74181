#!/bin/bash

INSTALL_DIR="$HOME/74181"

if [ ! -d "$INSTALL_DIR" ]; then
    echo "[ERRORE] Programma non installato."
    exit 1
fi

cd "$INSTALL_DIR" || exit

exe=$(ls *.out *.exe 2>/dev/null | head -n 1)

if [ -z "$exe" ]; then
    echo "[ERRORE] Nessun eseguibile trovato. Esegui install.sh prima."
    exit 1
fi

echo "[INFO] Avvio $exe..."
"./$exe"
