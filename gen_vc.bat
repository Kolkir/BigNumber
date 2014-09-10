ECHO OFF

SET CWD=%CD%

IF NOT EXIST vc_build (mkdir vc_build)

CD vc_build

cmake -G "Visual Studio 12" ..

CD %CWD%