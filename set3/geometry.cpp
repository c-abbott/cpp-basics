#include <iostream>
#include "geometry.h"

PointArray::PointArray() {
    size = 0; // Set size to zero.
    points = new Point[0]; // Create array of size zero in heap.
    // Must implement a destructor now.
}
/* Function to take in an array of points and the size and initilises
   an array of points with the specified size, copying the values
   in the input array */
PointArray::PointArray(const Point copyPoints[], const int copySize) {
    size = copySize;
    points = new Point[copySize];
    for (int i = 0; i < copySize; ++i) {
        points[i] = copyPoints[i];
    }
}
// Copy constructor.
PointArray::PointArray(const PointArray &o) {
    // Any code in PointArray class has access to
    // private variables like size and points.
    size = o.size;
    points = new Point[size];
    for (int i = 0; i < size; i++) {
        points[i] = o.points[i];
    }
}
// Destructor.
PointArray::~PointArray() {
    delete[] points;
}

void PointArray::resize(int newSize) {
    Point *newPts = new Point[newSize];
    for (int i = 0; i < std::min(size, newSize); ++i) {
        newPts[i] = points[i];
    }
    delete[] points;
    size = newSize;
    points = newPts;
}
// Clearing array.
void PointArray::clear(){
    resize(0);
}
// Adding point object at end of array.
void PointArray::pushBack(const Point &p) {
    resize(size + 1);
    points[size - 1] = p;
    // Or 
    // insert(size-1);
    
}
// Inserting point at desired position.
void PointArray::insert(const int pos, const Point &p) {
    resize(size + 1);
    for (int i = size - 1; i > pos; i++) {
        points[i] = points[i-1];
    }
    points[pos] = p;
}

void PointArray::remove(const int pos) {
    if (pos >= 0 && pos < size) {
        // Shifting everything left.
        for (int i = pos; i < size - 2; i++) {
            points[i] = points[i+1];
        }
        resize(size - 1);
    }
}

// Pointer arithmetic.
Point *PointArray::get(const int pos) {
    return pos >= 0 && pos < size ? points + pos : NULL;
}

const Point *PointArray::get(const int pos) const { 
    return pos >= 0 && pos < size ? points + pos : NULL;
}