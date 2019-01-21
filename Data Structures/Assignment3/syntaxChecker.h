#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//Creates template class
template <class T>
class GenStack
{
public:
  GenStack();
  GenStack(int maxSize);
  ~GenStack();

  void push(T d);
  T pop();
  T peek();
  bool isEmpty();
  bool isFull();
  int getSize();
  void increaseMemory();


  T *myArray;
  int top;
  int size;






};
template <class T>
GenStack<T>::GenStack() //default constructor
{


}
//max size of the stack
template <class T>
GenStack<T>::GenStack(int maxSize) //overloaded constructor
{
  myArray = new T [maxSize];
  size = maxSize;
  top = -1;

}
//delete stack once done.
template <class T>
GenStack<T>::~GenStack()
{

  delete myArray;
  cout<< "Stack has been deleted" << endl;
}

template <class T>
void GenStack<T>::push(T d)
{
  //If the current stack is full, a new stack is created that is double the size of the original
  if(isFull())
  {
    increaseMemory();
    myArray[++top] = d;
  }
  //If its not, it simply adds another element.
  else
  {
  myArray[++top] = d;
  }
}
//If stack is empty, it will return that the stack is empty.
template <class T>
T GenStack<T>::pop()
{
  if(isEmpty())
  {
    T dummy = 'T';
    cout << "ITS EMPTY." << endl;
    return dummy;
  }
  else
  {
  return myArray[top--];
  }

}
//Checks the top element in a stack, or rather the last element inputed.
template <class T>
T GenStack<T>::peek()
{

  return myArray[top];
}
//Checks to see if the stack is full.
template <class T>
bool GenStack<T>::isFull()
{

  return (top == size -1);
}
//Checks to see if stack is empty.
template <class T>
bool GenStack<T>::isEmpty()
{

  return (top == -1);
}
//Increases the size of the stack if the stack is full. 
template <class T>
void GenStack<T>::increaseMemory()
{

  T *tempArray = new T [size*2];

  for (int i = 0; i <= size; ++i)
  {
    tempArray[i] = myArray[i];
  }
  myArray = tempArray;
  size = size *2;
}
