#ifndef NIAS_CPP_EXAMPLE_MYVECTOR_H
#define NIAS_CPP_EXAMPLE_MYVECTOR_H

#include <vector>
#include <nias-cpp/vector.h>

class MyVector : public NiasVector
{
public:
  // Inherit constructors
  using NiasVector::NiasVector;
};

#endif // NIAS_CPP_EXAMPLE_MYVECTOR_H
