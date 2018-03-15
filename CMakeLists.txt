
cmake_minimum_required(VERSION 3.0)
project(DDRoller)

message(STATUS "${PROJECT_NAME} - Starting configuration.")

if(MSVC)
    set(D "/D")
else(MSVC)
    set(D "-D")
endif(MSVC)

set(${PROJECT_NAME}_sources
    #headers
    Include/diceapplication.h
    Include/diceframe.h
    Include/enums.h
    #sources
    Src/diceapplication.cpp
    Src/diceframe.cpp
    Src/main.cpp)

add_subdirectory(Lib/pugiXML)
add_subdirectory(Lib/wxWidgets)

set(wx_includes "${${PROJECT_NAME}_SOURCE_DIR}/Lib/wxWidgets/include")
if(MINGW)
    set(wx_includes ${wx_includes} "${${PROJECT_NAME}_BINARY_DIR}/Lib/gcc_lib/mswu")
endif(MINGW)
set(wx_link_DIR "")
if(MINGW)
    set(wx_link_DIR "${${PROJECT_NAME}_BINARY_DIR}/Lib/gcc_lib")
endif(MINGW)
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    add_definitions(${D}NDEBUG)

    set(wx_link_names
        core
        base
    )
else(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(wx_link_names
        core
        base
    )
endif(CMAKE_BUILD_TYPE MATCHES "Debug")

message(STATUS "Linking against libraries found in: ${wx_link_DIR}")


add_definitions(${D}__WXMSW__ ${D}_UNICODE)

#link_directories(${wx_link_DIR})
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_sources})
#target_link_libraries(${PROJECT_NAME} -L${wx_link_DIR})
target_link_libraries(${PROJECT_NAME} pugixml ${wx_link_names})
target_include_directories(${PROJECT_NAME} PRIVATE
    "${${PROJECT_NAME}_SOURCE_DIR}/Include"
    ${wx_includes}
    "${${PROJECT_NAME}_SOURCE_DIR}/Lib/pugiXML/src")

add_dependencies(${PROJECT_NAME} pugixml core base)

message(STATUS "${PROJECT_NAME} - Finishing configuration.")
