//idk why it's kinda weird but just remember that the indexing of the linked list starts at 1
#include "slist.h"
#include <iostream>

using namespace std;



/*
Class Library File
*/


// Constructor

// Destructor

// add(value)				//Adds a new value to the end of this list.

node* add(node* t1, node* value, bool tell, int index) {

    node* head;
    node* tail;
    head = t1;

    node* beforeIndex;
    node* afterIndex;

    int capacity;
    capacity = size(t1);

    node* lastElement;
    lastElement = get(t1, capacity);

    if (tell) {

        node* capacity2;
        capacity2 = get(t1, capacity);


        beforeIndex = get(t1, (index-1));

        if (index != capacity) {
            afterIndex = get(t1, (index+1));
        }
        else {
            afterIndex = get(t1, index);
        }

        beforeIndex->next = afterIndex;
    }


    lastElement->next = value;
    value->next = tail;
    tail->next = nullptr;


    return head;

}


// clear()					//Removes all elements from this list.
void clear(node* t1) {

    node* following;

    while (t1->next != nullptr) {
        following = t1->next;
        free(t1);
        t1 = following;
    }

}

// equals(list)				//Returns true if the two lists contain the same elements in the same order.
bool equals(node* t1, node* t2) {

    bool flag = true;

    while (t1->next != nullptr && t2->next != nullptr) {

        if (t1->airport != t2->airport || t1->latitude != t2->latitude || t1->longitude != t2->longitude) {
            flag = false;
            break;
        }

        t1 = t1->next;
        t2 = t2->next;

    }

    return flag;
}

//get(index)				//Returns the element at the specified index in this list.

node* get(node* t1, int index) {

    int counter = 1;
    node* get;

    while (t1-> next != nullptr) {

        if(counter == index) {
            get = t1;
            break;
        }

        counter++;
        t1 = t1->next;
    }


    return get;


}

//insert(index, value)		//Inserts the element into this list before the specified index.
node* insert(node* t1, node* value, int index, bool tell, int setIndex) {

    node* head;
    head = t1;

    node* indexNode;
    node* beforeIndex;

    beforeIndex = get(t1, (index-1));
    indexNode = get(t1, index);

    //assuming that set comes from linked list t1
    //stitch together beforeSet and After Set
    if (tell) {
        node* beforeSet;
        node* afterSet;

        beforeSet = get(t1, (setIndex-1));
        //cout << beforeSet->airport << endl;
        afterSet = get(t1, (setIndex+1));
        //cout << afterSet->airport << endl;

        beforeSet->next = afterSet;

    }


    beforeIndex->next = value;
    value->next = indexNode;


    return head;


}

void exchg(node* tp, int index1, int index2) {

    node* head;
    head = tp;

    string   airport1;
    double   longitude1;
    double   latitude1;
    double distance1;

    string   airport2;
    double   longitude2;
    double   latitude2;
    double distance2;

    airport1 = get(tp, index1)->airport;
    longitude1 = get(tp, index1)->longitude;
    latitude1 = get(tp, index1)->latitude;
    distance1 = get(tp, index1)->distance;

    airport2 = get(tp, index2)->airport;
    longitude2 = get(tp, index2)->longitude;
    latitude2 = get(tp, index2)->latitude;
    distance2 = get(tp, index2)->distance;

    strcpy(get(tp, index1)->airport, airport2.c_str());
    get(tp, index1)->longitude = longitude2;
    get(tp, index1)->latitude = latitude2;
    get(tp, index1)->distance = distance2;

    strcpy(get(tp, index2)->airport, airport1.c_str());
    get(tp, index2)->longitude = longitude1;
    get(tp, index2)->latitude = latitude1;
    get(tp, index2)->distance = distance1;


    while (head->next != nullptr) {
        cout << head->airport << endl;
        head = head->next;
    }

}


//swap(index1,index2)		//Swaps node located at index1 with node at index2

node* swap(node* tp, int index1, int index2) {

    node* head = tp;

    node* beforeFirst;
    node* first;
    node* afterFirst;

    node* beforeSecond;
    node* second;
    node* afterSecond;


    int index1Counter = 0;
    int index2Counter = 0;

    beforeFirst = get(tp, (index1-1));
    first = get(tp, index1);
    afterFirst = get(tp, (index1+1));

    beforeSecond = get(tp, (index2-1));
    second = get(tp, index2);
    afterSecond = get(tp, (index2+1));

    //gets the node before first to point to second and gets second to point to the node after first
    beforeFirst->next = second;
    second->next = afterFirst;

    //gets the node before second to point to first and gets first to point to the node after second
    beforeSecond->next = first;
    first->next = afterSecond;

    return head;
}



// isEmpty()				//Returns true if this list contains no elements.
bool isEmpty(node* t1) {

    bool check = false;

    if (size(t1) == 0) {
        check = true;
    }

    return check;
}

// remove(index)			//Removes the element at the specified index from this list.
node* remove (node* t1, int index) {

    node* head;
    head = t1;

    node* beforeIndex;
    node* afterIndex;

    beforeIndex = get(t1, (index-1));
    afterIndex = get(t1, (index+1));

    beforeIndex->next = afterIndex;

    return head;
}

// set(index, value)		//Replaces the element at the specified index in this list with a new value.

node* set(node* t1, node* set, int index, bool tell, int setIndex) {

    node* head;
    head = t1;

    node* beforeIndex;
    node* afterIndex;

    beforeIndex = get(t1, (index-1));
    afterIndex = get(t1, (index+1));

    //assuming that set comes from linked list t1
    //stitch together beforeSet and After Set
    if (tell) {
        node* beforeSet;
        node* afterSet;

        beforeSet = get(t1, (setIndex-1));
        afterSet = get(t1, (setIndex+1));

        beforeSet->next = afterSet;

    }


    //make before index point towards set and set point towards after index
    beforeIndex->next = set;
    set->next = afterIndex;

    int counter = 1;

    return head;
}

// size()					//Returns the number of elements in this list.
int size(node* t1) {

    int counter = 0;

    while (t1->next != nullptr) {
        counter++;
        t1 = t1->next;
    }

    return counter;
}

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

node* subList(node* t1, int start, int length) {

    node* begin;
    node* end;
    node* tail = new node;

    begin = get(t1, start);
    end = get(t1, length);

    end->next = tail;
    tail->next = nullptr;

    return begin;
}

// toString()				//Converts the list to a printable string representation.
void toString(node* tp) {

    while (tp->next != nullptr) {

        cout << "The airport is " << tp->airport << " degrees." <<  " Its longitude is: " << tp->longitude << " degrees." << " Its latitude is " << tp->latitude << " degrees." <<  " Its distance from the central airport is " << tp->distance << " miles. " << endl;

        tp = tp->next;
    }
}

node* simpleSortTotal (node* tp) {

    node* head;
    head = tp;

    node* i;
    node* j;

    j = head;
    i = head->next;


    for (i = head; i != nullptr; i = i->next) {

        for (j = i->next; j != nullptr; j = j->next) {
            
            if (i->distance > j->distance) {

                //swap i->airport and j->airport
                swapper(i->airport, j->airport);

                //swap i->longitude and j->longitude
                double temp2 = i->longitude;
                i->longitude = j->longitude;
                j->longitude = temp2;


                //swap i->latitude and j->latitude
                double temp3 = i->latitude;
                i->latitude = j->latitude;
                j->latitude = temp3;


                // swap i->distance and j->distance
                double temp4 = i->distance;
                i->distance = j->distance;
                j->distance = temp4;
            }
        }
    }

    return head;
}

//swaps two character arrays
void swapper( char str1[5], char str2[5])
{
    int j = 0;
    char temp[5];

    for(j = 0; j < 5; j++)
    {
        temp[j] = str1[j];
        str1[j] = str2[j];
        str2[j] = temp[j];
    }

}