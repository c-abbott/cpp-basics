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

int main() {
    return 0;
}