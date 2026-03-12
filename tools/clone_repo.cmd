@echo off
setlocal enabledelayedexpansion

REM Проверка наличия аргумента
if "%~1"=="" (
    echo Usage: %~nx0 ^<git-url^>
    exit /b 1
)

set "url=%~1"
set "repo_name=%~n1"

REM Create libraries directory if it doesn't exist
mkdir libraries 2>nul
if errorlevel 1 (
    echo Note: Failed to create 'libraries' directory
)

echo Cloning !repo_name!...
git clone !url! libraries\!repo_name!
if errorlevel 1 (
    echo Error: Failed to clone !repo_name! repository
    exit /b 1
)

pushd libraries\!repo_name!
git checkout master
popd

echo Successfully cloned !repo_name!
endlocal