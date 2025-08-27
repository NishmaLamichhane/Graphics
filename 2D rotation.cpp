#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    int n, i, direction;
    float angle_deg, angle_rad;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    float x[n], y[n], x_new[n], y_new[n];

    printf("Enter coordinates (x y) of each vertex:\n");
    for (i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%f %f", &x[i], &y[i]);
    }

    printf("Enter angle of rotation (in degrees): ");
    scanf("%f", &angle_deg);

    printf("Enter direction (1 for Clockwise, 2 for Counterclockwise): ");
    scanf("%d", &direction);

    // Convert angle to radians
    angle_rad = angle_deg * PI / 180;

    // Clockwise: negate the angle
    if (direction == 1) {
        angle_rad = -angle_rad;
    }

    // Apply rotation
    for (i = 0; i < n; i++) {
        x_new[i] = x[i] * cos(angle_rad) - y[i] * sin(angle_rad);
        y_new[i] = x[i] * sin(angle_rad) + y[i] * cos(angle_rad);
    }

    // Output results
    printf("\nOriginal\tRotated\n");
    for (i = 0; i < n; i++) {
        printf("(%.2f, %.2f)\t=>\t(%.2f, %.2f)\n", x[i], y[i], x_new[i], y_new[i]);
    }

    return 0;
}

