# python-examples-secure-coding

## Cython

### Go to cython directory

```bash
cd cython
```

#### Install cython in virtual environment

```bash
python3 -m venv .venv --system-site-packages
source .venv/bin/activate
pip install cython
```

#### Build cython module

```bash
python setup.py build_ext --inplace
```

#### Test cython module

```bash
python test_example.py
```

## Pybind11

### Go to pybind11 directory

```bash
cd pybind11
```

#### Install cmake and pybind11

```bash
brew install cmake
brew install pybind11
```

#### Build the cpp project

```bash
cmake -S . -B build_cpp -DBUILD_PYTHON_MODULE=OFF
cmake --build build_cpp -j4
```

#### Build the python project

```bash
cmake -S . -B build_python -DBUILD_PYTHON_MODULE=ON
cmake --build build_python -j4
module_file=$(ls build_python/*.so)
cp $module_file .
```

#### Test pybind11 module

```bash
python main.py
```

#### Install python module to python system site

```bash
sudo cmake --install build_python
```
