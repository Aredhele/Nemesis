@ECHO OFF
SET lineNB=0
SET TMP=0

FOR /F "tokens=*" %%G IN ('dir /B') DO (FIND /v /c "" %%G)