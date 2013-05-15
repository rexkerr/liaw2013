## How Do I Concatenate An Array?

Since vectors are dynamically sized, concatenating data to the end of
them is very easy:

```c++
std::vector<int> dynamic_array = { 1, 2, 3, 4, 5 };
std::vector<int> dynamic_array2 = { 6, 7, 8, 9, 10 };

dynamic_array.insert(end(dynamic_array), begin(dynamic_array2), end(dynamic_array2));

// now contains:  1 2 3 4 5 6 7 8 9 10 
```

Notice that concatenation is actually just a special case of
insertion.  We are inserting the contents of the second vector at the
end of the first.  This means that prepending is just as easy:


```c++
dynamic_array.insert(begin(dynamic_array), begin(dynamic_array2), end(dynamic_array2));

// now contains:  6 7 8 9 10 1 2 3 4 5 
```

... or even inserting somewhere in the middle ...


```c++
dynamic_array.insert(begin(dynamic_array) + 2, begin(dynamic_array2), end(dynamic_array2));

// now contains:  1 2 6 7 8 9 10 3 4 5 
```

