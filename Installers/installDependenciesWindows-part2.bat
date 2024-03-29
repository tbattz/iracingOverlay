:: Only run after installDependenciesWindows.bat has completed successfully
:: Must run in a new command prompt, to get the updated PATHS
echo off
CALL:echored "IMPORTANT: REMOVE CYGWIN FROM PATH BEFORE INSTALLING."
:: Change to download directory
cd ..
SET ORIGINAL=%CD%
cd %UserProfile%\Downloads\


:: Download GLFW
call:echoblue " =================================== GLFW ====================================="
if exist "%UserProfile%\Downloads\glfw\" (
	echo GLFW already cloned.
) else (
	echo Downloading GLFW.
	git clone https://github.com/glfw/glfw.git
)
:: Copy Required includes and Libraries
cd glfw
mkdir build
cd build
cmake -DBUILD_SHARED_LIBS=OFF -G "MinGW Makefiles" ..
make -j4
cd ..
if not exist %ORIGINAL%\include\ mkdir %ORIGINAL%\include\
xcopy include\GLFW\* %ORIGINAL%\include\GLFW\ /s/h/e/k/f/c/y
if not exist %ORIGINAL%\Lib\ mkdir %ORIGINAL%\Lib\
xcopy build\src\libglfw3.a %ORIGINAL%\Lib\ /s/h/e/k/f/c/y
cd ..


:: Download GLM
call:echoblue " =================================== GLM ======================================"
if exist "%UserProfile%\Downloads\GLM\" (
	echo GLM already cloned.
) else (
	echo Downloading GLM.
	git clone https://github.com/g-truc/glm.git
	cd glm && git checkout 0.9.7 && cd ..
)
xcopy /E/I/y glm\glm %ORIGINAL%\include\glm


:: Download FreeType
call:echoblue " =============================== FreeType ================================"
if exist "%UserProfile%\Downloads\ft271.zip" (
	echo ft271.zip already downloaded.
) else (
	echo Downloading FreeType.
	%UserProfile%\Downloads\wget.exe --no-check-certificate https://sourceforge.net/projects/gnuwin32/files/freetype/2.3.5-1/freetype-2.3.5-1-setup.exe
	start /w %UserProfile%\Downloads\freetype-2.3.5-1-setup.exe
    %UserProfile%\Downloads\wget.exe --no-check-certificate https://sourceforge.net/projects/freetype/files/freetype2/2.7.1/ft271.zip
    call:ECHOGREEN "Please unzip %UserProfile%\Downloads\ft271.zip to %UserProfile%\Downloads\ft271 before pressing enter."
    set /p answer=Press enter to continue
)
cd ft271
cd freetype-2.71
echo %CD%
autogen.sh
make -j4
make -j4
timeout 5
xcopy /E/I/y %UserProfile%\Downloads\ft271\freetype-2.7.1\objs\freetype.a %ORIGINAL%\Lib\
cd ..
cd ..
xcopy /E/I/y "%UserProfile%\Downloads\ft271\freetype-2.7.1\include\ft2build.h" %ORIGINAL%\include\
xcopy /E/I/y "%UserProfile%\Downloads\ft271\freetype-2.7.1\include\*" %ORIGINAL%\include\

:: Return to original directory
cd %ORIGINAL%

:: Functions
:ECHORED
%Windir%\System32\WindowsPowerShell\v1.0\Powershell.exe write-host -backgroundcolor Red %1
goto:eof

:ECHOBLUE
%Windir%\System32\WindowsPowerShell\v1.0\Powershell.exe write-host -backgroundcolor blue %1
goto:eof

:ECHOGREEN
%Windir%\System32\WindowsPowerShell\v1.0\Powershell.exe write-host -backgroundcolor green -foreground black %1
goto:eof