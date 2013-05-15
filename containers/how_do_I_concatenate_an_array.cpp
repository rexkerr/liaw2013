#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
   // concatenation
   {
      std::vector<int> dynamic_array = { 1, 2, 3, 4, 5 };
      std::vector<int> dynamic_array2 = { 6, 7, 8, 9, 10 };

      dynamic_array.insert(end(dynamic_array), begin(dynamic_array2), end(dynamic_array2));

      std::for_each(begin(dynamic_array), end(dynamic_array), [](int i){ std::cout << i << " "; });
      std::cout << std::endl;
   }

   // prepending
   {
      std::vector<int> dynamic_array = { 1, 2, 3, 4, 5 };
      std::vector<int> dynamic_array2 = { 6, 7, 8, 9, 10 };

      dynamic_array.insert(begin(dynamic_array), begin(dynamic_array2), end(dynamic_array2));

      std::for_each(begin(dynamic_array), end(dynamic_array), [](int i){ std::cout << i << " "; });
      std::cout << std::endl;
   }

   // prepending
   {
      std::vector<int> dynamic_array = { 1, 2, 3, 4, 5 };
      std::vector<int> dynamic_array2 = { 6, 7, 8, 9, 10 };

      dynamic_array.insert(begin(dynamic_array) + 2, begin(dynamic_array2), end(dynamic_array2));

      std::for_each(begin(dynamic_array), end(dynamic_array), [](int i){ std::cout << i << " "; });
      std::cout << std::endl;
   }
}


