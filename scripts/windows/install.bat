@echo off
title Installazione 74181
color 0a
setlocal enabledelayedexpansion

REM === CONFIGURAZIONE ===
set INSTALL_DIR=%USERPROFILE%\74181
set MSYS2_DIR=C:\msys64

echo ==================================================
echo        INSTALLER PER PROGETTO 74181
echo ==================================================
echo.

REM === 1. CONTROLLO GCC ===
echo [INFO] Controllo se GCC è installato...
where gcc >nul 2>nul
if %errorlevel% neq 0 (
    echo [WARN] GCC non trovato. Installo MSYS2...
    if not exist %MSYS2_DIR% (
        echo [INFO] Scarico MSYS2 (ci può volere un po')...
        powershell -Command "Invoke-WebRequest -Uri https://mirror.msys2.org/distrib/x86_64/msys2-x86_64-20240717.exe -OutFile %TEMP%\msys2.exe"
        
        echo [INFO] Installazione in corso...
        start /wait %TEMP%\msys2.exe
    )
    echo [INFO] Aggiorno pacchetti e installo gcc...
    %MSYS2_DIR%\usr\bin\bash -lc "pacman -Sy --noconfirm && pacman -S --noconfirm mingw-w64-x86_64-gcc"
)

echo.
echo [OK] GCC è disponibile.
echo.

REM === 2. CLONE DELLA REPO ===
if exist "%INSTALL_DIR%" (
    echo [INFO] Rimuovo vecchia installazione...
    rmdir /s /q "%INSTALL_DIR%"
)

echo [INFO] Clono la repository 74181...
git clone https://github.com/Leo-Galli/74181 "%INSTALL_DIR%"

REM Simulazione barra avanzamento
set bar=##########
for /L %%i in (1,1,10) do (
    set p=!bar:~0,%%i!
    <nul set /p="Avanzamento [!p!          ] %%i0%%`r"
    ping -n 1 localhost >nul
)
echo.

REM === 3. COMPILAZIONE ===
cd "%INSTALL_DIR%"
echo [INFO] Compilo i sorgenti .c...
for %%f in (*.c) do (
    echo Compilo %%f...
    gcc "%%f" -o "%%~nf.exe"
)

echo.
echo ==================================================
echo [SUCCESSO] Installazione completata!
echo Il programma è pronto in %INSTALL_DIR%
echo ==================================================
echo.

REM === 4. APRO IL WIKI ===
echo [INFO] Apro il wiki nel browser...
start https://github.com/Leo-Galli/74181/wiki

pause
endlocal
