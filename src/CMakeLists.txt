# src/CMakeLists.txt

file(GLOB_RECURSE SRC_CPP_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

file(GLOB_RECURSE SRC_H_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)


# Combine all source files
add_executable(Hooty
    ${SRC_CPP_FILES}
    ${SRC_H_FILES}
    ${SRC_UI_FILES}
)

target_link_libraries(Hooty
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Sql
)
