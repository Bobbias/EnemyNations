
###############################
# vpdiag.exe
###############################

set(vpdiag_sources
        VPDIAG.CPP
        VPDIAGDL.CPP
        STDAFX.CPP
        vpdiag.rc
        ../vpwinsk.cpp
        NET.CPP
        NBDLG.CPP
        TCPDLG.CPP
        ../vputil.cpp
        )

add_executable(vpdiag WIN32 ${vpdiag_sources})

target_include_directories(vpdiag PUBLIC
        ../
        )
