cmake_minimum_required(VERSION 3.13)

project(corewar)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_STANDARD 99)

if (${CMAKE_SYSTEM_NAME} STREQUAL Linux)
	set(LIBRARY_PATH /home/linuxbrew/.linuxbrew/lib/)
	set(LIBRARY_INCLUDE_PATH /home/linuxbrew/.linuxbrew/include/)
elseif (${CMAKE_SYSTEM_NAME} STREQUAL Darwin)
	set(LIBRARY_PATH /Users/dderevyn/.brew/lib/)
	set(LIBRARY_INCLUDE_PATH /Users/dderevyn/.brew/include/)
else ()
	message(FATAL_ERROR "Error: Your system is unsupported")
endif()

set(INCLUDE_PATH include/)
set(SOURCE_PATH source/)
set(EXECUTABLE corewar)
set(LIBFT_PATH libft/)
set(LIBFT libft.a)

#add_custom_command(OUTPUT /Users/dderevyn/CLionProjects/corewar_vm/${LIBFT_PATH}${LIBFT}
#		COMMAND make ${LIBFT}
#		WORKING_DIRECTORY /Users/dderevyn/CLionProjects/corewar_vm/${LIBFT_PATH})

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${SOURCE_PATH}*.c)

add_executable(${EXECUTABLE}
		${SOURCES})

target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -Werror)

target_include_directories(${EXECUTABLE}
		PRIVATE ${INCLUDE_PATH}
		PRIVATE ${INCLUDE_PATH}op/
		PRIVATE ${INCLUDE_PATH}parse/
		PRIVATE ${INCLUDE_PATH}vis/
		PRIVATE ${LIBRARY_INCLUDE_PATH}
		PRIVATE ${LIBFT_PATH}include/)

if (${CMAKE_SYSTEM_NAME} STREQUAL Linux)
	target_link_options(${EXECUTABLE} PRIVATE -Wl,-rpath=${LIBRARY_PATH})
elseif (${CMAKE_SYSTEM_NAME} STREQUAL Darwin)
	target_link_options(${EXECUTABLE} PRIVATE -Wl,-rpath,${LIBRARY_PATH})
endif()

target_link_directories(${EXECUTABLE}
		PRIVATE ${LIBRARY_PATH}
		PRIVATE ${LIBFT_PATH})

target_link_libraries(${EXECUTABLE}
		SDL2
		SDL2_image
		SDL2_mixer
		SDL2_ttf
		${LIBFT})
