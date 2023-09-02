cmake_minimum_required(VERSION 3.5)

# Define a arquitetura desejada como x86_64
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# Defina as flags de linker para executáveis e bibliotecas compartilhadas
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -m64")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -m64")

project(audioclient)

add_executable(audioclient_linux
    linux/portaudio_impl3_linux.cpp
)

target_link_libraries(audioclient_linux
    -lportaudio
)