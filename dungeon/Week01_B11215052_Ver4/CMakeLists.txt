project(Week01_Framework)

set(Week01_FunctionBasics_SRC_LIST 
    ${PROJECT_SOURCE_DIR}/Week01_FunctionBasics/main.cpp
)

set(Week01_IO_SRC_LIST 
    ${PROJECT_SOURCE_DIR}/Week01_IO/main.cpp
)

add_executable(Week01_FunctionBasics ${Week01_FunctionBasics_SRC_LIST})
add_executable(Week01_IO ${Week01_IO_SRC_LIST})