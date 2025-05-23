cmake_minimum_required(VERSION 3.10)

# Defina o nome do projeto
project(GBEmu)

# Defina o padrão de versão do C++
set(CMAKE_CXX_STANDARD 17)

# Defina os diretórios de inclusão para os arquivos .hpp
include_directories(${CMAKE_SOURCE_DIR}/src/includes)

# Coletar todos os arquivos .cpp recursivamente de src e subpastas
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# Adicionar o executável a ser gerado
add_executable(GBEmu ${SOURCES})

# Default build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type specified, defaulting to Debug")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

# Set build type specific flags and output directory using set_target_properties
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Configuring Debug build")
    message(STATUS "Out dir: ${CMAKE_BINARY_DIR}/bin/Debug")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/Debug"
    )
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")  # Debugging symbols, no optimization

elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Configuring Release build")
    message(STATUS "Out dir: ${CMAKE_BINARY_DIR}/bin/Release")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/Release"
    )
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")  # High optimization, no debug symbols
endif()

# Se você estiver usando bibliotecas externas, você poderia adicionar as configurações de link aqui
# Example:
# target_link_libraries(GBEmu <library_name>)

