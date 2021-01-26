#include <iostream>

#include "tga/tgaimage.h"

int main()
{
  union A
  {
    int32_t x;
    int8_t y[4];
  };

  struct B
  {
    int z;
    A a;
  };

  union C
  {
    B b;
    int p;
  };

  C c;
  c.b.a.y[2] = 1;

  std::cout << c.b.z << std::endl;

  return EXIT_SUCCESS;
}