cmake_minimum_required(VERSION 3.7)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_C_FLAGS_DEBUG "-Wcast-align -Wconversion -Wdouble-promotion -Wduplicated-branches -Wduplicated-cond -Wformat=2 -Wlogical-op -Wmisleading-indentation -Wnull-dereference -Wshadow -Wsign-conversion -Wunused -D DEBUG -ggdb3 -O0")

project(hypercycles)

find_package(SDL2 REQUIRED)
find_package(Curses REQUIRED)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${CURSES_INCLUDE_DIR}
)

set (SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set (INC_DIR ${CMAKE_SOURCE_DIR}/include)

set(COMMON_SOURCES
    ${SRC_DIR}/c_mod1.c
    ${SRC_DIR}/dos.c
    ${SRC_DIR}/i86.c
    ${SRC_DIR}/stdlib_watcom.c
    ${SRC_DIR}/string_watcom.c
    ${SRC_DIR}/unistd_watcom.c
)

add_executable(hypercycles
    ${COMMON_SOURCES}
    ${SRC_DIR}/adlib.c
    ${SRC_DIR}/adt.c
    ${SRC_DIR}/assets.c
    ${SRC_DIR}/audio.c
    ${SRC_DIR}/c_mod1.c
    ${SRC_DIR}/config.c
    ${SRC_DIR}/conio.c
    ${SRC_DIR}/ctv.c
    ${SRC_DIR}/debug.c
    ${SRC_DIR}/demo.c
    ${SRC_DIR}/doctor.c
    ${SRC_DIR}/fixpoint.c
    ${SRC_DIR}/game_save.c
    ${SRC_DIR}/h3d_gfx1.c
    ${SRC_DIR}/hyper6.c
    ${SRC_DIR}/input.c
    ${SRC_DIR}/inventory.c
    ${SRC_DIR}/level.c
    ${SRC_DIR}/memuse.c
    ${SRC_DIR}/menu.c
    ${SRC_DIR}/midimain.c
    ${SRC_DIR}/midiplay.c
    ${SRC_DIR}/object.c
    ${SRC_DIR}/outchip.c
    ${SRC_DIR}/picture.c
    ${SRC_DIR}/process.c
    ${SRC_DIR}/raycast.c
    ${SRC_DIR}/rendering.c
    ${SRC_DIR}/timer.c
    ${SRC_DIR}/trig.c
    ${SRC_DIR}/weapon.c
    ${SRC_DIR}/window.c
    ${SRC_DIR}/world.c
)

add_executable(builder
    ${COMMON_SOURCES}
    ${SRC_DIR}/build1.c
)

target_include_directories(hypercycles PRIVATE ${INC_DIR})
target_include_directories(builder PRIVATE ${INC_DIR})

target_link_libraries(hypercycles
    m
    ${SDL2_LIBRARIES}
    ${CURSES_LIBRARIES}
)

target_link_libraries(builder
    m
    ${CURSES_LIBRARIES}
)

