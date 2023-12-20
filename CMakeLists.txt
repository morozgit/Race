cmake_minimum_required(VERSION 3.5)

project(Race LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Исходные файлы проекта
set(SRCS Car.cpp Let.cpp main.cpp)
set(HDRS Car.h Let.h)

# Копирование директорий Images и font
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Images" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/font" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

# Найти библиотеку SFML
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Создание исполняемого файла Race
add_executable(Race ${SRCS} ${HDRS})
target_link_libraries(Race sfml-graphics sfml-audio)

# Найти библиотеку pybind11
find_package(pybind11 REQUIRED)

## Создание модуля Python RaceModule
#add_library(RaceModule MODULE Let.cpp)
#target_link_libraries(RaceModule PRIVATE pybind11::module)
#set_target_properties(RaceModule PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}" SUFFIX "${PYTHON_MODULE_EXTENSION}")

## Копирование файла test.py в директорию сборки
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Test/test.py ${CMAKE_CURRENT_BINARY_DIR}/test.py COPYONLY)

# Тест на Python
find_package(Python COMPONENTS Interpreter)
if(Python_Interpreter_FOUND)
    add_test(
        NAME TestPython
        COMMAND ${Python_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/test.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
else()
    message(WARNING "Python interpreter not found. TestPython will not be added.")
endif()
