#include <iostream>
#include "doubleLinkedList.h"
using namespace std;

template <class T>
class queue{
public:
  void enQueue(T data);
  T deQueue();

  DoublyLinkedList<T> mylist;


};
template <class T>
void queue<T>::enQueue(T data){

  mylist.insertBack(data);

}

template <class T>
T queue<T>::deQueue(){

if(!mylist.isEmpty()){
   return mylist.removeFront();
}

else{

  return T();
}


}
