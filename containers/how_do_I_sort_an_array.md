## How Do I Sort an Array?

Unlike many other object oriented languages, the standard containers
do not have sort methods that you can call.  Instead, sorting is done
using a generic algorithm that can work on many different container
types.

Example:

Given a vector, vect:

```c++
std::vector<int> vect = { 4, 42, 7, 16, 99 };
```

...you can sort it as follows:

```c++
std::sort(begin(vect), end(vect));
```

