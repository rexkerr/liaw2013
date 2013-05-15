#include <algorithm> // for for_each
#include <iostream>  // for cout
#include <vector>    // for vector

namespace
{
   void print_vector(std::vector<int> v)
   {
      std::for_each(begin(v), end(v), [](int i){ std::cout << i << " "; });
      std::cout << std::endl;
   }
}

int main()
{
   std::vector<int> v = { 1, 3, 4};

   v.push_back(5);

   v.insert(begin(v), 0);

   v.insert(begin(v) + 2, 2);

   print_vector(v);
}

