// File:LinkedList.cpp
// تطبيق الليست المربوطة


#include <iostream>
#include"LinkedList.h"
using namespace std;
using std::string;


// الدوال الخاصة بالكلاس
// الكونستركتور بتاع الكلاس
LinkedList::LinkedList()
{
	head = NULL; cursor = NULL;  prev = NULL;
}

// الديستركتور
LinkedList::~LinkedList()
{
	clearList();
}

// بترجع true لو الليست فاضية
bool LinkedList::isEmpty() const
{
	return (head == NULL);
}

// بترجع true لو المؤشر الحالي فاضي
bool LinkedList::currentIsEmpty() const
{
	return (cursor == NULL);
}

// بتخلي العقدة الحالية تكون اول عقدة
// لو الليست فاضية المؤشر هيفضل فاضي
void LinkedList::moveToFirst()
{
	cursor = head;  prev = NULL;
}

// بترجع true لو المؤشر على اول عقدة
// او لو الليست والمؤشر الاتنين فاضيين
bool LinkedList::isAtFirst() const
{
	return (cursor == head);
}

// بتتقدم للعقدة اللي بعدها
// بفترض ان المؤشر مش فاضي في الاول
void LinkedList::moveNext()
{
	prev = cursor;
	cursor = cursor->next;
}

// بتخلي المؤشر يروح لآخر عقدة
// لو الليست فاضية المؤشر هيفضل فاضي
void LinkedList::moveToLast()
{
	moveToFirst();
	if (! isEmpty())
		while ( cursor->next != NULL) moveNext();
}

// بترجع true لو المؤشر على آخر عقدة
// او لو الليست فاضية
bool LinkedList::isAtLast() const
{
	if ( isEmpty()) return true;
		else if (currentIsEmpty()) return false;
			else return (cursor->next == NULL);
}

// بترجع حجم الليست
int LinkedList::getSize() const
{
	NodePointer q;
	int count;
	q = head;	count = 0;
	while (q != NULL)
	{
		count++; 	q = q->next;
	}
	return count;
}

// بتحدث البيانات في العقدة الحالية
// بفترض ان المؤشر مش فاضي
void LinkedList::updateCurrentData(const char &d)
{
	cursor->data = d;
}

// بترجع البيانات من العقدة الحالية
// بفترض ان المؤشر مش فاضي
void LinkedList::getCurrentData(char &d, int &k) const
{
	d = cursor->data;
	k = cursor ->key;
}

void LinkedList::getCurrentKey(int &k) const
{
	k = cursor->key;
}

// بتضيف عقدة جديدة في اول الليست
// العقدة الجديدة بتبقى هي الحالية
void LinkedList::addFirst(const int &k, const char &d )
{
	NodePointer pnew;
	pnew = new node;
	pnew->key = k; pnew->data = d;
	pnew->next = head;
	head = pnew;
	cursor = head;
	prev = NULL;
}



// بتضيف عقدة جديدة بعد العقدة الحالية
// من غير ما تغير مكان المؤشر
// بفترض ان المؤشر مش فاضي والليست مش فاضية
void LinkedList::addAfter(const int &k, const char &d )
{
	NodePointer pnew;
	pnew = new node;
	pnew->key = k; pnew->data = d;
	pnew->next = cursor->next;
 	cursor->next = pnew;
 	prev = cursor;
 	cursor = pnew;
}


// بتضيف عقدة جديدة قبل العقدة الحالية
// المؤشر بتاعي بيبقى على العقدة الجديدة
void LinkedList::addBefore(const int &k, const char &d )
{
	NodePointer pnew;
	pnew = new node;
	pnew->key = k; pnew->data = d;
	pnew->next = cursor;
    prev->next = pnew;
	cursor = pnew;
}

// بتضيف عقدة جديدة في آخر الليست
// المؤشر بتاعي بيبقى على العقدة الجديدة
void LinkedList::addLast(const int &k, const char &d )
{
	if (isEmpty()) addFirst(k,d);
	else {moveToLast(); addAfter(k,d); }
}




// بتمسح العقدة الحالية والمؤشر بيروح للعقدة اللي بعدها
// لو العقدة الحالية كانت آخر عقدة المؤشر هيبقى فاضي
// بفترض ان المؤشر مش فاضي في الاول
void LinkedList::removeCurrent()
{
	NodePointer q;
   	if(! currentIsEmpty())
	{
		if (isAtFirst())
   		{	q = cursor;
			cursor = cursor->next;
			head = cursor;
      		delete q;
		}

		else
   		{	q = cursor;
			cursor = cursor->next;
			prev->next = cursor;
			delete q;
		}
   }
}

// بتمسح اول عقدة والمؤشر بيروح للعقدة اللي بعدها
// لو كانت العقدة الوحيدة المؤشر هيبقى فاضي
// بفترض ان المؤشر مش فاضي في الاول
void LinkedList::removeFirst()
{
	if(! isEmpty()) {moveToFirst(); removeCurrent();}
}

// بتمسح آخر عقدة والمؤشر بيبقى فاضي
// بفترض ان المؤشر مش فاضي في الاول
void LinkedList::removeLast()
{
	if(! isEmpty()) {moveToLast(); removeCurrent();}
}

// بتمسح الليست كلها
void LinkedList::clearList()
{
     moveToFirst();
     while (! isEmpty())
        removeCurrent();
}

// بتدور على عقدة بالمفتاح المطلوب
// لو لقيتها المؤشر بيروحلها وبترجع true
// لو ملقتهاش بترجع false والمؤشر بيبقى فاضي
bool LinkedList::findNode(const int &k)
{
	bool found = false;
  	moveToFirst();
	while ((! found) && (cursor != NULL))
		if (k == cursor->key)  found = true;
			else moveNext();
	return found;
}

// بتضيف عقدة جديدة في مكان مناسب
// بحيث تحافظ على الترتيب التصاعدي للمفاتيح
void LinkedList::insertSorted(const char &d, const int &k)
{
	moveToFirst();
	while ((cursor != NULL) && (k > cursor->key))
		moveNext();
	if (prev == NULL)  addFirst(k,d);
		else addBefore(k,d);
}

// بتطبع كل العقد اللي في الليست
void LinkedList::display()
{
	moveToFirst();
	while (! currentIsEmpty())
	{
		cout << cursor->data << " - "<<cursor->key << endl;
		moveNext();
	}
}
