#include <iostream>
#include <cmath>
#include "geometry.h"

PointArray::PointArray()
{
    size = 0;              // Set size to zero.
    points = new Point[0]; // Create array of size zero in heap.
    // Must implement a destructor now.
}
// Making PointArray object from a literal array of points.
PointArray::PointArray(const Point copyPoints[], const int copySize)
{
    size = copySize;
    points = new Point[copySize]; // Initialise in heap
    for (int i = 0; i < copySize; ++i)
    {
        points[i] = copyPoints[i];
    }
}
// Copy constructor.
PointArray::PointArray(const PointArray &o)
{
    // Any code in PointArray class has access to
    // private variables like size and points.
    size = o.size;
    points = new Point[size];
    for (int i = 0; i < size; i++)
    {
        points[i] = o.points[i];
    }
}
// Destructor.
PointArray::~PointArray()
{
    delete[] points;
}

void PointArray::resize(int newSize)
{
    Point *newPts = new Point[newSize];
    for (int i = 0; i < std::min(size, newSize); ++i)
    {
        newPts[i] = points[i];
    }
    delete[] points;
    size = newSize;
    points = newPts;
}
// Clearing array.
void PointArray::clear()
{
    resize(0);
}
// Adding point object at end of array.
void PointArray::pushBack(const Point &p)
{
    resize(size + 1);
    points[size - 1] = p;
    // Or
    // insert(size-1);
}
// Inserting point at desired position.
void PointArray::insert(const int pos, const Point &p)
{
    resize(size + 1);
    for (int i = size - 1; i > pos; i++)
    {
        points[i] = points[i - 1];
    }
    points[pos] = p;
}

void PointArray::remove(const int pos)
{
    if (pos >= 0 && pos < size)
    {
        // Shifting everything left.
        for (int i = pos; i < size - 2; i++)
        {
            points[i] = points[i + 1];
        }
        resize(size - 1);
    }
}

// Pointer arithmetic.
Point *PointArray::get(const int pos)
{
    return pos >= 0 && pos < size ? points + pos : NULL;
}

const Point *PointArray::get(const int pos) const
{
    return pos >= 0 && pos < size ? points + pos : NULL;
}

// Always intialise static members
// in the cpp file.
int Polygon::numPolygons = 0;

// If given a PointArray object, this constructor will 
// call upon
Polygon::Polygon(const PointArray &pa) : points(pa)
{
    ++numPolygons;
}

Polygon::Polygon(const Point pointArr[], const int numPoints)
    : points(pointArr, numPoints)
{
    ++numPolygons;
}

// Make empty array to contain 4 Points.
Point constructorPoints[4];
// Create pointer to this array to allow updates.
// Notice the passing by reference. 
Point *updateConstructorPoints(const Point &p1, const Point &p2,
                               const Point &p3, const Point &p4 = Point(0, 0))
{
    // Initialize values.
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;
    // Return updated array.
    return constructorPoints;
}

Rectangle::Rectangle(const Point &ll, const Point &ur) :
    Polygon(updateConstructorPoints(ll, Point(ll.getX(), ur.getY()), 
    ur, Point(ur.getX(), ll.getY())), 4) {}

Rectangle::Rectangle(const int llx, const int lly, const int urx, const int ury) :
    Polygon(updateConstructorPoints(Point(llx,lly), Point(llx, ury), 
    Point(urx, lly), Point(urx, ury)), 4) {}

double Rectangle::area() const
{
    /* point.get(1) will retrieve the pointer to the 2nd element
    in the points array. points.get(1)->getY() == (*points[1]).y 
    and so we will recieve the y value associated with the 2nd
    point and so on.
    */
    int length = points.get(1)->getY() - points.get(0)->getY();
    int width = points.get(2)->getX() - points.get(1)->getX();
    // Need to return a double.
    return std::abs((double)length * width);
}

Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3) :
    Polygon(updateConstructorPoints(p1, p2, p3), 3) {}

double Triangle::area() const
{
    int dx01 = points.get(0)->getX() - points.get(1)->getX(),
        dx12 = points.get(1)->getX() - points.get(2)->getX(),
        dx20 = points.get(2)->getX() - points.get(0)->getX();
    int dy01 = points.get(0)->getY() - points.get(1)->getY(),
        dy12 = points.get(1)->getY() - points.get(2)->getY(),
        dy20 = points.get(2)->getY() - points.get(0)->getY();

    double a = std ::sqrt(dx01 * dx01 + dy01 * dy01),
           b = std ::sqrt(dx12 * dx12 + dy12 * dy12),
           c = std ::sqrt(dx20 * dx20 + dy20 * dy20);
    
    double s = (a + b + c) / 2;

    return std::sqrt(s  * (s-a) * (s-b) * (s-c));
}