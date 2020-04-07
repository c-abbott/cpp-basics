class Point {
private:
    int x, y;

public:
    Point(int xx = 0, int yy = 0) { x = xx; y = yy; }
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(const int xx) { x = xx; }
    void setY(const int yy) { y = yy; }
};

class PointArray {
private:
    Point *points; // Pointer to points array.
    int size; // Size of points array.

public:
    PointArray();
    PointArray(const Point copyPoints[], const int copySize);
    PointArray(const PointArray &o);
    ~PointArray();
};