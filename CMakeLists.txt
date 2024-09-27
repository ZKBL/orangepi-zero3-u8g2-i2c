cmake_minimum_required(VERSION 3.5)


set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)  # 或者 arm
set(CMAKE_CROSSCOMPILING TRUE)

set(CMAKE_C_COMPILER aarch64-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)
set(CMAKE_FIND_ROOT_PATH /usr/aarch64-linux-gnu)  # 或者 /usr/arm-linux-gnueabi

# 搜索路径
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(i2c-test C)

file(GLOB_RECURSE ALL_SRCS src/*.c)

include_directories(include)

add_library(I2C STATIC IMPORTED)
set_target_properties(I2C PROPERTIES 
	IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/i2c-tools/lib/libi2c.a
       	INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/i2c-tools/include)

add_subdirectory(u8g2 )
add_executable(main ${ALL_SRCS})

target_link_libraries(main u8g2 I2C)
