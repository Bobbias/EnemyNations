
###############################
# vpdiag.exe
###############################

set(vdmplui_sources
        STDAFX.CPP
        VDMPLUI.CPP
        VDMPLUI.RC
        )

add_library(vdmplui SHARED ${vdmplui_sources})

target_include_directories(vdmplui PUBLIC
        ../
        )
