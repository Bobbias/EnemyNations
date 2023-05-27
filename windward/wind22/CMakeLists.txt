
set(wind22_sources
        src/acmutil.cpp
        src/apppalet.cpp
        src/bitbuffe.cpp
        src/blt.cpp
        src/bpecodec.cpp
        src/btree.cpp
        src/codec.cpp
        src/datafile.cpp
        src/davidinl.cpp
        src/dib.cpp
#        src/dircore.cpp
        src/dlgmsg.cpp
        src/fixpoint.cpp
        src/flcctrl.cpp
        src/global.cpp
        src/huffmanc.cpp
        src/init.cpp
        src/logging.cpp
        src/lzsscode.cpp
        src/lzwcodec.cpp
        src/mmio.cpp
        src/msg_box.cpp
        src/music.cpp
        src/rand.cpp
        src/scanlist.cpp
        src/stdafx.cpp
        src/strext.cpp
        src/subclass.cpp
        src/threads.cpp
        src/wndbase.cpp
        dibwnd.cpp
        )

add_library(wind22 STATIC ${wind22_sources})

target_compile_options(wind22 INTERFACE
        "$<$<CONFIG:RELEASE>:$<BUILD_INTERFACE:/MD;/GX;/Zi;/O2;/Ob2;/EHsc>"
        "$<$<CONFIG:DEBUG>:$<BUILD_INTERFACE:/MD;/GX;/EHsc>"
        )

target_compile_definitions(wind22 PUBLIC
        _AFXDLL
        _WIN32_WINNT=_WIN32_WINNT_WIN7
        _WINDOWS
        _MBCS
        WIN32
        _X86_ # Hack! This should not be necessary.
        )

target_link_libraries(wind22 PUBLIC
        winmm.lib
        version.lib
        )

target_include_directories(wind22 PUBLIC
        include
        ../../tools
        )

target_link_directories(wind22 PUBLIC
        ../../tools/lib)
