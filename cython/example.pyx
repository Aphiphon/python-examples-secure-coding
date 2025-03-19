# Enable C++ support
# distutils: language = c++

# Include C++ code
cdef extern from "<cmath>" namespace "std":
    double sqrt(double x)

def add_numbers(int a, int b):
    return a + b

def calculate_sqrt(double x):
    return sqrt(x)
