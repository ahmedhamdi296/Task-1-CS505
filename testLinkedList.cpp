// File:testLinkedList.cpp
// برنامج تطبيقي على الليست المربوطة

#include <iostream>
#include <string>
#include "LinkedList.h"
#include"stdio.h"
using namespace std;
using std::string;

int main()
{
	LinkedList myList;
	myList.addFirst(1,'A');
	myList.addAfter(2,'B');
	myList.addAfter(3,'C');
	myList.addAfter(4,'D');
	myList.display();
	return 0;
}
