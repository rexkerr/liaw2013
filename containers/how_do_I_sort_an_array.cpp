#include <vector>    // for vector
#include <algorithm> // for sort & for_each
#include <iostream>  // for cout

namespace
{
   std::vector<int> vect = { 4, 42, 7, 16, 99 };

   void print_vector(std::vector<int> v)
   {
      std::for_each(begin(vect), end(vect), [](int i){ std::cout << i << " " << std::endl; });
      std::cout << std::endl;
   }
}

int main()
{
   std::cout << "Before sorting:  " << std::endl;
   print_vector(vect);

// ---> example starts here

   std::sort(begin(vect), end(vect));

// <--- example ends here

   std::cout << "After sorting:  " << std::endl;
   print_vector(vect);
}

