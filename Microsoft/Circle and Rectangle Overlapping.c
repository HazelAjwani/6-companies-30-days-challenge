#include <math.h>
#include <stdbool.h>

// Function to calculate the square of the distance between two points
int calculateDistanceSquared(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

// Function to check overlap between a circle and a rectangle
bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    // Clamp the circle's center to the rectangle's boundary
    int closestX = (xCenter < x1) ? x1 : (xCenter > x2) ? x2 : xCenter;
    int closestY = (yCenter < y1) ? y1 : (yCenter > y2) ? y2 : yCenter;

    // Calculate the squared distance from the circle's center to the closest point
    int distanceSquared = calculateDistanceSquared(xCenter, yCenter, closestX, closestY);

    // Compare the squared distance with the square of the radius
    return distanceSquared <= radius * radius;
}
