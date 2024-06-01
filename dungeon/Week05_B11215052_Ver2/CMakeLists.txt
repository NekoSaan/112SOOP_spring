project(Week05_Framework)

set(Week05_SRC_LIST 
    ${PROJECT_SOURCE_DIR}/Week05/main.cpp
	
	${PROJECT_SOURCE_DIR}/Week05/main.h
	${PROJECT_SOURCE_DIR}/Week05/Hero.h
	${PROJECT_SOURCE_DIR}/Week05/Position.h
	${PROJECT_SOURCE_DIR}/Week05/Trigger.h
)

add_executable(Week05 ${Week05_SRC_LIST})