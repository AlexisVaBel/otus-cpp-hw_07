cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 14)
#set(CMAKE_BUILD_TYPE Debug)
project(nickname)

if ($ENV{TRAVIS_BUILD_NUMBER})
 project(${PROJECT_NAME} VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ($ENV{TRAVIS_BUILD_NUMBER})
 project(${PROJECT_NAME}  VERSION 0.0.1)
endif ($ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)



set(INC_DIRS  "." "radix/")
set(SRC_LIST main.cpp  radix/strhelper.cpp radix/radixtreeuniq.cpp)


include_directories(${INC_DIRS})


add_executable(${PROJECT_NAME} ${SRC_LIST})

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )


#    target_link_libraries(${PROJECT_NAME}_test
#        ${Boost_LIBRARIES}
#        )


install (TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT alexisvabel@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
include(CPack)
