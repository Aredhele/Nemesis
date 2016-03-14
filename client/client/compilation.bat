@echo off
ECHO.
REM std=gnu++0x std=c++11
REM CLIENT Compilation
REM Add to link editor -mwindows -O2 for release mode

SET FLAGS=-std=gnu++0x

SET EXENAME=Client.exe
SET DIRBIN=..\bin
SET DIRINC=..\include
SET DIRLIB=..\lib
SET DIRSFML=..\lib\SFML
SET DIRGTEST=..\lib\GTEST
SET DIRSRC=..\src

SET TESTMAIN=TestMain.exe

REM SFML LIB

SET GRAPH=-lsfml-graphics
SET WINDO=-lsfml-window
SET SYSTE=-lsfml-system
SET AUDIO=-lsfml-audio
SET MAIN=-lsfml-main
SET NET=-lsfml-network

SET SFLIB=-B%DIRSFML% %GRAPH% %WINDO% %SYSTE% %AUDIO% %MAIN% %NET%

REM --- BEG CLIENT ---
CD src
g++ %FLAGS% -g -Wall *.cpp -c -I%DIRINC%
g++ *.o -o %EXENAME% %SFLIB%

DEL .*
MOVE %EXENAME% %DIRBIN%

CD ../bin
%EXENAME%
cd ..

REM --- END CLIENT ---


REM --- BEG TEST ---
CD src

g++ %FLAGS% Nemesis.cpp -c -I%DIRINC%
g++ *.o -o %TESTMAIN% -B%DIRGTEST% -lgtest %SFLIB%

DEL *.o
MOVE %TESTMAIN% %DIRBIN%

CD ..

REM --- END TEST ---

REM --- CLEANING ---
cd bin
REM DEL *.exe
cd ..