@echo off
title Avvio 74181
color 0e

set INSTALL_DIR=%USERPROFILE%\74181

if not exist "%INSTALL_DIR%" (
    echo [ERRORE] Programma non installato.
    pause
    exit /b
)

cd "%INSTALL_DIR%"
for %%f in (*.exe) do (
    echo [INFO] Avvio %%f...
    start %%f
    exit /b
)

echo [ERRORE] Nessun eseguibile trovato. Esegui install.bat prima.
pause
