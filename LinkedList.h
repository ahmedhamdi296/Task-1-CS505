// File:LinkedList.h
// تعريف كلاس الليست المربوطة

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// تعريف الكلاس

class LinkedList
{
	public:

	// الدوال الخاصة بالكلاس
	// بتعمل ليست فاضية
	LinkedList();
	// بتدمر الليست
	~LinkedList();

	// تعريفات الدوال

	bool isEmpty() const;
	bool currentIsEmpty() const;
	void moveToFirst();
	bool isAtFirst() const;
	void moveNext();
	void moveToLast();
	bool isAtLast() const;
	int  getSize() const;
	void updateCurrentData(const char & );
	void getCurrentData(char &, int &) const;
	void getCurrentKey(int &) const;
	void addFirst(const int &, const char & );
	void addAfter(const int &, const char & );
	void addBefore(const int &, const char& );
	void addLast(const int &, const char & );
	void removeCurrent();
	void removeFirst();
	void removeLast();
	void clearList();
	bool findNode(const int & );
	void insertSorted(const char &, const int & );
	void display();

private:
	// الكلاس 
	   class node
	   {
		public:
			int key;
			char data;
			node *next;
		};

	   typedef node * NodePointer;

	NodePointer head, cursor, prev;
	

};
#endif // LINKEDLIST_H
