/*
Karl Hickel
ID: 2278978
hicke111@mail.chapman.edu
CPSC-350-01
Assignment 6
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//Different sort types.
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
void bubbleSort(double arr[], int size);
void quickSort(double arr[], int left, int right);
void insertionSort(double arr[], int size);
void shellSort(double arr[], int size);
void quickSort(double * arr2, int low, int high);
void swap(double* a, double* b);
int partition(double arr[], int low, int high);
void quickSort(double arr[], int low, int high);




//int main(int argc , char** argv)

//Main Program
//Enter file name with ./a.out "".
int main(int argc , char** argv){
//Declaring dynamic arrays for sorting method.
double *array1;
double *array2;
double *array3;
double *array4;
int arraySize;
ifstream file;
string lines = " ";
int lineCounter = 0;
string fileName;
fileName = argv[1];
file.open(fileName);
//Reads the first line of the file and takes it as the size of the array.
while(getline(file, lines)){
  if(lineCounter==0){
    arraySize = atof(lines.c_str());

  }

  lineCounter++;

}
//closes the file
file.close();
file.open("numbers.txt");
lineCounter = 0;
int counter=0;


array1 = new double[arraySize];
array2 = new double[arraySize];
array3 = new double[arraySize];
array4 = new double[arraySize];
//Goes through the file and stores the values in each respective array.
for(int i; i <= arraySize; ++i){
  getline(file,lines);
  if(lineCounter != 0){
    array1[counter] = atof(lines.c_str());
    array2[counter] = atof(lines.c_str());
    array3[counter] = atof(lines.c_str());
    array4[counter] = atof(lines.c_str());
    counter++;

  }

  lineCounter++;
}



cout << endl;
cout << "----------Time in milliseconds-------------" << endl;
cout << endl;
//Bubble Sort
//Clock start and finish are intended to find the time of the program. The difference
//would indicate the time it took to complete the sorting function.
int start= clock();
bubbleSort(array1,arraySize);
int finish= clock();
double bubbleTime = double(finish - start ) / CLOCKS_PER_SEC * 1000000;
cout <<"Bubble Sort Time: " << bubbleTime << endl;


//Insertion Sort
int start1 = clock();
insertionSort(array2,arraySize);
int finish1 = clock();
double insertTime = double(finish1 - start1) / CLOCKS_PER_SEC * 1000000;
cout << "Insertion Sort Time: " << insertTime << endl;


//shellSort
int start2 = clock();
shellSort(array3,arraySize);
int finish2 = clock();
double shellSortTime = (finish2 - start2) / CLOCKS_PER_SEC * 1000000;
cout << "Shell sort: " << shellSortTime << endl;

//QuickSort
int start3 = clock();
quickSort(array4, 0 , arraySize -1);
int finish3 = clock();
double quickSortTime = (finish3 - start3) / CLOCKS_PER_SEC * 1000000;
cout << "Quck Sort time: " << quickSortTime << endl;

}

//Takes input of the array and
void bubbleSort(double arr[] , int size){
  for(int i = 0; i < size; ++i){
    double temp = 0;
    for(int j = 0; j < size - 1; ++j){
    if(arr[j]>arr[j+1])
    {
      temp = arr[j+1];
      arr[j+1] = arr[j];
      arr[j] = temp;
    }
    }
  }
}

//Used Rena's code from inclass but couldnt run, fixed with an online resource
//https://www.geeksforgeeks.org/insertion-sort/
void insertionSort(double arr[], int size){
for(int j = 1; j < size; ++j) {

    double temp = arr[j];

    int k = j;
    while(k > 0 && arr[k-1] >= temp) {
      arr[k] = arr[k-1];
      --k;
    }
    arr[k] = temp;
  }
}
//Kind of a weird
//https://www.sanfoundry.com/c-program-implement-shell-sort/
void shellSort(double arr[], int size)
{
  int i, j, k, tmp;
  for (i = size / 2; i > 0; i = i / 2)
  {
    for (j = i; j < size; j++)
      {
        for(k = j - i; k >= 0; k = k - i)
        {
        if (arr[k+i] >= arr[k])
        break;
    else
        {
          tmp = arr[k];
          arr[k] = arr[k+i];
          arr[k+i] = tmp;
        }
      }
    }
  }
}

//This swaps the data.
void swap(double* pointer1, double* pointer2)
{
    double t = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = t;
}
//You need partition in order to correctly position the indexes in
//order to do quick sort.
int partition(double arr[], int left, int right)
{
    int pivot = arr[right];
    int i = (left - 1);

    for (int j = left; j <= right- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return (i + 1);
}
//Had to get this one online and reconstruct it. Could not figure out the partition bit.
//https://www.geeksforgeeks.org/cpp-program-for-quicksort/
void quickSort(double arr[], int left, int right)
{
    if (left < right)
    {

        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}
