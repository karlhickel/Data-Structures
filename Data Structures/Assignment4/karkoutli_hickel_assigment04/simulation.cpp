#include <iostream>
#include "simulation.h"
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include <algorithm>
using namespace std;

Simulation::Simulation(){

  time1=0;


}

Simulation::~Simulation(){}

void Simulation::fileReader(string fileName){
      ifstream file;
      string line = " ";
      int lineCounter=0;
      int totalLine=1;
      int numOfStudents=0;
      int numofStudentsCounter=0;
      int arrivalTime=0;
      int timeNeededWindow=0;


      numOfWindows=0;


      file.open(fileName);
//We read line by line to store the each value in each respective variable.
      while(getline(file, line)){
      if(totalLine==1){
        numOfWindows= atoi(line.c_str());
        cout << numOfWindows << endl;

      }
      else if(totalLine==2){
        arrivalTime= atoi(line.c_str());
          cout << arrivalTime << endl;
      }
      else if(totalLine==3){
        numOfStudents =  atoi(line.c_str()); //2
          cout << numOfStudents << endl;
      }
      else if(numofStudentsCounter < numOfStudents){
        timeNeededWindow= atoi(line.c_str());
        cout << timeNeededWindow << endl;
        Student student(arrivalTime, timeNeededWindow);
        studentQueue.enQueue(student);
        numofStudentsCounter++;
        studentCounter++;
      }
      else{
        //if our counter reaches line 4 we reset it back to line 2 so that it
        // Loops through the corresponding lines and stores the values into a new object.

        arrivalTime=atoi(line.c_str());
        cout << arrivalTime << endl;
        numOfStudents=0;
        numofStudentsCounter=0;

        totalLine=2;

      }

      totalLine++;

    }
    //create array of windows
      windowArray = new Window[numOfWindows];
      for( int i = 0; i < numOfWindows; ++i){
        Window window;
        windowArray[i]= window;

      }


}
//This is where we run our full program.
void Simulation::runProgram(){

cout << endl;
//Our array to store student values.
Student studentStatsArray[studentCounter];


  while(true){
    time1++;
    timeNeededDecrement(); // goes before adding student to window


  for (int i = 0; i < numOfWindows; ++i) {
//Checks to see if student is done at window
    if (windowArray[i].student.timeNeededWindow == 0) {
//Checks to see that they have the correct arrival time above zero
      if (windowArray[i].student.arrivalTime > 0) {
//Error checking.
        if (studentStatsArray[i].arrivalTime == 0) { //if student array is empty
          studentStatsArray[i] = windowArray[i].student;
          windowArray[i].student.arrivalTime = 0;
          windowArray[i].student.waitTimeQueue = 0;


        }

        else {
          for (int j = 0; j < studentCounter; ++j) {
            if (studentStatsArray[j].arrivalTime == 0) {

              studentStatsArray[j] = windowArray[i].student;
              windowArray[i].student.arrivalTime = 0;
              windowArray[i].student.waitTimeQueue = 0;

            }
          }

        }
      }
    }
  }



      while (studentQueue.peek().arrivalTime == time1) {

        int a = emptyIndex();
//We decided it was easier to simply call the method in a variable than to repeat it over and over.
        if (a != -1) { //if it is not full
          windowArray[emptyIndex()].student = studentQueue.deQueue();

          if(!studentQueue.isEmpty1())
          {
            if(studentQueue.peek().arrivalTime < time1)
              waitInQueueCounter(time1);
          }
        }
        else { //if windows are all full

          waitInQueueCounter(time1);
        }
      }



    idleWindowCounter();

//If both the queue and the array is empty, break.
    if(studentQueue.isEmpty1()==1 && arrayCheck())
      break;




  }

//printing array of students with arrival times and wait imes
  for(int i = 0; i < studentCounter; ++i){

    cout<< " student arrivalTime " << studentStatsArray[i].arrivalTime <<  " wait time: " << studentStatsArray[i].waitTimeQueue<< endl;
    }
cout << endl;

//printing the windows
  for (int i =0; i< numOfWindows; ++i){

    cout << "idle time "<< windowArray[i].idleTime <<  " student time needed " << windowArray[i].student.timeNeededWindow
    << " student wait time " << windowArray[i].student.waitTimeQueue << " arrival time of student in window: "<< windowArray[i].student.arrivalTime <<   endl;
  }

  cout << endl;



//Stats variables.
  int waitTimeCounter=0;
  int waitTimeArray[studentCounter];
  int meanSumStudent = 0;
  int countStudents = 0;
  int meanCalculateStudent = 0;
  int greaterThan10Wait= 0;
  int windowIdleArray[numOfWindows];
  int greaterThan5Idle=0;
  int meanIdle=0;
  int meanSumIdle=0;

  for(int i = 0; i < studentCounter; ++i){
//Adding the wait time to the queue.
      waitTimeArray[i] = studentStatsArray[i].waitTimeQueue;
      meanSumStudent += studentStatsArray[i].waitTimeQueue;
      countStudents++;
// Counts the number of students with a wait time greater than 10.
    if(studentStatsArray[i].waitTimeQueue > 10){
      greaterThan10Wait++;
    }
  }
// Prints the wait times.
  for(int i = 0; i < studentCounter; ++i){
      cout << waitTimeArray[i] << endl;
    }


    //sort student stat array and find the median
    int n = sizeof(waitTimeArray) / sizeof(waitTimeArray[0]);
    sort(waitTimeArray, waitTimeArray + n);
    if(n % 2 != 0){
      cout << "Median Student Wait Time: " << waitTimeArray[n/2] << endl; ;
    }
    else{
      cout << "Median Student Wait Time: " << (waitTimeArray[(n-1)/2] + waitTimeArray[n/2]) / 2 << endl;
    }

    cout << "Longest Student Wait Time: "  << waitTimeArray[studentCounter-1] << endl;

    meanCalculateStudent = meanSumStudent / countStudents;
    cout << "Mean Student Wait time: " << meanCalculateStudent << endl;
    cout << "Students waiting over 10 minutes: " << greaterThan10Wait<< endl;

    cout << endl;

  for (int i = 0; i < numOfWindows; ++i){

      windowIdleArray[i]= windowArray[i].idleTime ;
      cout << windowIdleArray[i] << endl;
      meanSumIdle+= windowArray[i].idleTime;

      if(windowArray[i].idleTime > 5){
        greaterThan5Idle++;
      }
  }

  meanIdle= meanSumIdle / numOfWindows;

  int k = sizeof(windowIdleArray) / sizeof(windowIdleArray[0]);
  sort(windowIdleArray, windowIdleArray + k);

  cout << "Mean Window Idle Time: " << meanIdle << endl;
  cout << "Longest Window Idle Time: " << windowIdleArray[numOfWindows-1] << endl;
  cout << "Number of Windows Idle for over 5 mins " << greaterThan5Idle << endl;




}
//Checks if array is empty.
bool Simulation::arrayCheck()
{
  for(int i = 0;i<numOfWindows;i++)
  {
    if(windowArray[i].isIdle() == 0)
      return 0;

  }
  return 1;
}

//Checks if window is empty.
int Simulation::emptyIndex()
{
  for(int i = 0; i < numOfWindows; ++i)
  {
    if (windowArray[i].isIdle()){

      return i;
    }

  }
  return -1;
}
//Counts how long a window is empty.
void Simulation::idleWindowCounter(){

  for(int i = 0; i < numOfWindows; ++i)
  {
    if (windowArray[i].isIdle()){

      windowArray[i].idleTime+=1;
    }

  }
}
//Counts how long a student was in the queue.
void Simulation::waitInQueueCounter(int time1)
{


  Student *std = studentQueue.front();
  int diff = time1 +1;
  int original = std->arrivalTime;

if(std->arrivalTime < time1){
    int temp= time1 - std->arrivalTime;
    std->waitTimeQueue+=temp+1;
    std->arrivalTime+=temp+1;


  }
  else{
    int temp = (time1- original) + original+ 1;
    std->waitTimeQueue+=1;
    std->arrivalTime=temp;
  }


}


//Decrements student time in a window. 
void Simulation::timeNeededDecrement(){

  for(int i = 0; i < numOfWindows; ++i)
  {
    if (!windowArray[i].isIdle()){

      windowArray[i].student.timeNeededWindow -= 1;

    }}
}
