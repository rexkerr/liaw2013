#include <iostream>

// This will not compile
/*
void f()
{
  void nested() {
  }

  nested();
}
*/

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

int main() {
   f_nested_struct();
   f_with_lambda();
}
