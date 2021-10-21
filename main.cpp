#include <iostream>
#include <fstream>
#include "funcs.h"

int main()
{
  //task A
  std::ifstream in_file1;
  in_file1.open("bad-code1.cpp");

  while (!in_file1.fail())
  {
    std::string ogline;
    getline(in_file1, ogline);
    //std::cout << ogline << '\n';
    std::string resultline = removeLeadingSpaces(ogline);
    std::cout << resultline << '\n';
  }
}
