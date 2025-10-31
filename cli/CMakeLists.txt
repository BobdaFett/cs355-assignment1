if (MSVC)
    add_executable(cs355_assignment1_clr main.cpp
            include/problemThree.h
            problemThree.cpp
            problemFive.cpp
            problemSix.cpp
    )
    
    # Prevent linking native runtime
    set_target_properties(cs355_assignment1_clr PROPERTIES
        COMMON_LANGUAGE_RUNTIME ""
        LINKER_LANGUAGE CXX
        VS_DOTNET_REFERENCES "System"
    )

    target_include_directories(cs355_assignment1_clr PRIVATE
        ${CMAKE_SOURCE_DIR}/cli/include
    )
else()
    message(NOTICE "MSVC target not found, skipping CLR build.")
endif()
