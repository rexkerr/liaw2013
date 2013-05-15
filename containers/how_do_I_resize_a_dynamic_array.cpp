#include <vector>     // for vector
#include <iostream>   // for cout
#include <algorithm>  // for for_each

namespace
{
   void print_vector(std::vector<int> v)
   {
      std::cout << "size:  " << v.size() << std::endl;
      std::cout << "content:  ";
      std::for_each(begin(v), end(v), [](int i){ std::cout << i << " "; });
      std::cout << "\n" << std::endl;
   }
}

int main()
{
   std::vector<int> v = {1, 2, 3};
   print_vector(v);

   v.resize(5);
   // Vector now contains: 1,2,3,0,0
   print_vector(v);

   v.resize(7, 42);
   // Vector now contains: 1,2,3,0,0,42,42
   print_vector(v);

   v.resize(2);
   // Vector now contains: 1,2
   print_vector(v);
}

