## How Do I Create A Statically Sized Array?

C++ provides an array container called std::array<T,N>.  You create
the array by specifying the type of data that it contains and its
size, as follows:

```c++
std::array<int, 5> myarray = {1,2,3,4,5};
```

The initialization after the equals sign is optional.  If no initial
values are provided, each element in the array will be default
constructed.

Sometimes it is necessary to send the array to an older C style
method, which doesn't recognize the std::array type.  This can be done
by using the data() member function:

```c++
takes_c_style_array(myarray.data(), myarray.size());
```

