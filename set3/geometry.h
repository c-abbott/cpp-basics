class Point
{
// Create class to represent Cartesian points
 // with private x and y variables
private:
    int x, y;

public:
    // Constructor.
    Point(int xx = 0, int yy = 0)
    {
        x = xx;
        y = yy;
    }
    // Prototypes.
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(const int xx) { x = xx; }
    void setY(const int yy) { y = yy; }
};

// Class to represent an array of points.
class PointArray
{
private:
    Point *points; // Pointer to points array.
    int size;      // Size of points array.

    // Only internal functions need to access this method.
    // Therefore make it private.
    void resize(int newSize);

public:
    // Constructors.
    PointArray(); // 0 argument
    // Constructs PointArray from array of Points
    // and some given size.
    PointArray(const Point copyPoints[], const int copySize);
    // Copy Constructor - must pass by reference.
    PointArray(const PointArray &o);
    // Destructor.
    ~PointArray();

    // Prototypes.
    void pushBack(const Point &p); // Add point to end
    void insert(const int pos, const Point &p); // Add point anywhere
    void remove(const int pos); // Remove point
    int getSize() const { return size; }
    void clear();
    // Getting pointer to some arbritrary element in the 
    // array. Need const version for const objects.
    Point *get(const int pos); 
    const Point *get(const int pos) const;
};

// Polygon ABSTRACT class - it will not be instantiated itself,
// only subclasses derived from it i.e. Rectangle, Triangle.
class Polygon
{
protected:
    static int numPolygons;
    /* Polygon contains the actual PointArray object
    whilst PointArray contains a pointer to the first 
    element of this array*/
    PointArray points;

public:
    // Constructors.
    Polygon(const PointArray &pa);
    Polygon(const Point polyPoints[], const int numPoints);
    ~Polygon() { --numPolygons; };

    // Prototypes.
    // Virtual as will be defined in subclasses.
    virtual double area() const = 0;
    static int getNumPolygons() { return numPolygons; }
    int getNumSides() const { return points.getSize(); }
    const PointArray *getPoints() { return &points; }
};

class Rectangle : public Polygon
{
public:
    // Constructors
    Rectangle(const Point &ll, const Point &ur); // 2 Point
    Rectangle(const int a, const int b, const int c, const int d); // 4 ints

    // Prototypes.
    virtual double area() const;
};

class Triangle : public Polygon
{
public:
    // Constructors
    Triangle(const Point &p1, const Point &p2, const Point &p3); // 3 point

    // Prototypes.
    virtual double area() const;
};