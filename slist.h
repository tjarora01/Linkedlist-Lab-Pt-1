/*
Header file for single linked list class library
*/
//idk why it's kinda weird but just remember that the indexing of the linked list starts at 1
#ifndef SLIST_H
#define SLIST_H
#define AUSLONGITUDE 30.1944
#define AUSLATITUDE 97.67

class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;

};

struct node {
    char   airport[5];
    double   longitude;
    double   latitude;
    double distance;
    node* next;
};

using namespace std;

// add(value)				//Adds a new value to the end of this list.
node* add(node* t1, node* value, bool tell, int index); // legit works

// clear()					//Removes all elements from this list.
void clear(node* t1); // legit works

// equals(list)				//Returns true if the two lists contain the same elements in the same order.
bool equals(node* t1, node* t2); // legit works

//get(index)				//Returns the element at the specified index in this list.
node* get(node* t1, int index); // legit works

//insert(index, value)		//Inserts the element into this list before the specified index.
node* insert(node* t1, node* value, int index, bool tell, int setIndex); // legit works

//exchg(index1, index2)		//Switches the payload data of specified indexex.
void exchg(node* tp, int index1, int index2); // legit works

//swap(index1,index2)		//Swaps node located at index1 with node at index2
node* swap(node* tp, int index1, int index2); //legit works

// isEmpty()				//Returns true if this list contains no elements.
bool isEmpty(node* t1); //legit works

// remove(index)			//Removes the element at the specified index from this list.
node* remove (node* t1, int index); // legit works

// set(index, value)		//Replaces the element at the specified index in this list with a new value.
node* set(node* t1, node* set, int index, bool tell, int setIndex); // legit works

// size()					//Returns the number of elements in this list.
int size(node* t1); // legit works

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
node* subList(node* t1, int start, int length); // legit works

// toString()				//Converts the list to a printable string representation.
void toString(node* tp); // legit works

//Provide sort routine on linked list
node* simpleSortTotal (node* tp); // legit works

//swaps two character arrays
void swapper(char str1[5], char str2[5]); // legit works

#endif // #ifndef SLIST_H, #define SLIST_H