#include <iostream>
#include <cctype>
#include <fstream>
#include "funcs.h"

//----------------- task A -----------------

std::string removeLeadingSpaces(std::string line)
{
  std::string result = "";
  bool start = false;

  for (int i = 0; i < line.length(); i++)
  {
    char curr = line[i];

    if (!isspace(curr))
      start = true;

    if (start)
      result += curr;
  }

  return result;
}

//----------------- task B -----------------

int countChar(std::string line, char c)
{
  int result = 0;

  for (int i = 0; i < line.length(); i++)
  {
    if (line[i] == c)
      result++;
  }

  return result;
}

void fixIndent(std::string filename)
{
  //task A
  std::cout << "Task A: unindenting " << filename << "\n" << '\n';

  std::ifstream in_file1;
  in_file1.open(filename);

  std::ofstream out_file1;
  out_file1.open("unindented-" + filename);

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
  std::cout << "Task B: fixing the indentation of " << filename << "\n" << '\n';

  std::ifstream in_file2;
  in_file2.open("unindented-" + filename);

  std::ofstream out_file2;
  out_file2.open("fixed-" + filename);

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
    out_file2 << resultline << '\n';
  }
}
