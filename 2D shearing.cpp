#include <stdio.h>

// Function to perform X-shear
void xShear(float x, float y, float shx) {
    float x_new = x + shx * y;
    float y_new = y;

    printf("\nAfter X-shear:\n");
    printf("New Coordinates: (%.2f, %.2f)\n", x_new, y_new);
}

// Function to perform Y-shear
void yShear(float x, float y, float shy) {
    float x_new = x;
    float y_new = y + shy * x;

    printf("\nAfter Y-shear:\n");
    printf("New Coordinates: (%.2f, %.2f)\n", x_new, y_new);
}

// Function to perform XY-shear
void xyShear(float x, float y, float shx, float shy) {
    float x_new = x + shx * y;
    float y_new = y + shy * x;

    printf("\nAfter XY-shear:\n");
    printf("New Coordinates: (%.2f, %.2f)\n", x_new, y_new);
}

int main() {
    float x, y, shx, shy;

    // Input original coordinates and shear factors
    printf("Enter original coordinates (x y): ");
    scanf("%f %f", &x, &y);

    printf("Enter shear factor in X-direction (shx): ");
    scanf("%f", &shx);

    printf("Enter shear factor in Y-direction (shy): ");
    scanf("%f", &shy);

    // Perform transformations
    xShear(x, y, shx);
    yShear(x, y, shy);
    xyShear(x, y, shx, shy);

    return 0;
}

