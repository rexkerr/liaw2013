## How do I Pass a Variable Number of Parameters to a Function?

There are a number of different ways to accomplish this in C++.  Perhaps the most basic is the *overload*, which lets you define several functions with the same name but different numbers and types of arguments:

```c++
#include <iostream>
#include <string>

void foo() {}
void foo(int a) {}
void foo(int a, std::string b) {}
void foo(int a, std::string b, bool c) {}
```
From the compiler's perspective, each of these are different functions, and so a separate
definition must be provided for each.  This may result in some code duplication if they do
similar functions.

A second option is to employ default arguments.  This may work for you if the intended
functionality in the case of a missing argument is the same as having that argument
take a particular value.  This function can accept 1, 2, or 3 arguments:

```c++
void bar(int a, char b = 'B', bool c = false) {}
```

If you should happen to have a compiler that supports the new C++11 feature of *variadic templates* (i.e., any recent one except MSVC) you can define different versions of the same function as template specializations.
```c++
template<typename ...T>
void baz(T... args)
{
   std::cout << "executing baz general case" << std::endl;
}

template<>
void baz(int a, std::string b, bool c)
{
   std::cout << "executing baz for the case of int, std::string, and bool" << std::endl;
}
```

You can also use this feature to make a function that iterates over an arbitrary number of arguments:
```c++
void recurse()
{
   // this overload is chosen when recurse is called with no arguments
   std::cout << "THE END\n";
}

template<typename Head, typename ...Tail>
void recurse(Head h, Tail... t)
{
   std::cout << h << std::endl;
   recurse(t...);
}
```

Finally, if you **absolutely must** and none of the previous techniques will work for you,
you can use the old C-style *varargs* approach:
```c++
#include <cstdarg>

void varargs_fn(int count, ...)
{
   va_list vl;
   // Arguments are enforced only by user convention.  Here we have decided that the first argument
   // will indicate how many remaining arguments there are, and that they will all be of type char const*
   va_start(vl, count);    // "count" is here because it's the last of the named parameters
                           // this helps the macros locate the beginning of the variable parameters
   for (int i = 0; i < count; ++i)
   {
      char const* str = va_arg(vl, char const*);
      std::cout << str << std::endl;
   }
   va_end(vl);
}
```
A skilled programmer should feel a bit squeamish about choosing this solution.
