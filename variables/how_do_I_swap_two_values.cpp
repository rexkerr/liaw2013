#include <iostream>   // For std::cout
#include <algorithm>  // For std::swap

int main()
{
  // Original values
  float a = 4.2f, b = 6.9f;

  std::cout << "a: " << a << " ";
  std::cout << "b: " << b << "\n";

  // Swapping values
  std::swap(a,b);
  std::cout << "-----------------\n";

  // Swapped values
  std::cout << "a: " << a << " ";
  std::cout << "b: " << b << "\n";
}
