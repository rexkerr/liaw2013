## How do I Create a Variable Sized Array?

C++ arrays are not variable sized and do not support dynamic resizing.
That said, there is a container, std::vector<T>, that gives you the
same semantics as an array.  

The vector class works much like an array in that it guarantees
contiguous layout of its contents and the same performance
characteristics.

In order to use a vector you must first include the <vector> header:

```c++
#include <vector>
```

Then to declare the vector you must declare an instance of the vector,
specialized on the type of data that it will hold:

```c++
std::vector<int> int_vector;
std::vector<float> float_vector;
```

Each of these lines creates a zero sized vector.  It is possible
to create the vector with an initial size as follows:

```c++
std::vector<double> double_vector(25, 3.14);
```

This creates a vector of 25 doubles, all initialized to the value
3.14.  The initial value is optional.  If not provided the elements
will be initialized to double(), aka 0.0.

Note that a vector, just like an array, can only hold data of one
type.


