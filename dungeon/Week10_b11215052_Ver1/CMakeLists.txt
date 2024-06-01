project(Week10_Framework)

set(Week10_SRC_LIST 
    ${PROJECT_SOURCE_DIR}/Week10/main.cpp
	${PROJECT_SOURCE_DIR}/Week10/Hero.cpp
	${PROJECT_SOURCE_DIR}/Week10/Trigger.cpp
	
	${PROJECT_SOURCE_DIR}/Week10/main.h
	${PROJECT_SOURCE_DIR}/Week10/Hero.h
	${PROJECT_SOURCE_DIR}/Week10/Position.h
	${PROJECT_SOURCE_DIR}/Week10/Trigger.h
)

add_executable(Week10 ${Week10_SRC_LIST})