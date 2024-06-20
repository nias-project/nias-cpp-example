#include <iostream>
#include <vector>

#include <nias-cpp/gram_schmidt.h>
#include <nias-cpp/vector.h>
#include <nias-cpp-example/vector.h>

void print(const std::vector<nias::NiasVector>& vecs)
{
  int i = 0;
  for (auto& vec : vecs) {
    std::cout << "vec" << i++ << ": ";
    for (auto& entry : vec) {
      std::cout << entry << " ";
    }
    std::cout << std::endl;
  }

  // print result
  std::cout << "Inner products: " << std::endl;
  for (auto&& vec1 : vecs) {
      for (auto&& vec2 : vecs) {
          std::cout << vec1.dot(vec2) << " ";
      }
      std::cout << std::endl;
  }
}

int main()
{
  namespace py = pybind11;

  // Create some vectors
  MyVector v1({1., 2., 3.});
  MyVector v2({4., 5., 6.});
  MyVector v3({7., 8., 9.});
  std::vector<nias::NiasVector> vectors = {v1, v2, v3};

  std::cout << "======== Input ======== " << std::endl;
  print(vectors);

  py::scoped_interpreter guard{}; // start the interpreter and keep it alive

  // Perform Gram-Schmidt orthogonalization
  std::cout << std::endl;
  std::cout << "Performing Gram-Schmidt orthogonalization... ";
  auto orthonormalized_vectors = nias::gram_schmidt(vectors);
  std::cout << "done! " << std::endl;
  std::cout << std::endl;

  std::cout << "======== Output ======== " << std::endl;
  print(orthonormalized_vectors);
  return 0;
}
