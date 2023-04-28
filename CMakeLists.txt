cmake_minimum_required(VERSION 3.5)

project(Race LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SRCS Car.cpp Let.cpp main.cpp)
set(HDRS Car.h Let.h)

#копируем директорию Images
FILE(
    COPY "${CMAKE_CURRENT_SOURCE_DIR}/Images"
    DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
)
FILE(
    COPY "${CMAKE_CURRENT_SOURCE_DIR}/font"
    DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
)


find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Race ${SRCS} ${HDRS})

target_link_libraries(Race sfml-graphics sfml-audio)
