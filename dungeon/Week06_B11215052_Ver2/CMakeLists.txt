project(Week06_Framework)

set(Week06_SRC_LIST 
    ${PROJECT_SOURCE_DIR}/Week06/main.cpp
	
	${PROJECT_SOURCE_DIR}/Week06/main.h
	${PROJECT_SOURCE_DIR}/Week06/Hero.h
	${PROJECT_SOURCE_DIR}/Week06/Position.h
	${PROJECT_SOURCE_DIR}/Week06/Trigger.h
)

add_executable(Week06 ${Week06_SRC_LIST})