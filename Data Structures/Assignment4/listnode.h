#include <iostream>

using namespace std;
template <class T>
class ListNode
{
	public:
		ListNode(); //Default
		ListNode(T d); //Overloaded
		~ListNode();


		T data;
		ListNode<T> *next;
    ListNode<T> *prev;


};

template <class T>
ListNode<T>::ListNode()
{
	//default constructor
	//you can build character here
}

template <class T>
ListNode<T>::~ListNode()
{


	//build character
	//and get your money's worth.
}

template <class T>
ListNode<T>::ListNode(T d)//overloaded
{
	data = d;
  prev= NULL;
	next = NULL;

}
