@echo ****************************************************************
@echo *             This debugsim build scrpt.                       *
@echo ****************************************************************
@echo.
@echo.
                                                         
@echo off



set INCLUDE=../include;%INCLUDE%
set CCFLAG=/c /O2
set CC=cl
set LD=link
set LDFLAG=/DEFAULTLIB:MSVCRT.LIB /NODEFAULTLIB:LIBCMT.LIB



set base_dir=..
cd  output

@echo on

%CC% %CCFLAG% %base_dir%\register\opreg.c

%CC% %CCFLAG% %base_dir%\mem\opmem.c

%CC% %CCFLAG% %base_dir%\debugsim\debugsim.c

%CC% %CCFLAG% %base_dir%\cmdtrans\cmdtrans.c

%CC% %CCFLAG% %base_dir%\disassmeber\disassmeber.c

%CC% %CCFLAG% %base_dir%\assember\assember.c

%LD% %LDFLAG% debugsim.obj opreg.obj opmem.obj cmdtrans.obj disassmeber.obj assember.obj /out:debugsim.exe


@echo off



cd ..

@echo on
@echo.  
@echo.                                                 
@echo ****************************************************************
@echo *                     Building Finished..                      *
@echo ****************************************************************

