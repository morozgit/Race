# CMakeLists.txt in Test directory

# Копирование тестового файла test.py
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test.py ${CMAKE_CURRENT_BINARY_DIR}/Test/test.py COPYONLY)

# Тест на Python
find_package(Python COMPONENTS Interpreter)
if(Python_Interpreter_FOUND)
    add_test(
        NAME TestPython
        COMMAND ${Python_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Test/test.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
else()
    message(WARNING "Python interpreter not found. TestPython will not be added.")
endif()
