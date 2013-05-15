## How Do I Resize a Dynamic Array?

C++ vectors can be resized easily using the .resize() method.  Resize
takes two parameters, the new size and [optionally] the default value
to be assigned to newly added elements [if any].  resize() can be used
to both grow and shrink the vector.

```c++
std::vector<int> v = {1, 2, 3};
// Vector now contains: 1,2,3

v.resize(5);
// Vector now contains: 1,2,3,0,0

v.resize(7, 42);
// Vector now contains: 1,2,3,0,0,42,42

v.resize(2);
// Vector now contains: 1,2
```
