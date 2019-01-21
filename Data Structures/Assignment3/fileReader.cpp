#include <iostream>
#include <string>
#include <fstream>
#include "fileReader.h"
#include <stdlib.h>
using namespace std;


readFile::readFile()
{

}

readFile::~readFile()
{

}
//Takes in a
void readFile::fileReader(string name)
{
  ifstream myFile;
  string fileName = name;
  myFile.open(fileName);
  string input;
  int numLine = 0;
  GenStack<char> g(5);
  int test = 1;
  int result = 1;

//Runs through the file.
  while(!myFile.eof())
	{


    if(test == 0)
    {
      break;
    }

    numLine++;

    getline(myFile,input);
    for (int i = 0; i < input.size(); ++i)
			{
        if(input[i] == '{')
        {
          g.push('{');
        }
        else if(input[i] == '[')
        {
          g.push('[');
        }
        else if(input[i] == '(')
        {
          g.push('(');
        }



//Checks to see if the brackets match eachother, if not the for loop breaks, along with the while loop. Then tells you error location.
        if (input[i] == '}')
        {
          if (g.peek() == '{')
          {
            g.pop();
          }
          else
          {
            cout << "You have an error on line " << numLine <<". Your opening brace should be '{'." << endl;
            test = 0;
            result = 0;
            break;

          }
        }


        else if (input[i] == ']')
        {
          if (g.peek() == '[')
          {
            g.pop();
          }
          else
          {
            cout << "You have an error on line " << numLine <<". Your opening brace should be '['." << endl;
            test = 0;
            result = 0;
            break;
          }
        }

        else if (input[i] == ')')
        {
          if(g.peek() == '(')
          {
            g.pop();
          }
          else
          {
            cout << "You have an error on line " << numLine <<". Your opening brace should be '('." << endl;
            test = 0;
            result = 0;
            break;
          }
        }
      }
  }
  //Checks to see if there are any remainding curly brackets in the stack.
  if(g.peek() == '{' || g.peek() =='(' || g.peek() == '[')
  {
    cout << "You require a closing bracket at the very end of your code on line " << numLine << endl;
    test = 1;
    result = 0;
  }
// Reports if there are no errors
  if(result == 1)
  {
    cout << "You have no errors to report." << endl;
  }
  myFile.close();
}
