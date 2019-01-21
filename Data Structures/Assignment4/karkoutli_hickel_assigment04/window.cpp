#include <iostream>
#include "window.h"

using namespace std;
//Window wait time and longest time. 
Window::Window(){
  idleTime=0;
  longestTime=0;



}


Window::~Window(){


}

bool Window::isIdle(){
  return student.timeNeededWindow==0;
}
