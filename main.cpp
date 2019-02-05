//Build a library for singly linked list.
// Replace the airport array in main with a Linked List.
// Sort the array.
//idk why it's kinda weird but just remember that the indexing of the linked list starts at 1

#include <iostream>
#include <fstream>
#include <cmath>
#include "slist.h"

using namespace std;


//CREATE LINKED LIST
node* n;
node* t; // temporary
node* h; // head
node* tp; //for traversing linked list


void simpleSortTotal(Airport* s[], int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main() {


    ifstream infile;
    int i=0;
    char cNum[10] ;
    //Airport* airportArr[13500];			// Replace array with Linked List
    int   airportCount;
    //Airport* a[13500];

    n = new node; // creates first node

    t = n; // assigns temporary node to first node
    h = n; // assigns head node to first node
    tp = n; // tp equals the head node of the linked list


    infile.open("/Users/tanmayarora/Documents/USAirportCodes.csv", ifstream::in);


    if (infile.is_open()) {
        int   c=0;
        while (infile.good())
        {

            if (i != 0) {

                n = new node;
            }


            infile.getline(n->airport, 256, ',');
            infile.getline(cNum, 256, ',');
            n->longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            n->latitude = atof(cNum);

            n->distance = distanceEarth(AUSLATITUDE, AUSLONGITUDE, n->latitude, n->longitude);

            t->next = n; // access the "next" of the first node and makes it point to this node
            t = t->next; // moves t to the new node

            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();

    }
    else {
        cout << "Error opening file";
    }

    node* test;

    test = simpleSortTotal(tp);
    tp = h;

    int counter = 0;

    while (test->next != nullptr) {


        if (test->distance > 0 && test->distance < 100) {
            cout << test->airport << endl;
            cout << test->distance << endl;

        }

        if (counter == (size(tp)-1)) {
            cout << "the farthest airport is " << test->airport << endl;
            cout << "it is " << test->distance << " miles from the central airport " << endl;
        }

        counter++;
        test = test->next;
    }



}

#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
    return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
    return (rad * 180 / pi);
}

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
    double lat1r, lon1r, lat2r, lon2r, u, v;
    lat1r = deg2rad(lat1d);
    lon1r = deg2rad(lon1d);
    lat2r = deg2rad(lat2d);
    lon2r = deg2rad(lon2d);
    u = sin((lat2r - lat1r)/2);
    v = sin((lon2r - lon1r)/2);
    return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

// simpleSortTotal method is written in slist.cpp file