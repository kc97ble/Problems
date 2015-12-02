@echo off

for %%i in (..) do set problem_name=%%~ni

echo %problem_name%

if EXIST ..\%problem_name%_%1.dpr dcc32 -cc ..\%problem_name%_%1.dpr
if EXIST ..\%problem_name%_%1.cpp g++ ..\%problem_name%_%1.cpp -o ..\%problem_name%_%1.exe
if EXIST ..\%problem_name%_%1.java javac ..\%problem_name%_%1.java -encoding utf8 

for %%i in (??) do (
    echo %%i
    copy %%i ..\%problem_name%.in > nul
    pushd ..
    if EXIST %problem_name%_%1.exe call %problem_name%_%1.exe
    if EXIST %problem_name%_%1.class call java -Xmx256M -Xss64M -ea %problem_name%_%1
    if EXIST %problem_name%_%1.py call python %problem_name%_%1.py
    popd
    copy ..\%problem_name%.out %%i.a > nul
)
