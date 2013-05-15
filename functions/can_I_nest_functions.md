## Can I nest functions?

Not directly.  However, you can define classes with static member functions and call them.  Starting with C++11, you can also define lambda functions and bind them to a variable, which you can then call.

```c++
// This will not compile
void f()
{
  void nested() {
  }

  nested();
}

// Using a nested struct
void f_nested_struct()
{
  struct fn_holder
  {
    static void nested()
    {
      // your code here
    }
  };

  fn_holder::nested();
}

// Using a local lambda
void f_with_lambda()
{
  auto nested = []()
  {
    // your code here
  };
  nested();
}
```
