#include <iostream>
//#include "doubleLinkedList.h"
#include "queue.h"

using namespace std;

int main(){
queue<int> q;

q.enQueue(5);
q.enQueue(3);
q.enQueue(2);
q.enQueue(3);
q.enQueue(5);

cout << q.deQueue() << endl;
cout << q.deQueue() << endl;
cout << q.deQueue() << endl;
cout << q.deQueue() << endl;
cout << q.deQueue() << endl;
cout << q.deQueue() << endl;




/*
DoublyLinkedList<int> d;

d.insertBack(5);
d.insertBack(1);
d.insertBack(2);
d.insertBack(3);
d.insertBack(4);
d.insertBack(5);
d.insertBack(2);

cout << d.removeFront() << endl;
cout << d.removeFront() << endl;
cout << d.removeFront() << endl;
cout << d.removeFront() << endl;
cout << d.removeFront() << endl;
cout << d.removeFront() << endl;
cout << d.removeFront() << endl;
cout << d.removeFront() << endl;


*/

  return 0;
}
