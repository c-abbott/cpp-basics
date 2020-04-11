// Assume you implemented Problem 5 from Problem Set 3 correctly.
// This would mean you would have a working Polygon class,
// and inheriting from that a Triangle class and a Rectangle class. 
// Now imagine you have a pointer declared as Rectangle *rect;
// that has been properly initialized.


// Recasts a Recatangle *p to a Triangle *p
// without checking for type correctness.
static_cast<Triangle *>(p)

// Recasts a Recatangle *p to a Triangle *p
// but checks for type correctness first.
// If failed, a NULL pointer is returned.
dynamic_cast<Triangle *>(p)
