#include <math.h>
#include <stdio.h>

typedef struct {
    double x;
    double y;
} Point;

Point getCoordinates(double d_origin, double d_1_0) {
    Point p;
    
    // Check for degenerate case where no intersection is possible.
    if (d_origin <= 0 || d_1_0 <= 0) {
        p.x = NAN;
        p.y = NAN;
        return p;
    }

    // We want to solve for the intersection of two circles:
    // Circle 1: centered at (0, 0) with radius d_origin
    // Circle 2: centered at (1, 0) with radius d_1_0

    // x-coordinate of the point can be found using the formula derived from the intersection of two circles:
    double x = (d_origin * d_origin - d_1_0 * d_1_0 + 1) / 2;

    // If |x| is greater than the radius of the first circle, no solution exists.
    double under_sqrt = d_origin * d_origin - x * x;
    if (under_sqrt < 0) {
        p.x = NAN;
        p.y = NAN;
        return p;
    }

    // y-coordinate can be found by using Pythagoras' theorem.
    double y = sqrt(under_sqrt);

    p.x = x;
    p.y = y;
    
    return p;
}

int main() {
    double d_origin = 5.0;  // Example distance from (0,0)
    double d_1_0 = 4.0;     // Example distance from (1,0)

    Point result = getCoordinates(d_origin, d_1_0);
    if (isnan(result.x) || isnan(result.y)) {
        printf("No valid intersection\n");
    } else {
        printf("Coordinates: x = %f, y = %f\n", result.x, result.y);
    }
    
    return 0;
}
