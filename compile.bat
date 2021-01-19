@echo off
::=======================================
:: Set compilation variables
set cPath=
set cc=gcc
set source=main.c
set libs=
set output=main.exe
set cFlags=-std=c99 -Wall
::=======================================
:: Remove previous compilation
cmd /c IF EXIST %output% del /F %output%
::=======================================
::Compile
%cPath%%cc% %source% -o %output% %cFlags% %libs%
::=======================================
::launch the executable
%output%
::=======================================
::stop at the end 
pause
