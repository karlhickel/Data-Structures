#include <iostream>
#include "golHeader.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unistd.h>




using namespace std;

int userChoice = 0;
int userChoice2 = 0;
int userChoice3 = 0;
char decision;
int row = 0;
int column = 0;
int numberIndex;
double densityProbability;
int numX;
int numMinus;
char** grid = new char*[row];
char** grid2 = new char*[row];
char** gridTemp = new char*[row];
int counterA = 0;
int counterB = 0;
int counterC = 0;
int counterX = 0;
int randR = 0;
int randC = 0;
int counterAlive = 0;
int arrayCounter = 0;
int Decider = 1;
int counterGen = 1;
int Loopdy = 0;
int emptyCount = 0;
int fullCount = 0;
char Enter;
int microseconds = 2000000;


int main()
{


  cout << "Write to file '1'" << endl;
  cout << "User input '2'" << endl;
  cout << "Import from file '3'" << endl;

  cin >> userChoice;
  if (userChoice == 2)
  {
    srand(time(NULL));
    cout << "Do you want to input a grid or a create a new one?" << endl;
    cout << "(Type 1 to input a grid, Type 2 to create a new one)" << endl;
    cin >> decision;

    if(decision == '1'){





    }
    else if(decision == '2')
    {

      //srand(time(NULL));
      cout << "How many rows would you like?" << endl;
      cin >> row;
      cout << "How many columns would you like?" << endl;
      cin >> column;
      cout << "How dense do you want your grid to be? (.01-.99)" << endl;
      cin >> densityProbability;
      //this creates the 2d array.

      for(int i = 0; i < row; ++i)
      {
        grid[i] = new char[column];
      }

      for(int i = 0; i < row; ++i)
      {
        grid2[i] = new char[column];
      }

      for(int i = 0; i < row; ++i)
      {
        gridTemp[i] = new char[column];
      }


      numberIndex = row * column;
      numX = numberIndex * densityProbability;
      numMinus = numberIndex - numX;


    //while(counterA < numberIndex)

        for(int i = 0; i < row; ++i)
        {
          for(int j = 0; j < column; ++j)
          {
            grid[i][j] = '-';
          }
        }




        while(counterX < numX)
        {
          randR =(rand() % row - 1) +1;
          randC = (rand() % column - 1) +1;
          grid[randR][randC] = 'X';
          counterX++;
        }

  }


       cout << endl;
       cout << "Grid1: " << endl;
       for(int i = 0; i < row; ++i)
       {
         for(int j = 0; j < column; ++j)
         {
           cout << grid[i][j];
         }
         cout << endl;
       }


       cout << "Grid2: " << endl;
       cout << endl;
       for(int i = 0; i < row; ++i)
       {
         for(int j = 0; j < column; ++j)
         {
           grid2[i][j] = grid[i][j];
           cout << grid2[i][j];
         }
         cout <<endl;
       }


    cout << "Which mode would you like to do" << endl;
    cout << "1) Classic mode" << endl;
    cout << "2) Donut mode" << endl;
    cout << "3) Mirror mode" << endl;

    cin >> userChoice2;
    if (userChoice2 == 1)
    {
      cout << "Would you like to click enter to create a new generation or " << endl;
      cout << "do you want a timer.  (1 = enter, 2 = timer) " << endl;
      cin >> userChoice3;
      while(Decider == 1)
      {

           for(int i = 0; i < row; ++i)
           {
               for(int j = 0; j < column; ++j)
               {
                 counterAlive = 0;
                 if (i == 0 && j == 0)
                 {
                   if(grid2[0][1] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[1][1] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[1][0] == 'X')
                   {
                     counterAlive++;
                   }
                 }



                 else if (i == 0 && j == column - 1)
                 {
                   if(grid2[0][column - 2] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[1][column - 2] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[1][column - 1] == 'X')
                   {
                     counterAlive++;
                   }

                 }

                 else if (i == row - 1 && j == 0)
                 {
                   if(grid2[row - 1][1] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[row - 2][0] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[row - 2][1] == 'X')
                   {
                     counterAlive++;
                   }

                 }


                 else if (i == row - 1 && j == column - 1)
                 {
                   if(grid2[row - 2][column - 1] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[row - 1][column - 2] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[row - 2][column - 2] == 'X')
                   {
                     counterAlive++;
                   }

                 }


                 else if (i == 0)
                 {
                   if (grid2[i][j-1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i][j+1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i+1][j+1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i+1][j] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i+1][j-1] == 'X')
                   {
                     counterAlive++;
                   }

                 }



                 else if (j == 0)
                 {

                   if (grid2[i-1][0] == 'X')
                   {
                     counterAlive++;
                   }

                   if (grid2[i-1][1] == 'X')
                   {
                     counterAlive++;
                   }

                   if (grid2[i][1] == 'X')
                   {
                     counterAlive++;
                   }

                   if (grid2[i+1][1] == 'X')
                   {
                     counterAlive++;
                   }

                   if (grid2[i+1][0] == 'X')
                   {
                     counterAlive++;
                   }
                 }



                 else if (i == row - 1)
                 {
                   if (grid2[row-2][j] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[row-1][j+1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[row-1][j-1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[row-2][j+1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[row-2][j-2] == 'X')
                   {
                     counterAlive++;
                   }

                 }


                 else if (j == column - 1)
                 {
                   if (grid2[i+1][column-1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i+1][column-2] == 'X')
                   {
                     counterAlive++;
                   }

                   if (grid2[i][column-2] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i-1][column-2] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i-1][column-1] == 'X')
                   {
                     counterAlive++;
                   }
                 }



                 else
                 {
                   if (grid2[i+1][j+1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i+1][j-1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i+1][j] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i][j+1] =='X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i][j-1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i-1][j+1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i-1][j] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i-1][j-1] == 'X')
                   {
                     counterAlive++;
                   }


                 }

                 if (counterAlive == 0)
                 {
                   grid[i][j] = '-';
                 }
                 else if (counterAlive == 1)
                 {
                   grid[i][j] = '-';
                 }
                 else if (counterAlive == 2)
                 {

                 }
                 else if (counterAlive == 3)
                 {
                   grid[i][j] = 'X';
                 }
                 else
                 {
                   grid[i][j] = '-';
                 }
           }

         }

         cout << endl;
         //checking if equal




       bool isEmpty = true;
       bool isIdentical = true;
       cout << "Press the ENTER key";
       cin.get();



         for(int i = 0; i < row; ++i)
         {
           for(int j = 0; j < column; ++j)
           {
             if (grid[i][j] != '-')
             {
               isEmpty = false;

             }
             if(grid2[i][j] != grid[i][j])
             {
               isIdentical = false;
             }
           }
         }

         //if(emptyCount == numberIndex || fullCount == numberIndex)
         if(isEmpty || isIdentical)
         {
           Decider = 0;
         }


         //Decider = 0;
         if (userChoice3 == 1)
         {
           cin.get();
         }
         else if (userChoice3 == 2)
         {
           usleep(microseconds);
         }

        counterGen++;

      //purely printing out changed grid
         cout << "This is generation: " << counterGen << endl;


      //updating grid2 and printing new grid 2
         for(int i = 0; i < row; ++i)
         {
           for(int j = 0; j < column; ++j)
           {
             grid2[i][j] = grid[i][j];

           }

         }

         for(int i = 0; i < row; ++i)
         {
           for(int j = 0; j < column; ++j)
           {


           }
           cout << grid2[i] << endl;
         }

         cout << endl;


      }
    }
    else if (userChoice2 == 2)
    {
      cout << "Would you like to click enter to create a new generation or " << endl;
      cout << "do you want a timer.  (1 = enter, 2 = timer) " << endl;
      cin >> userChoice3;
      while(Decider == 1)
      {

           for(int i = 0; i < row; ++i)
           {
               for(int j = 0; j < column; ++j)
               {
                 counterAlive = 0;
                 if (i == 0 && j == 0)
                 {
                   if(grid2[0][1] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[1][1] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[1][0] == 'X')
                   {
                     counterAlive++;
                   }
                   //Checks bottom right corner
                   if(grid2[row-1][column-1] == 'X')
                   {
                     counterAlive++;
                   }
                   //Checks top right corner.
                   if(grid2[0][column - 1] == 'X')
                   {
                     counterAlive++;
                   }
                   //Checks bottom left corner.
                   if(grid2[row-1][0] == 'X')
                   {
                     counterAlive++;
                   }
                   //Checks bottom right second column.
                   if(grid2[row-1][1] == 'X')
                   {
                     counterAlive++;
                   }
                   //Right side second row.
                   if(grid2[1][column -1 ] == 'X')
                   {
                     counterAlive++;
                   }
                 }



                 else if (i == 0 && j == column - 1)
                 {
                   if(grid2[0][column - 2] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[1][column - 2] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[1][column - 1] == 'X')
                   {
                     counterAlive++;
                   }
                   //Checks bottom left corner
                   if(grid2[row-1][0] == 'X')
                   {
                     counterAlive++;
                   }
                   //Top left corner
                   if(grid2[0][0] == 'X')
                   {
                     counterAlive++;
                   }
                   //Checks left second row
                   if(grid2[1][0] == 'X')
                   {
                     counterAlive++;
                   }
                   //Bottom right corner
                   if(grid2[row-1][column-1] == 'X')
                   {
                     counterAlive++;
                   }
                   //Bottom right corner second to last column
                   if(grid2[row-1][column-2] == 'X')
                   {
                     counterAlive++;
                   }

                 }

                 else if (i == row - 1 && j == 0)
                 {
                   if(grid2[row - 1][1] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[row - 2][0] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[row - 2][1] == 'X')
                   {
                     counterAlive++;
                   }
                   //Top right corner
                   if(grid2[0][column-1] == 'X')
                   {
                     counterAlive++;
                   }
                   //Bottom right corner
                   if(grid2[row-1][column-1] == 'X')
                   {
                     counterAlive++;
                   }
                   //Bottom right second to last row
                   if(grid2[row-2][column-1] == 'X')
                   {
                     counterAlive++;
                   }
                   //Top left corner
                   if(grid2[0][0] == 'X')
                   {
                     counterAlive++;
                   }
                   //Top row second index
                   if(grid2[0][1] == 'X')
                   {
                     counterAlive++;
                   }

                 }


                 else if (i == row - 1 && j == column - 1)
                 {
                   if(grid2[row - 2][column - 1] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[row - 1][column - 2] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[row - 2][column - 2] == 'X')
                   {
                     counterAlive++;
                   }
                   //Top left corner
                   if(grid2[0][0] == 'X')
                   {
                     counterAlive++;
                   }
                   //Top right corner
                   if(grid2[0][column-1] == 'X')
                   {
                     counterAlive++;
                   }
                   //Top right second to last
                   if(grid2[0][column-2] == 'X')
                   {
                     counterAlive++;
                   }
                   //Bottom left corner
                   if(grid2[row-1][0] == 'X')
                   {
                     counterAlive++;
                   }
                   //Second to last row left side.
                   if(grid2[row-2][0] == 'X')
                   {
                     counterAlive++;
                   }

                 }


                 else if (i == 0)
                 {
                   if (grid2[i][j-1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i][j+1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i+1][j+1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i+1][j] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i+1][j-1] == 'X')
                   {
                     counterAlive++;
                   }
                   //bottom row.
                   if(grid2[row-1][j] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[row-1][j+1] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[row-1][j-1] == 'X')
                   {
                     counterAlive++;
                   }


                 }



                 else if (j == 0)
                 {

                   if (grid2[i-1][0] == 'X')
                   {
                     counterAlive++;
                   }

                   if (grid2[i-1][1] == 'X')
                   {
                     counterAlive++;
                   }

                   if (grid2[i][1] == 'X')
                   {
                     counterAlive++;
                   }

                   if (grid2[i+1][1] == 'X')
                   {
                     counterAlive++;
                   }

                   if (grid2[i+1][0] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i-1][column-1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i+1][column-1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i][column-1] == 'X')
                   {
                     counterAlive++;
                   }
                 }



                 else if (i == row - 1)
                 {
                   if (grid2[row-2][j] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[row-1][j+1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[row-1][j-1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[row-2][j+1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[row-2][j-2] == 'X')
                   {
                     counterAlive++;
                   }
                   //Top row
                   if(grid2[0][j] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[0][j+1] == 'X')
                   {
                     counterAlive++;
                   }
                   if(grid2[0][j-1] == 'X')
                   {
                     counterAlive++;
                   }

                 }


                 else if (j == column - 1)
                 {
                   if (grid2[i+1][column-1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i+1][column-2] == 'X')
                   {
                     counterAlive++;
                   }

                   if (grid2[i][column-2] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i-1][column-2] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i-1][column-1] == 'X')
                   {
                     counterAlive++;
                   }

                   //left column
                   if (grid2[i-1][0] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i+1][0] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i][0] == 'X')
                   {
                     counterAlive++;
                   }
                 }



                 else
                 {
                   if (grid2[i+1][j+1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i+1][j-1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i+1][j] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i][j+1] =='X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i][j-1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i-1][j+1] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i-1][j] == 'X')
                   {
                     counterAlive++;
                   }
                   if (grid2[i-1][j-1] == 'X')
                   {
                     counterAlive++;
                   }


                 }

                 if (counterAlive == 0)
                 {
                   grid[i][j] = '-';
                 }
                 else if (counterAlive == 1)
                 {
                   grid[i][j] = '-';
                 }
                 else if (counterAlive == 2)
                 {

                 }
                 else if (counterAlive == 3)
                 {
                   grid[i][j] = 'X';
                 }
                 else
                 {
                   grid[i][j] = '-';
                 }
           }

         }

         cout << endl;
         //checking if equal




       bool isEmpty = true;
       bool isIdentical = true;
       cout << "Press the ENTER key";




         for(int i = 0; i < row; ++i)
         {
           for(int j = 0; j < column; ++j)
           {
             if (grid[i][j] != '-')
             {
               isEmpty = false;

             }
             if(grid2[i][j] != grid[i][j])
             {
               isIdentical = false;
             }
           }
         }

         //if(emptyCount == numberIndex || fullCount == numberIndex)
         if(isEmpty || isIdentical)
         {
           Decider = 0;
         }


         //Decider = 0;

        counterGen++;

      //purely printing out changed grid
         cout << "This is generation: " << counterGen << endl;


      //updating grid2 and printing new grid 2

    //updating grid2 and printing new grid 2

    if (userChoice3 == 1)
    {
      cin.get();
    }
    else if (userChoice3 == 2)
    {
      usleep(microseconds);
    }


       for(int i = 0; i < row; ++i)
       {
         for(int j = 0; j < column; ++j)
         {
           grid2[i][j] = grid[i][j];

         }

       }

       for(int i = 0; i < row; ++i)
       {
         for(int j = 0; j < column; ++j)
         {


         }
         cout << grid2[i] << endl;
       }
       cout << endl;
    }


    }



//Mirror mode.
    else if (userChoice2 == 3)
    {
      cout << "Would you like to click enter to create a new generation or " << endl;
      cout << "do you want a timer.  (1 = enter, 2 = timer) " << endl;
      cin >> userChoice3;
        while(Decider == 1)
        {

             for(int i = 0; i < row; ++i)
             {
                 for(int j = 0; j < column; ++j)
                 {
                   counterAlive = 0;
                   if (i == 0 && j == 0)
                   {
                     if(grid2[0][1] == 'X')
                     {
                       counterAlive+=2;
                     }
                     if(grid2[1][1] == 'X')
                     {
                       counterAlive++;
                     }
                     if(grid2[1][0] == 'X')
                     {
                       counterAlive+=2;
                     }
                     if(grid2[0][0] == 'X'){
                       counterAlive +=3;
                     }
                   }



                   else if (i == 0 && j == (column - 1))
                   {
                     if(grid2[0][column - 2] == 'X')
                     {
                       counterAlive+=2;
                     }
                     if(grid2[1][column - 2] == 'X')
                     {
                       counterAlive++;
                     }
                     if(grid2[1][column - 1] == 'X')
                     {
                       counterAlive+=2;
                     }
                     if(grid2[0][column - 1] == 'X')
                     {
                       counterAlive+=3;
                     }


                   }

                   else if (i == row - 1 && j == 0)
                   {
                     if(grid2[row - 1][1] == 'X')
                     {
                       counterAlive+=2;
                     }
                     if(grid2[row - 2][0] == 'X')
                     {
                       counterAlive+=2;
                     }
                     if(grid2[row - 2][1] == 'X')
                     {
                       counterAlive++;
                     }
                     if(grid2[row - 1][0] == 'X')
                     {
                       counterAlive+=3;
                     }

                   }


                   else if (i == row - 1 && j == column - 1)
                   {
                     if(grid2[row - 2][column - 1] == 'X')
                     {
                       counterAlive+=2;
                     }
                     if(grid2[row - 1][column - 2] == 'X')
                     {
                       counterAlive+=2;
                     }
                     if(grid2[row - 2][column - 2] == 'X')
                     {
                       counterAlive++;
                     }
                     if(grid2[row - 1][column - 1] == 'X')
                     {
                       counterAlive+=3;
                     }

                   }


                   else if (i == 0)
                   {
                     if (grid2[i][j] == 'X')
                     {
                       counterAlive=0;
                     }
                     if (grid2[i][j-1] == 'X')
                     {
                       counterAlive+=2;
                     }
                     if (grid2[i][j+1] == 'X')
                     {
                       counterAlive+=2;
                     }
                     if (grid2[i+1][j+1] == 'X')
                     {
                       counterAlive++;
                     }
                     if (grid2[i+1][j] == 'X')
                     {
                       counterAlive++;
                     }
                     if (grid2[i+1][j-1] == 'X')
                     {
                       counterAlive++;
                     }


                   }

                   else if (j == 0)
                   {
                     if (grid2[i][j] == 'X')
                     {
                       counterAlive++;
                     }

                     if (grid2[i-1][0] == 'X')
                     {
                       counterAlive+=2;
                     }

                     if (grid2[i-1][1] == 'X')
                     {
                       counterAlive++;
                     }

                     if (grid2[i][1] == 'X')
                     {
                       counterAlive++;
                     }

                     if (grid2[i+1][1] == 'X')
                     {
                       counterAlive++;
                     }

                     if (grid2[i+1][0] == 'X')
                     {
                       counterAlive+=2;
                     }
                   }


                   else if (i == row - 1)
                   {
                     if (grid2[row-1][j] == 'X')
                     {
                       counterAlive++;
                     }
                     if (grid2[row-2][j] == 'X')
                     {
                       counterAlive++;
                     }
                     if (grid2[row-1][j+1] == 'X')
                     {
                       counterAlive+=2;
                     }
                     if (grid2[row-1][j-1] == 'X')
                     {
                       counterAlive+=2;
                     }
                     if (grid2[row-2][j+1] == 'X')
                     {
                       counterAlive++;
                     }
                     if (grid2[row-2][j-1] == 'X')
                     {
                       counterAlive++;
                     }

                   }


                   else if (j == column - 1)
                   {
                     if (grid2[i][column-1] == 'X')
                     {
                       counterAlive++;
                     }
                     if (grid2[i+1][column-1] == 'X')
                     {
                       counterAlive+=2;
                     }
                     if (grid2[i+1][column-2] == 'X')
                     {
                       counterAlive++;
                     }

                     if (grid2[i][column-2] == 'X')
                     {
                       counterAlive++;
                     }
                     if (grid2[i-1][column-2] == 'X')
                     {
                       counterAlive++;
                     }
                     if (grid2[i-1][column-1] == 'X')
                     {
                       counterAlive+=2;
                     }
                   }



                   else
                   {
                     if (grid2[i+1][j+1] == 'X')
                     {
                       counterAlive++;
                     }
                     if (grid2[i+1][j-1] == 'X')
                     {
                       counterAlive++;
                     }
                     if (grid2[i+1][j] == 'X')
                     {
                       counterAlive++;
                     }
                     if (grid2[i][j+1] =='X')
                     {
                       counterAlive++;
                     }
                     if (grid2[i][j-1] == 'X')
                     {
                       counterAlive++;
                     }
                     if (grid2[i-1][j+1] == 'X')
                     {
                       counterAlive++;
                     }
                     if (grid2[i-1][j] == 'X')
                     {
                       counterAlive++;
                     }
                     if (grid2[i-1][j-1] == 'X')
                     {
                       counterAlive++;
                     }


                   }

                   if (counterAlive == 0)
                   {
                     grid[i][j] = '-';
                   }
                   else if (counterAlive == 1)
                   {
                     grid[i][j] = '-';
                   }
                   else if (counterAlive == 2)
                   {

                   }
                   else if (counterAlive == 3)
                   {
                     grid[i][j] = 'X';
                   }
                   else
                   {
                     grid[i][j] = '-';
                   }


             }

           }

           cout << endl;
           //checking if equal




         bool isEmpty = true;
         bool isIdentical = true;
         cout << "Press the ENTER key";
         cin.get();



           for(int i = 0; i < row; ++i)
           {
             for(int j = 0; j < column; ++j)
             {
               if (grid[i][j] != '-')
               {
                 isEmpty = false;

               }
               if(grid2[i][j] != grid[i][j])
               {
                 isIdentical = false;
               }
             }
           }

           //if(emptyCount == numberIndex || fullCount == numberIndex)
           if(isEmpty || isIdentical)
           {
             Decider = 0;
           }


           //Decider = 0;
           counterGen++;




        //purely printing out changed grid
           cout << "This is generation: " << counterGen << endl;
           cout << endl;

           if (userChoice3 == 1)
           {
             cin.get();
           }
           else if (userChoice3 == 2)
           {
             usleep(microseconds);
           }


        //updating grid2 and printing new grid 2

      //updating grid2 and printing new grid 2
         for(int i = 0; i < row; ++i)
         {
           for(int j = 0; j < column; ++j)
           {
             grid2[i][j] = grid[i][j];

           }

         }

         for(int i = 0; i < row; ++i)
         {
           for(int j = 0; j < column; ++j)
           {


           }
           cout << grid2[i] << endl;
         }

         cout << endl;






      }
    }
}

//////////////////////









return 0;


}
