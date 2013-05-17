// Examples of passing variable number of parameters to a function

#include <iostream>
#include <string>

// Overloading
// You can create several functions with the same name but different numbers of arguments:
void foo() {}
void foo(int a) {}
void foo(int a, std::string b) {}
void foo(int a, std::string b, bool c) {}
// Unfortunately, each function will need to be implemented separately, so this may result
// in code duplication.

// If arguments that are not present should take a default value, you can use default parameter values:
void bar(int a, char b = 'B', bool c = false) {}
// Callers can supply a, a and b, or a, b, and c and only a single implementation is required.

// If you are using a fully compliant C++11 implementation (not MSVC) you can use variadic function templates:
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

// You can even create a completely general function that iterates over its arguments using specialization:
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

// If all the above options fail, and you simply must have a function with variable numbers of arguments,
// the old C-style "varargs" approach still works:
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
// This approach is undesirable for a number of reasons, chief among them that the number and types
// of arguments are not checked by the compiler.


int main()
{
   // try overloads (four separate functions)
   foo();
   foo(3);
   foo(3, "calling foo\'s third overload");
   foo(42, "calling foo\'s fourth overload", true);

   // try defaults (one function)
   bar(42);            // calls bar with b=='B' and c==false
   bar(42, 'Z');       // calls bar with c==false
   bar(42, 'Z', true); // supplies all arguments

   // try variadic function template with specialization
   baz();                                    // general case
   baz("does not match specialization");     // general case
   baz(42, "still does not match specialization", true);  // const char*, not std::string!
   baz(42, std::string("matches specialization"), true);

   // try variadic function template with recursion
   recurse(true, 11, "C++11 is so great");

   // do it with C-style varargs
   varargs_fn(2, "one potato", "two potato");

}

