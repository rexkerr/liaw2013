#include <algorithm>
#include <array>
#include <iostream>

namespace
{
   void takes_c_style_array(int* data, int length)
   {
      for(int i = 0; i < length; ++i)
      {
         std::cout << *(data+i) << " ";
      }
      std::cout << std::endl;
   }
}


int main()
{
   std::array<int, 5> myarray = {1,2,3,4,5};

   std::for_each(begin(myarray), end(myarray), [](int i){ std::cout << i << " "; });
   std::cout << std::endl;

   takes_c_style_array(myarray.data(), myarray.size());
}

