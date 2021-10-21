#include <iostream>
#include <cctype>
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
