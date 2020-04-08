class Point
{
private:
    int x, y;

public:
    Point(int xx = 0, int yy = 0)
    {
        x = xx;
        y = yy;
    }
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(const int xx) { x = xx; }
    void setY(const int yy) { y = yy; }
};

class PointArray
{
private:
    Point *points; // Pointer to points array.
    int size;      // Size of points array.

    // Only internal function need to access this method.
    void resize(int newSize);

public:
    // Constructors.
    PointArray();
    PointArray(const Point copyPoints[], const int copySize);
    PointArray(const PointArray &o);
    ~PointArray();

    // Prototypes.
    void pushBack(const Point &p);
    void insert(const int pos, const Point &p);
    void remove(const int pos);
    int getSize() const { return size; }
    void clear();
    Point *get(const int pos);
    const Point *get(const int pos) const;
};

class Polygon
{
protected:
    static int numPolygons;
    PointArray points;

public:
    // Constructors.
    Polygon(const PointArray &pa);
    Polygon(const Point polyPoints[], const int numPoints);
    ~Polygon() { --numPolygons; }

    // Prototypes.
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
    virtual double area() const;
}