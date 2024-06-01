project(Week08_Framework)

set(Week08_SRC_LIST 
    ${PROJECT_SOURCE_DIR}/Week08/main.cpp
	
	${PROJECT_SOURCE_DIR}/Week08/main.h
	${PROJECT_SOURCE_DIR}/Week08/Hero.h
	${PROJECT_SOURCE_DIR}/Week08/Position.h
	${PROJECT_SOURCE_DIR}/Week08/Trigger.h
)

add_executable(Week08 ${Week08_SRC_LIST})