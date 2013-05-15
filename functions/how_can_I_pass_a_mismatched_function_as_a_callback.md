## How Can I Pass a Mismatched Function as a Callback?

If the callback accepts function objects, you can use std::bind to produce a function object with the desired signature:
```C++
#include <functional>
#include <string>

typedef std::function<int(char const*)> fnobj_t;
void caller_fnobj(fnobj_t callback)
{
   int result = callback("hello callee");
}

// candidate callbacks

// both arg and return types are convertible
short cvt_callback(std::string const&) {}

// arg/return types are same but there is an extra arg
int extraarg_callback(char const*, unsigned) {}

int main()
{
   // the callback with convertible types with work directly with the function object
   caller_fnobj(&cvt_callback);

   // the callback with an extra argument will work with the function object if
   // we adapt it using std::bind
   using std::placeholders::_1;
   caller_fnobj(std::bind(&extraarg_callback, _1, 42u));
}
```

If the callback expects a function pointer, C++11 lambdas may be used:
```C++
// test function with function pointer callback
typedef int (*fnptr_t)(char const*);
void caller_fnptr(fnptr_t callback)
{
   int result = callback("hello callee");
}

int main()
{
   caller_fnptr([](char const* c)->int {   // use expected signature
         return cvt_callback(c);           // compiler performs conversions
      });

   caller_fnptr([](char const* c)->int {
         return extraarg_callback(c, 42);  // or pass desired value into lambda
      });
}
```
If C++11 is not available to you, manually wrapping the function you wish to be called inside another with the right signature is the only remaining option.

