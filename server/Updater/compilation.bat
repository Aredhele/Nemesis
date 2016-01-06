@echo off
ECHO.
REM std=gnu++0x std=c++11
REM CLIENT Compilation
REM Add to link editor -mwindows -O2 for release mode

SET FLAGS=-std=gnu++0x

SET EXENAME=Updater.exe
SET DIRBIN=..\bin
SET DIRINC=..\include
SET DIRLIB=..\lib
SET DIRSFML=..\lib\SFML
SET DIRGTEST=..\lib\GTEST
SET DIRSRC=..\src

REM SFML LIB

SET GRAPH=-lsfml-graphics
SET WINDO=-lsfml-window
SET SYSTE=-lsfml-system
SET AUDIO=-lsfml-audio
SET MAIN=-lsfml-main
SET NET=-lsfml-network
SET CRY=-lcrypto

SET SFLIB=-B%DIRSFML% %GRAPH% %WINDO% %SYSTE% %AUDIO% %MAIN% %NET% %CRY%

CD src
g++ %FLAGS% *.cpp -c -I%DIRINC%
g++ *.o -o %EXENAME% %SFLIB%

DEL *.o
MOVE %EXENAME% %DIRBIN%

CD ../bin
%EXENAME%
cd ..