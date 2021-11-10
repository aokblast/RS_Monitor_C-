cmake_minimum_required(VERSION 3.20)
project(RS_Monitor)

set(CMAKE_CXX_STANDARD 14)


set(wxWidgets_ROOT_DIR </usr/include/wx-3.0-unofficial>)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})
set(SOURCE_FILES main.cpp)

add_executable(RS_Monitor main.cpp src/interface/ResourceObject.h src/interface/CPUInfo.cpp src/interface/CPUInfo.h src/interface/CPUObject.cpp src/interface/CPUObject.h src/interface/RamObject.cpp src/interface/RamObject.h src/arch/Linux/LinuxCPU.cpp src/arch/Linux/LinuxCPU.h src/arch/Linux/LinuxRam.cpp src/arch/Linux/LinuxRam.h src/gui/MainWindow.cpp src/gui/MainWindow.h src/interface/DiskObject.cpp src/interface/DiskObject.h src/interface/DiskInfo.cpp src/interface/DiskInfo.h src/arch/Linux/LinuxDisk.cpp src/arch/Linux/LinuxDisk.h)

target_link_libraries(RS_Monitor ${wxWidgets_LIBRARIES})