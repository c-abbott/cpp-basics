// Using templates, implement a min function which returns the 
// minimum of two elements of any comparable type.
template <typename T>
T min(const T a, const T b)
{
    return a < b ? a : b;
}