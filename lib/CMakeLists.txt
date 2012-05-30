FILE(GLOB EF_CPP "*.cpp")

add_subdirectory(lib_json)

add_library(entity-framework ${EF_CPP})
target_link_libraries(entity-framework jsoncpp)
