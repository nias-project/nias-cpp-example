#include <iostream>
#include <vector>

#include <nias-cpp/gram_schmidt.h>
#include <nias-cpp/vector.h>
#include <nias-cpp-example/vector.h>

int main()
{
  namespace py = pybind11;

  // Create some vectors
  MyVector v1({1., 2., 3.});
  MyVector v2({4., 5., 6.});
  MyVector v3({7., 8., 9.});

  // Create a vector of vectors
  std::vector<NiasVector*> vectors = {&v1, &v2, &v3};

  py::scoped_interpreter guard{}; // start the interpreter and keep it alive


  // test py::exec
  py::exec(R"(
    from nias_cpp_example import *
    print(f'globals from py: {globals()}')
  )");

  // // do something similar using the Pybind11's C++ API
  // py::module_ our_py_module = py::module::import("nias_cpp_example");
  // py::object MyPyVector = our_py_module.attr("MyVector");
  // py::print(py::globals());

  // Create a vector of Python-compatible vectors
  std::vector<py::object> py_vectors;
  for (auto* vec : vectors) {
    py_vectors.push_back(py::cast(vec));
  }

  // Perform Gram-Schmidt orthogonalization
  auto orthonormalized_vectors = nias::gram_schmidt(vectors);

  // // print result
  // int i = 0;
  // for (auto& vec : orthonormalized_vectors) {
  //   std::cout << "vec" << i++ << ": ";
  //   for (auto& entry : vec) {
  //     std::cout << entry << " ";
  //   }
  //   std::cout << std::endl;
  // }
  // return 0;
}
