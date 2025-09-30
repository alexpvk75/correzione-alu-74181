#!/bin/bash

INSTALL_DIR="$HOME/74181"

if [ -d "$INSTALL_DIR" ]; then
    echo "[INFO] Rimuovo la cartella $INSTALL_DIR..."
    rm -rf "$INSTALL_DIR"
    echo "[OK] Disinstallazione completata."
else
    echo "[INFO] Nessuna installazione trovata."
fi
