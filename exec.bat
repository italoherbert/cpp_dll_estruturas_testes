@echo off

setlocal

set app_file_name=EstruturasTestes.exe

set root_dir=%~dp0%
set include_dir=%root_dir%include
set app_file=%root_dir%bin\Debug\%app_file_name%

set utils_dll_file=%root_dir%Utils.dll
set testesunit_dll_file=%root_dir%TestesUnit.dll
set estruturas_dll_file=%root_dir%Estruturas.dll

set /a cont=0

if %1==limpar (
    call :limpa
) else if %1==compilar (
    call :compila_e_linka
) else if %1==build (
    call :limpa
    call :compila_e_linka
) else if %1==exec (
    call :limpa
    call :compila_e_linka
    call :exec_app
) else if %1==push (
    call :push
)

goto :fim

:exec_app
    %app_file%
exit /b 0

:limpa
    if exist %utils_dll_file% (
        del /s /q %utils_dll_file%
    )

    if exist %testesunit_dll_file% (
        del /s /q %testesunit_dll_file%
    )

    if exist %estruturas_dll_file% (
        del /s /q %estruturas_dll_file%
    )

    del /s /q %include_dir%\*

    set /a cont=0
    for %%f in (%include_dir%\*) do (
        set /a cont = cont+1
    )

    if %cont% gtr 0 (
        rmdir /s /q %include_dir%\*
    )

    echo Foi efetuada a limpeza de arquivos e diretorios
exit /b 0

:compila_e_linka
    cd %root_dir%
    call %root_dir%compile.bat

    @echo on
    copy %app_file% %root_dir% /y
    @echo off

    echo %app_file_name% foi compilado e linkado com sucesso.
exit /b 0

:push
    git add .

    set /p msg="Commit MSG: "
    git commit -m "%msg%"

    git push -u origin main
exit /b 0


:fim
if ErrorLevel = 1 echo Houve um erro.

endlocal
