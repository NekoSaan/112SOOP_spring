project(Week09_Framework)

set(Week09_SRC_LIST 
    ${PROJECT_SOURCE_DIR}/Week09/main.cpp
	
	${PROJECT_SOURCE_DIR}/Week09/main.h
	${PROJECT_SOURCE_DIR}/Week09/Hero.h
	${PROJECT_SOURCE_DIR}/Week09/Position.h
	${PROJECT_SOURCE_DIR}/Week09/Trigger.h
)

add_executable(Week09 ${Week09_SRC_LIST})