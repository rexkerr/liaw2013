#include <algorithm>  // for for_each, transform
#include <iostream>   // for cout

namespace
{
   void print_vector(std::vector<int> v)
   {
      std::for_each(begin(v), end(v), [](int i){ std::cout << i << " "; });
      std::cout << "\n" << std::endl;
   }
}

int main()
{
   // Using a for loop
   {
      std::vector<int> v = {1,2,3,4};

      std::cout << "for loop:  ";

      for(std::vector<int>::size_type i = 0; i < v.size(); ++i)
      {
         v[i] *= 2;
      }

      print_vector(v);
   }

   // Using a range based for
   {
      std::vector<int> v = {1,2,3,4};
      std::cout << "range for:  ";

      for(int &i : v)
      {
         i *= 2;
      }

      print_vector(v);
   }

   // Using for_each
   {
      std::vector<int> v = {1,2,3,4};
      std::cout << "for_each:  ";

      std::for_each(begin(v), end(v), [](int &i) { i*=2; });

      print_vector(v);
   }


   // Using transform
   {
      std::vector<int> v = {1,2,3,4};
      std::vector<int> v2;
      std::cout << "transform:  ";

      std::transform(begin(v), end(v), std::back_inserter(v2), [](int i) { return i*2; });

      print_vector(v2);
   }
}

