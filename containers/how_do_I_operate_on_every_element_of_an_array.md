## How do I Operate on Every Element of An Array?

There are many ways to operate on every element of an array.

```c++
// Using a for loop
{
   std::vector<int> v = {1,2,3,4};

   std::cout << "for loop:  ";

   for(auto i = 0; i < v.size(); ++i)
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
```

