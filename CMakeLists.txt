cmake_minimum_required(VERSION 3.21)
set(PROJECT_NAME "RLG_Cmake")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

link_directories(lib)
link_libraries(raylib)

include_directories(lib
        lib/raylib-cpp
        lib/chaiscript
        )

set(CORE
        src/main.cpp
        src/core/execCtx.cpp
        src/core/state.cpp
        src/core/widget.cpp
        src/core/widget_container_draggable.cpp
        src/core/widget_draggable.cpp
        src/core/guiBuilder.cpp
        src/core/guiBuilder.h
        src/core/GameStore.cpp
        src/core/GameStore.h
        lib/raycolors.h
        src/core/gameConfig.cpp
        src/core/gameConfig.h
        src/core/scriptFns.h
        src/core/textRectEX.h)

set(WIDGETS
        src/widgets/WG_TextInput.cpp
        src/widgets/WG_Window.cpp
        src/widgets/WG_Button.cpp
        src/widgets/WG_Button.h
        )

add_executable(${PROJECT_NAME}
        ${CORE}
        ${WIDGETS}
        )

if (${CMAKE_BUILD_TYPE} STREQUAL Release)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_STRIP} ${PROJECT_NAME}
            )
endif ()

if (APPLE)
    target_link_libraries(RLG_Cmake PRIVATE
            "-framework OpenGL"
            "-framework CoreVideo"
            "-framework IOKit"
            "-framework Cocoa"
            "-framework GLUT"
            )
endif ()