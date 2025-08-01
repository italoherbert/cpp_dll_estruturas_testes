@echo off

set root_dir=%cd%
set include_dir=%root_dir%\include

set utils_dll_file=%root_dir%\Utils.dll
set utils_proj_dir=..\Utils
set utils_proj_src=%utils_proj_dir%\src
set utils_proj_dll_file=%utils_proj_dir%\bin\Debug\Utils.dll

set estruturas_dll_file=%root_dir%\Estruturas.dll
set estruturas_proj_dir=..\Estruturas
set estruturas_proj_src=%estruturas_proj_dir%\src
set estruturas_proj_dll_file=%estruturas_proj_dir%\bin\Debug\Estruturas.dll

set testesunit_dll_file=%root_dir%\TestesUnit.dll
set testesunit_proj_dir=..\TestesUnit
set testesunit_proj_src=%testesunit_proj_dir%\src
set testesunit_proj_dll_file=%testesunit_proj_dir%\bin\Debug\TestesUnit.dll

set /a cont=0

if %1==limpar (
    call :limpa
) else if %1==copiar (
    call :copia_utils_lib
    call :copia_estruturas_lib
    call :copia_testesunit_lib
) else if %1==build (
    call :limpa
    call :copia_utils_lib
    call :copia_estruturas_lib
    call :copia_testesunit_lib
) else if %1==push (
    call :push
) else if %1==pushall (
    call :pushall
)

goto :fim

:limpa
    if exist %utils_dll_file% (
        del /s /q %utils_dll_file%
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

:copia_utils_lib
    xcopy %utils_proj_src% %include_dir% /s /q
    del /s /q %include_dir%\*.cpp

    copy %utils_proj_dll_file% %root_dir%

    echo Foi realizada a copia dos arquivos da biblioteca Utils.dll
exit /b 0

:copia_estruturas_lib
    xcopy %estruturas_proj_src% %include_dir% /s /q
    del /s /q %include_dir%\*.cpp

    copy %estruturas_proj_dll_file% %root_dir%

    echo Foi realizada a copia dos arquivos da biblioteca Estruturas.dll
exit /b 0

:copia_testesunit_lib
    xcopy %testesunit_proj_src% %include_dir% /s /q
    del /s /q %include_dir%\*.cpp

    copy %testesunit_proj_dll_file% %root_dir%

    echo Foi realizada a copia dos arquivos da biblioteca TestesUnit.dll
exit /b 0

:push
    git add .

    set /p msg="Commit MSG: "
    git commit -m "%msg%"

    git push -u origin main
exit /b 0

:pushall
    set /p msg="Commit MSG: "

    cd %utils_proj_dir%
    git add .
    git commit -m "%msg%"
    git push -u origin main

    cd %estruturas_proj_dir%
    git add .
    git commit -m "%msg%"
    git push -u origin main

    cd %testesunit_proj_dir%
    git add .
    git commit -m "%msg%"
    git push -u origin main

    cd %root_dir%
    git add .
    git commit -m "%msg%"
    git push -u origin main
exit /b 0

:fim
if ErrorLevel = 0 echo Finalizado com sucesso!
if ErrorLevel = 1 echo Houve um erro.
