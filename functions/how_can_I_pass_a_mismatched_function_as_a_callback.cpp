#include <string>
#include <functional>

// test function with function pointer callback
typedef int (*fnptr_t)(char const*);
void caller_fnptr(fnptr_t callback)
{
   int result = callback("hello callee");
}

// test function with function object callback
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

   // Unfortunately the same things will not compile with the function pointer:

   // caller_fnptr(&cvt_callback);  // not directly usable, even though signature is convertible

   // std::function cannot be converted to a function (though the reverse does work)
   // caller_fnptr(std::function<int(char const*)>(&cvt_callback))
   
   // std::bind suffers from the same problem
   // caller_fnptr(std::bind(&extraarg_callback, _1, 42u));

   // Solution: use C++11 lambdas, which are compatible with function pointers:
   caller_fnptr([](char const* c)->int {   // use expected signature
         return cvt_callback(c);           // compiler performs conversions
      });

   caller_fnptr([](char const* c)->int {
         return extraarg_callback(c, 42);  // or pass desired value into lambda
      });

}
