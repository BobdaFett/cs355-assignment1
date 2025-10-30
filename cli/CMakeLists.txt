if (MSVC)
    add_executable(cs355_assignment1_clr main.cpp)
    # Enable CLR for proper compilation
    target_compile_options(cs355_assignment1_clr PRIVATE /clr)
    
    # Prevent linking native runtime
    set_target_properties(cs355_assignment1_clr PROPERTIES
        COMMON_LANGUAGE_RUNTIME ""
        LINKER_LANGUAGE CXX
    )
else()
    message(NOTICE "MSVC target not found, skipping CLR build.")
endif()
