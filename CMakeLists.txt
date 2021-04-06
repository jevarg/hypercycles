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

add_executable(hypercycles
    src/adlib.c
    src/adt.c
    src/assets.c
    src/audio.c
    src/c_mod1.c
    src/config.c
    src/conio.c
    src/ctv.c
    src/debug.c
    src/demo.c
    src/doctor.c
    src/dos.c
    src/fixpoint.c
    src/game_save.c
    src/h3d_gfx1.c
    src/hyper6.c
    src/i86.c
    src/input.c
    src/inventory.c
    src/level.c
    src/memuse.c
    src/menu.c
    src/midimain.c
    src/midiplay.c
    src/object.c
    src/outchip.c
    src/picture.c
    src/process.c
    src/raycast.c
    src/rendering.c
    src/stdlib_watcom.c
    src/string_watcom.c
    src/timer.c
    src/trig.c
    src/unistd_watcom.c
    src/weapon.c
    src/window.c
    src/world.c
)

target_include_directories(hypercycles PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(hypercycles
    m
    ${SDL2_LIBRARIES}
    ${CURSES_LIBRARIES}
)

