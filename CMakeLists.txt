# CMakeList.txt: CMakeProject2 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("GeometryTest")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


# 添加boost支持
if (WIN32)
    include_directories("C:/Program Files/CppLibrary/boost/include/boost-1_75")
    link_directories("C:/Program Files/CppLibrary/boost/lib")
    if(${CMAKE_BUILD_TYPE} STREQUAL Release)
        set(BOOST_SERIALIZATION_LIB "libboost_serialization-vc142-mt-x64-1_75")
    else()
        set(BOOST_SERIALIZATION_LIB "libboost_serialization-vc142-mt-gd-x64-1_75")
    endif()
else()
    find_package(Boost REQUIRED)
    if(Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
        set(BOOST_SERIALIZATION_LIB "/usr/lib/arm-linux-gnueabihf/libboost_serialization.so")
    endif()
endif()
link_libraries(${BOOST_SERIALIZATION_LIB})

# geometry
file(GLOB geometry_src geometry/*.cpp geometry/*.h geometry/*.hpp)
message(geometry_src: ${geometry_src})

# 将源代码添加到此项目的可执行文件。
add_executable (GeometryTest 
${geometry_src}
"main.cpp" 
"wykobi/wykobi.hpp" 
"rmath.h")

# TODO: 如有需要，请添加测试并安装目标。
