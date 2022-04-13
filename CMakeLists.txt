cmake_minimum_required(VERSION 3.21)
project(RLG_Cmake)

set(CMAKE_CXX_STANDARD 17)

link_directories(lib)
link_libraries(raylib)

include_directories(lib
        lib/raylib-cpp
        lib/chaiscript
        )

set(CORE
        src/main.cpp
        #        src/core/builder.cpp
        src/core/execCtx.cpp
        src/core/state.cpp
        src/core/widget.cpp
        src/core/widget_container_draggable.cpp
        src/core/widget_draggable.cpp
        src/core/guiBuilder.cpp src/core/guiBuilder.h src/core/GameStore.cpp src/core/GameStore.h lib/raycolors.h)

set(WIDGETS
        src/widgets/WG_TextInput.cpp
        src/widgets/WG_Window.cpp
        src/widgets/WG_Button.cpp src/widgets/WG_Button.h)

add_executable(RLG_Cmake
        ${CORE}
        ${WIDGETS}
        )

if (APPLE)
    target_link_libraries(RLG_Cmake PRIVATE
            "-framework OpenGL"
            "-framework CoreVideo"
            "-framework IOKit"
            "-framework Cocoa"
            "-framework GLUT"
            )
endif ()