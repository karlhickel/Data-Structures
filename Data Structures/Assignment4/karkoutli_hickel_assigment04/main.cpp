#include <iostream>
//#include "doubleLinkedList.h"
//#include "queue.h"
#include <fstream>
#include <stdlib.h>
#include "simulation.h"

using namespace std;

int main(){

string fileName= " ";

//Prompts user to type in file name.
cout << "enter file name: " << endl;
cin>>fileName;
Simulation s;
//Function in simulation that reads and stores file objects
s.fileReader(fileName);
//Runs the full simulation. 
s.runProgram();

  return 0;
}
