project(EntityFramework)

cmake_minimum_required(VERSION 2.8)

# Enlazo con los include y los lib
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/lib)

# Compilo entity-framework
add_subdirectory(lib)

# Genero ejecutable de test
add_executable(test-entity test/test-entity.cpp)
target_link_libraries(test-entity entity-framework)
