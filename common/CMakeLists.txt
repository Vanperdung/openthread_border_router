add_library(otbr-common STATIC
    code_utils.cpp
)

target_include_directories(otbr-common PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
