#include <pybind11/stl_bind.h>

#include <nias-cpp-example/vector.h>

PYBIND11_MODULE(nias_cpp_example, m) {
    m.doc() = "nias-cpp-example bindings"; // optional module docstring
    pybind11::bind_vector<MyVector>(m, "MyVector", pybind11::module_local(false));
}
