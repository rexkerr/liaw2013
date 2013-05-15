#include <iostream>                             // For std::cout
#include <boost/lexical_cast.hpp>               // For boost::lexical_cast
#include <boost/numeric/conversion/cast.hpp>    // For boost::numeric_cast

int main()
{
  // Convert int to float using static_cast
  int a = 42;
  float f = static_cast<float>(a);
  std::cout << "int: " << a << " -> float: " << f << "\n";

  // Convert int to float using numeric_cast
  f = boost::numeric_cast<float>(a);
  std::cout << "int: " << a << " -> float: " << f << "\n";

  // Out of range conversion throws some exception
  try
  {
    unsigned int x = boost::numeric_cast<unsigned int >(-4);
  }
  catch(boost::numeric::bad_numeric_cast& e)
  {
    std::cout << e.what() << "\n";
  }

  // Convert int to string using lexical_cast
  std::string s = boost::lexical_cast<std::string>(a);
  std::cout << "int: " << a << " -> string: " << s << "\n";

  // Convert string to double using lexical_cast
  double d = boost::lexical_cast<double>("3.14158");
  std::cout << "string: 3.14158 -> double: " << d << "\n";

  // Wrong casting throws a bad_lexical_cast
  try
  {
    char c = boost:: lexical_cast<char>("127");
  }
  catch(boost::bad_lexical_cast& e)
  {
    std::cout << e.what() << "\n";
  }
}
