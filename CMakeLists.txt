cmake_minimum_required(VERSION 3.5)

project(audioclient)

add_executable(audioclient_linux
    linux/portaudio_impl3_linux.cpp
)

target_link_libraries(audioclient_linux
    -lportaudio
)