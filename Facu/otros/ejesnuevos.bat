
SET /A a = 40
SET /A b = 45
:lp
SET /A a = %a% + 1
xcopy template.c Ejercicio_%a%.c
IF %a% gtr %b% goto exit
goto lp

:exit