
SET /A a = 45
SET /A b = 53
:lp
SET /A a = %a% + 1
xcopy template.c Ejercicio_%a%.c
IF %a% gtr %b% goto exit
goto lp

:exit