# In this CMakeLists.txt we define which files
# are used to compile the application
set(kcpuinfo_SRCS
   kcpuinfo.cpp
   cpuinformationaquirer.cpp
   mainboardinformationaquirer.cpp
   main.cpp
 )

ki18n_wrap_ui(kcpuinfo_SRCS kcpuinfo.ui)

add_executable( kcpuinfo ${kcpuinfo_SRCS} )

target_link_libraries( kcpuinfo
    Qt5::Widgets
    KF5::CoreAddons
    KF5::I18n
)

install( TARGETS kcpuinfo ${INSTALL_TARGETS_DEFAULT_ARGS} )
install( PROGRAMS kcpuinfo.desktop  DESTINATION ${XDG_APPS_INSTALL_DIR} )
