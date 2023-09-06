cmake_minimum_required(VERSION 3.5)

project(audioclient3_clean_windows)

add_executable(audioclient3_clean_windows
    windows/portaudio_impl3_clean.cpp
)

target_link_libraries(audioclient3_clean_windows
    -lportaudio
)