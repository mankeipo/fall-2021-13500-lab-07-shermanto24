#include <iostream>
#include <fstream>
#include "funcs.h"

int main()
{
  //task A
  std::cout << "Task A\n" << '\n';

  std::ifstream in_file1;
  in_file1.open("bad-code1.cpp");

  std::ofstream out_file1;
  out_file1.open("unindented-code1.cpp");

  while (!in_file1.fail())
  {
    std::string ogline;
    getline(in_file1, ogline);
    std::string resultline = removeLeadingSpaces(ogline);
    std::cout << resultline << '\n';
    out_file1 << resultline << '\n';
  }

  in_file1.close();
  out_file1.close();

  //task B
  std::cout << "Task B\n" << '\n';

  std::ifstream in_file2;
  in_file2.open("unindented-code1.cpp");

  std::ofstream out_file2;
  out_file2.open("fixed-code1.cpp");
  
  int openblocks = 0;

  while (!in_file2.fail())
  {
    std::string ogline;
    getline(in_file2, ogline);

    if (countChar(ogline, '}') >= 1)
      openblocks--;

    std::string resultline = ogline;
    for (int i = 0; i < openblocks; i++)
      resultline = '\t' + resultline;

    if (countChar(ogline, '{') >= 1)
      openblocks++;

    std::cout << resultline << '\n';
    out_file2 << resultline << 'n';
  }
}
