@echo off
setlocal

call tools\clone_repo.cmd "https://github.com/bxparks/EpoxyDuino.git"
if errorlevel 1 exit /b %errorlevel%

call tools\clone_repo.cmd "https://github.com/bxparks/AUnit.git"
if errorlevel 1 exit /b %errorlevel%

echo All repositories cloned successfully!
endlocal