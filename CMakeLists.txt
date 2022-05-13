# CMakeList.txt: CMakeProject2 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("GeometryTest")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 添加opencv支持
if (WIN32)
    set(OpenCV_DIR "C:/Program Files/CppLibrary/opencv/build")
    if((MSVC_VERSION EQUAL 1910) OR (MSVC_VERSION GREATER 1910))
        set(OpenCV_RUNTIME vc15)
    else()
        set(OpenCV_RUNTIME vc14)
    endif()
endif()
find_package(OpenCV REQUIRED)
link_directories(${OpenCV_LIBRARY_DIRS})

# 添加boost支持
include_directories("C:/Program Files/CppLibrary/boost/include/boost-1_75")

# 添加Qt支持
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR}Charts)   #直方图控件需要用到
find_package(Qt${QT_VERSION_MAJOR}Sql)      #日志类需要用到

# geometry
file(GLOB geometry_src geometry/*.cpp geometry/*.h geometry/*.hpp)
message(geometry_src: ${geometry_src})

# 将源代码添加到此项目的可执行文件。
add_executable (GeometryTest 
${geometry_src}
"main.cpp" 
"adapted/adapted_qt.hpp" 
"adapted/adapted_cv.hpp" 
"wykobi/wykobi.hpp" 
"rmath.h")

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Charts  Qt${QT_VERSION_MAJOR}::Sql)
