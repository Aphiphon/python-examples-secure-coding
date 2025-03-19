#include <iostream>
#include <string>
#include <pybind11/pybind11.h>
#include "hello.h"

namespace py = pybind11;

// Pybind11 module definition
PYBIND11_MODULE(hello, m) {
    m.def("hello_world", &hello_world, "A function that returns 'Hello, World!'");
}
