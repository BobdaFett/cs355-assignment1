add_executable(cs355_assignment1
    main.cpp
    problemOne.cpp
    problemTwo.cpp
    problemThree.cpp
)

target_include_directories(cs355_assignment1 PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)