cmake_minimum_required(VERSION 3.16)

# 1. ONLY CHANGE THIS LINE FOR NEW PROJECTS
project(Program05_Student_Grades LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. This line tells the compiler to search the include/ folder for .h files:
include_directories(include)

#3 List all .cpp source files under a single add_executable command
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Students.cpp
)

# 4. This also automatically updates
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

