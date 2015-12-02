set n=20
REM for /L %%i in (1,1,%n%) do mkdir test%%i
for /L %%i in (1,1,9) do python treasure.py <treasure0%%i.inp >treasure0%%i.out
for /L %%i in (10,1,%n%) do python treasure.py <treasure%%i.inp >treasure%%i.out