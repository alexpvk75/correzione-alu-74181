@echo off
title Disinstallazione 74181
color 0c

set INSTALL_DIR=%USERPROFILE%\74181

if exist "%INSTALL_DIR%" (
    echo [INFO] Rimuovo la cartella %INSTALL_DIR%...
    rmdir /s /q "%INSTALL_DIR%"
    echo [OK] Disinstallazione completata.
) else (
    echo [INFO] Nessuna installazione trovata.
)

pause
