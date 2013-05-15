

no, but... local lambda


void f()
{
  auto l []{ /* do stuff */ };

  l();
  l();
  l();
}


void f()
{
   struct S
   {
      static void foo() {}
   };

   S::foo();
}
