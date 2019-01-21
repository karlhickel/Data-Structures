/*
Karl Hickel
ID:2278978
CPSC 350-01
Assignment 3
hicke111@mail.chapman.edu
*/


#include <iostream>
#include "fileReader.h"
#include <string>
#include <fstream>

using namespace std;

//Simply calls my file reading function from a class in fileReader.cpp
int main(int argc , char** argv)
{
  string fileInput = argv[1];
  readFile a;
  a.fileReader(fileInput);


}
