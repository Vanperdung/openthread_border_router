add_executable(otbr-agent
    main.cpp
    application.cpp
)

target_link_libraries(otbr-agent PRIVATE
    otbr-common
)
