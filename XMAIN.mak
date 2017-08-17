# Microsoft Developer Studio Generated NMAKE File, Based on XMAIN.dsp
!IF "$(CFG)" == ""
CFG=XMAIN - Win32 Debug
!MESSAGE No configuration specified. Defaulting to XMAIN - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "XMAIN - Win32 Release" && "$(CFG)" != "XMAIN - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "XMAIN.mak" CFG="XMAIN - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "XMAIN - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "XMAIN - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "XMAIN - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\XMAIN.exe"


CLEAN :
	-@erase "$(INTDIR)\HUMAN.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XMAIN.obj"
	-@erase "$(OUTDIR)\XMAIN.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\XMAIN.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\XMAIN.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\XMAIN.pdb" /machine:I386 /out:"$(OUTDIR)\XMAIN.exe" 
LINK32_OBJS= \
	"$(INTDIR)\HUMAN.obj" \
	"$(INTDIR)\XMAIN.obj"

"$(OUTDIR)\XMAIN.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "XMAIN - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\XMAIN.exe" "$(OUTDIR)\XMAIN.bsc"


CLEAN :
	-@erase "$(INTDIR)\HUMAN.obj"
	-@erase "$(INTDIR)\HUMAN.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XMAIN.obj"
	-@erase "$(INTDIR)\XMAIN.sbr"
	-@erase "$(OUTDIR)\XMAIN.bsc"
	-@erase "$(OUTDIR)\XMAIN.exe"
	-@erase "$(OUTDIR)\XMAIN.ilk"
	-@erase "$(OUTDIR)\XMAIN.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\XMAIN.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\XMAIN.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\HUMAN.sbr" \
	"$(INTDIR)\XMAIN.sbr"

"$(OUTDIR)\XMAIN.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\XMAIN.pdb" /debug /machine:I386 /out:"$(OUTDIR)\XMAIN.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\HUMAN.obj" \
	"$(INTDIR)\XMAIN.obj"

"$(OUTDIR)\XMAIN.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("XMAIN.dep")
!INCLUDE "XMAIN.dep"
!ELSE 
!MESSAGE Warning: cannot find "XMAIN.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "XMAIN - Win32 Release" || "$(CFG)" == "XMAIN - Win32 Debug"
SOURCE=.\HUMAN.cpp

!IF  "$(CFG)" == "XMAIN - Win32 Release"


"$(INTDIR)\HUMAN.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "XMAIN - Win32 Debug"


"$(INTDIR)\HUMAN.obj"	"$(INTDIR)\HUMAN.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\XMAIN.cpp

!IF  "$(CFG)" == "XMAIN - Win32 Release"


"$(INTDIR)\XMAIN.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "XMAIN - Win32 Debug"


"$(INTDIR)\XMAIN.obj"	"$(INTDIR)\XMAIN.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

