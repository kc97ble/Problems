@echo off

set problem=exactone
set timeLimit=2000
set /A memoryLimit=256*1024*1024

if "%~1"=="" (
    echo judge [filename]
    goto end
)

if not exist %1 (
    echo File not found %1
    goto end
)

if exist check.cpp goto checkCpp
if exist check.dpr goto checkDpr
if exist Check.java goto checkJava

echo Checker not found
goto end

:checkCpp

g++ -O2 -static -lm -s -x c++ -Wl,--stack=268435456 -o check.exe check.cpp

goto endCheck

:checkDpr

fpc -XS -O2 check.dpr > nul

goto endCheck

:checkJava

rmdir /S /Q __tmp 2> nul
mkdir __tmp
javac -classpath ".;testlib4j.jar" -d __tmp Check.java
copy /Y testlib4j.jar __tmp    > nul
pushd __tmp
call jar xf testlib4j.jar
echo Main-Class: ru.ifmo.testlib.CheckerFramework> META-INF/manifest.1
echo Checker-Class: Check>> META-INF/manifest.1
del /S /Q *.java > nul
del testlib4j.jar > nul
call jar cfm check.jar META-INF/manifest.1 *.class ru
copy /Y check.jar .. > nul
popd

rmdir /S /Q __tmp

goto endCheck

:endCheck

g++ -O2 -static -lm -s -x c++ -Wl,--stack=268435456 -o %problem%.exe %1
if errorlevel 1 (
    echo Compile error
    goto end
)

for %%i in (??) do (
    echo Running on test %%i ...
    copy /Y %%i %problem%.in > nul
    bb -T %timeLimit% -M %memoryLimit% -B %problem%.exe
    if exist check.exe check %%i %problem%.out %%i.a
    if exist check.jar java -Xss256M -jar check.jar %%i %problem%.out %%i.a
    if errorlevel 1 pause
    del %problem%.in %problem%.out
    echo.
)

:end

del /S /Q %problem%.exe check.exe check.jar *.o *.ppu > nul
pause