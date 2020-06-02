win32 {
    DEFINES+=SAK_IMPORT_HID_MODULE
    HID_SYSTEM_PLATFORM=windows
    HID_VERSION=0.9.0

    # i386或x86_64
    contains(QT_ARCH, i386) {
        HID_CPU_ARCHITECTURE=x86
    }else{
        HID_CPU_ARCHITECTURE=amd64
    }

    INCLUDEPATH += $${PWD}/$${HID_VERSION}/$${HID_SYSTEM_PLATFORM}/$${HID_CPU_ARCHITECTURE}/include
    LIBS += -L$${PWD}/$${HID_VERSION}/$${HID_SYSTEM_PLATFORM}/$${HID_CPU_ARCHITECTURE}/lib -lhidapi
    LIBS += -lsetupapi

    QMAKE_LFLAGS_DEBUG += /DEBUG /NODEFAULTLIB:libc.lib /NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:msvcrt.lib /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:libcmtd.lib
}