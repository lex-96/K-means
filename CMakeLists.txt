cmake_minimum_required(VERSION 3.2)

# Defining VERSION for local and Travis build 
if($ENV{TRAVIS_BUILD_NUMBER})
	project(kkmeans VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
	project(kkmeans VERSION 0.0.1)
endif()

add_executable(${PROJECT_NAME} main.cpp)

add_executable(GenerateSky GenerateSky.cpp)

set_target_properties(${PROJECT_NAME} GenerateSky PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(${PROJECT_NAME}
        openblas
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT lex9612@gmail.com)

include(CPack)

