@echo off

REM Create libraries directory if it doesn't exist
mkdir libraries 2>nul
if errorlevel 1 (
    echo Error: Failed to create 'libraries' directory
    exit /b 1
)

cd libraries

REM Clone EpoxyDuino
echo Cloning EpoxyDuino...
git clone https://github.com/bxparks/EpoxyDuino.git
if errorlevel 1 (
    echo Error: Failed to clone EpoxyDuino repository
    exit /b 1
)

cd EpoxyDuino
git checkout master
cd ..

REM Clone AUnit
echo Cloning AUnit...
git clone https://github.com/bxparks/AUnit.git
if errorlevel 1 (
    echo Error: Failed to clone AUnit repository
    exit /b 1
)

cd AUnit
git checkout master
cd ..

cd ..

echo Done
