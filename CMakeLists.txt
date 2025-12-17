####################################### Enforce CMake Version

cmake_minimum_required(VERSION 3.20)

####################################### Project definition

project(
	Math_Tools 
	VERSION 0.0.1 
	DESCRIPTION "Cross Platform Math Tools" 
	LANGUAGES CXX
)

####################################### Enforcing C++20 standard

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

####################################### Check For No Config Set

if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    message(FATAL_ERROR "No build type specified, ending build. CMAKE WILL NOW EXIT")
endif()

####################################### Enforce 64-bit Requirement

if(NOT ${CMAKE_SIZEOF_VOID_P} EQUAL 8)
    message(FATAL_ERROR "Math_Tools only supports 64-bit platforms.")
endif()

####################################### Build Message

message(STATUS "Build artifacts will be stored in: ${OUTPUT_DIR}")
message(STATUS "Building Math_Tools for ${PLATFORM_NAME} in ${CMAKE_BUILD_TYPE} mode.")

####################################### Detect Current OS

if(WIN32)

    set(PLATFORM_NAME "Windows")

elseif(APPLE)

	set(PLATFORM_NAME "TIM_APPLE")

	set_property( #Clang++/g++ compiler settings
		TARGET ${PROJECT_NAME} 
		APPEND PROPERTY COMPILE_OPTIONS -Wall -Wextra -Wpedantic
	)

	if(CMAKE_BUILD_TYPE STREQUAL "Debug") #treat warnings as errors for debug builds
		set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_OPTIONS -Werror)
	endif()

elseif(UNIX)

	set(PLATFORM_NAME "Some_Linux_Distro_idfk")

	set_property( #Clang++/g++ compiler settings
		TARGET ${PROJECT_NAME} 
		APPEND PROPERTY COMPILE_OPTIONS -Wall -Wextra -Wpedantic
	)

	if(CMAKE_BUILD_TYPE STREQUAL "Debug") #treat warnings as errors for debug builds
		set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY COMPILE_OPTIONS -Werror)
	endif()

else()
    message(FATAL_ERROR "Unsupported platform!")
endif()

####################################### Set Build Output Directories

set(
	OUTPUT_DIR 
	"${CMAKE_SOURCE_DIR}/build/${PLATFORM_NAME}/${CMAKE_BUILD_TYPE}"
)

####################################### Find All Source Files

file(
    GLOB_RECURSE 
    MATH_TOOLS_SOURCE_FILES 
    CONFIGURE_DEPENDS 
    "src/*.cpp"
	"src/*.h"
)

####################################### Executable Target

add_executable(
	${PROJECT_NAME} 
	${MATH_TOOLS_SOURCE_FILES}
)

####################################### Set Startup Project (Visual Studio & Xcode)

# Set Math_Tools as the default scheme in Xcode

if(CMAKE_GENERATOR STREQUAL "Xcode")
    set(CMAKE_XCODE_GENERATE_SCHEME TRUE)
    set(CMAKE_XCODE_SCHEME_EXECUTABLE ${PROJECT_NAME})
    message(STATUS "Setting ${PROJECT_NAME} as the default startup project for Xcode")

# Set Math_Tools as the startup project for Visual Studio

elseif(CMAKE_GENERATOR MATCHES "Visual Studio")
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
    message(STATUS "Setting ${PROJECT_NAME} as the default startup project for VS2022")

endif()