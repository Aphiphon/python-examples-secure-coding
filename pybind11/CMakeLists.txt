cmake_minimum_required(VERSION 3.15)
project(HelloWorld VERSION 1.0)

# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable optimization flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -march=native -funroll-loops -fomit-frame-pointer -fvisibility=default")

# Option to build as a Python module or standalone executable
option(BUILD_PYTHON_MODULE "Build Python module" OFF)

if (BUILD_PYTHON_MODULE)
    # Set build type for Pybind11 module to RelWithDebInfo by default
    set(CMAKE_BUILD_TYPE RelWithDebInfo)

    # Use FindPython3 to locate the Python interpreter, libraries, and includes
    find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
    find_package(pybind11 REQUIRED)

    # Explicitly set the Python include and library directories from Python3
    include_directories(${Python3_INCLUDE_DIRS})
    link_directories(${Python3_LIBRARY_DIRS})

    # Define source files for the Python module
    set(SOURCE bindings.cpp hello.cpp)

    # Add bindings source file and hello.cpp for the Python module
    pybind11_add_module(hello MODULE ${SOURCE})

    # Link required libraries for the Python module
    target_link_libraries(hello PRIVATE ${Python3_LIBRARIES})

    # Install the Python module to the site-packages directory
    install(TARGETS hello LIBRARY DESTINATION ${Python3_SITELIB})

else()
    # Define source files for the standalone executable
    set(SOURCE main.cpp hello.cpp)

    # Build standalone C++ executable
    add_executable(hello_world ${SOURCE})

    # Install the standalone executable to /usr/local/bin
    install(TARGETS hello_world RUNTIME DESTINATION bin)
endif()
