cmake_minimum_required(VERSION 3.1)

project(Race LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)
set(SRCS Car.cpp Let.cpp main.cpp)
set(HDRS Car.h Let.h)
set(SFML_DIR "C:/SFML-2.5.1-cmake")

#копируем директорию Images
FILE(
    COPY "${CMAKE_CURRENT_SOURCE_DIR}/Images"
    DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
)
FILE(
    COPY "${CMAKE_CURRENT_SOURCE_DIR}/font"
    DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
)


find_package(SFML 2.5 REQUIRED graphics audio)

add_executable(Race ${SRCS} ${HDRS})

target_link_libraries(Race sfml-graphics sfml-audio)
