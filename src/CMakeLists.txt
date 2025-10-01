add_executable(FRIngine)

target_sources(FRIngine
    PRIVATE
        player.cpp
        main.cpp
)

target_compile_options(FRIngine PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -g
)

# 🚀 Link against SFML 3
target_link_libraries(FRIngine
    PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)