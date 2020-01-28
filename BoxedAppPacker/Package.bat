@echo off

set CurDir=%~dp0
set CurDir=%CurDir:~,-1%
set ReleaseDir=%CurDir%\..\binary\release\

REM Use UPX to compress dlls.
call upx.exe 7z.dll %ReleaseDir%\*.dll

REM Use BoxedAppPackerConsole to Package Project files.
call BoxedAppPackerConsole.exe GDConfigure.bxproj

pause
