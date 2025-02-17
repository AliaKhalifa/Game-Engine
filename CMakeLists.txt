cmake_minimum_required(VERSION 3.0.0)   # Selects the minimum version of CMake required to run this file
project(GFX-LAB VERSION 0.1.0)          # Here we select the project name and version

# Here we select C++17 with all the standards required and all compiler-specific extensions disabled
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# These are the options we select for building GLFW as a library
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)        # Don't build Documentation
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)       # Don't build Tests
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)    # Don't build Examples
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)           # Don't build Installation Information
set(GLFW_USE_HYBRID_HPG ON CACHE BOOL "" FORCE)     # Add variables to use High Performance Graphics Card if available
add_subdirectory(vendor/glfw)                       # Build the GLFW project to use later as a library

# A variable with all the source files of GLAD
set(GLAD_SOURCE vendor/glad/src/gl.c)
# A variables with all the source files of Dear ImGui
set(IMGUI_SOURCES
        vendor/imgui/imgui.cpp
        vendor/imgui/imgui_demo.cpp
        vendor/imgui/imgui_draw.cpp
        vendor/imgui/imgui_widgets.cpp
        vendor/imgui/imgui_impl/imgui_impl_glfw.cpp
        vendor/imgui/imgui_impl/imgui_impl_opengl3.cpp
        )

# Combine all vendor source files together into a single variable
set(VENDOR_SOURCES ${GLAD_SOURCE} ${IMGUI_SOURCES})

# A variable with all our source files that are common between executable targets (examples)
set(COMMON_SOURCES
        source/common/application.cpp
        source/common/shader.cpp
        source/common/texture/texture-utils.cpp
        source/common/texture/screenshot.cpp
        source/common/mesh/mesh-utils.cpp source/common/Material.hpp source/common/Material.cpp source/common/Texture2D.h source/common/Texture2D.cpp source/common/Sampler2D.h source/common/Sampler2D.cpp source/common/RenderState.hpp source/common/Components/Component.cpp source/common/Components/Component.h source/common/Entity.cpp source/common/Entity.h source/common/Components/TransformComponent.cpp source/common/Components/TransformComponent.h source/common/Components/CameraControllerComponent.cpp source/common/Components/CameraControllerComponent.h source/common/Components/CameraComponent.cpp source/common/Components/CameraComponent.h source/States/State.cpp source/States/State.h source/States/PlayState.cpp source/States/PlayState.h source/States/MenuState.cpp source/States/MenuState.h source/common/Components/MeshRenderer.cpp source/common/Components/MeshRenderer.h source/common/mesh/mesh.hpp source/common/RendererSystem.hpp source/common/Components/LightComponent.h source/common/Components/LightComponent.cpp source/gameLogic/playerSystem.cpp source/gameLogic/playerSystem.h source/gameLogic/playerSystem.cpp)
# Define the directories in which to search for the included headers
include_directories(
        source/common
        vendor/glfw/include
        vendor/glad/include
        vendor/glm
        vendor/imgui
        vendor/utils
)

add_executable(APPLICATION source/common/application.cpp ${COMMON_SOURCES} ${VENDOR_SOURCES})
target_link_libraries(APPLICATION glfw)
# we add an executable target
# the target compiles the source file and the common & vendor source files
# Then we link GLFW with it
#add_executable(DRAWSHAPES source/drawshapes.cpp ${COMMON_SOURCES} ${VENDOR_SOURCES})
#target_link_libraries(DRAWSHAPES glfw)