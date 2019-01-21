#include <iostream>
#include <string>
#include <fstream>
#include "syntaxChecker.h"
using namespace std;
//Seperate class to read an input file and return any syntax errors. 
class readFile
{
public:
  readFile();
  ~readFile();
  void fileReader(string name);
  string name;


};
