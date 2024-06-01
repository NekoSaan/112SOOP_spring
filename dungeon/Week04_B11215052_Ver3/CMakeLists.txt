project(Week04_Framework)

set(Week04_SRC_LIST 
    ${PROJECT_SOURCE_DIR}/Week04/main.cpp
    ${PROJECT_SOURCE_DIR}/Week04/main.h
    ${PROJECT_SOURCE_DIR}/Week04/hero.cpp
    ${PROJECT_SOURCE_DIR}/Week04/hero.h
)

add_executable(Week04 ${Week04_SRC_LIST})