#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>


using namespace std;

class Simulation
{
public:

  Simulation();
  ~Simulation();

  void classicMode();
  void donutMode();
  void mirrorMode();
  void printGrid();
  void swap();
  char** grid;
  char** grid2;
  int uperLeftCorner(int i, int j);
  int uperRightCorner();
  int lowerRightCorner();
  int lowerLeftCorner();
  int upperRow();
  int lowerRow();
  int rightColumn();
  int leftColumn();
  char decision;
  int row;
  int column;
  int numberIndex;
  double densityProbability;
  int numX;
  int numMinus;
  int randR;
  int randC;
  int counterAlive;
  int arrayCounter;
  int Decider;
  int counterGen;
  int Loopdy;
  int emptyCount;
  int fullCount;
  char Enter;






};
