#include <iostream>
#include "funcs.h"

int main()
{
  std::cout << "------------- FIRST TEST -------------\n" << '\n';
  fixIndent("bad-code1.cpp");

  std::cout << '\n' << "------------- SECOND TEST -------------\n\n";
  fixIndent("bad-code2.cpp");
}
