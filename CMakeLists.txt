cmake_minimum_required(VERSION 3.20)
project(RS_Monitor)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)


add_executable(${PROJECT_NAME} src/gui/main.cpp src/interface/ResourceObject.h src/interface/CPUInfo.cpp src/interface/CPUInfo.h src/interface/CPUObject.cpp src/interface/CPUObject.h src/interface/RamObject.cpp src/interface/RamObject.h src/arch/Linux/LinuxCPU.cpp src/arch/Linux/LinuxCPU.h src/arch/Linux/LinuxRam.cpp src/arch/Linux/LinuxRam.h src/interface/DiskObject.cpp src/interface/DiskObject.h src/interface/DiskInfo.cpp src/interface/DiskInfo.h src/arch/Linux/LinuxDisk.cpp src/arch/Linux/LinuxDisk.h src/gui/mainwindow.cpp src/gui/mainwindow.h src/gui/mainwindow.ui src/gui/main.cpp src/gui/cpudisplay.cpp src/gui/cpudisplay.h src/gui/cpudisplay.ui src/gui/cpucomponent.cpp src/gui/cpucomponent.h src/gui/cpucomponent.ui src/gui/ramdisplay.cpp src/gui/ramdisplay.h src/gui/ramdisplay.ui src/gui/diskdisplay.cpp src/gui/diskdisplay.h src/gui/diskdisplay.ui src/gui/diskcomponent.cpp src/gui/diskcomponent.h src/gui/diskcomponent.ui)
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})