#include <stdio.h>

int main() {
    int n, i;
    float points[100][2];      // original points
    float scaled[100][2];      // scaled points
    float Sx, Sy;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input coordinates
    for(i = 0; i < n; i++) {
        printf("Enter x%d and y%d: ", i+1, i+1);
        scanf("%f%f", &points[i][0], &points[i][1]);
    }

    // Input scaling factors
    printf("Enter scaling factor Sx: ");
    scanf("%f", &Sx);
    printf("Enter scaling factor Sy: ");
    scanf("%f", &Sy);

    // Perform scaling
    for(i = 0; i < n; i++) {
        scaled[i][0] = points[i][0] * Sx;
        scaled[i][1] = points[i][1] * Sy;
    }

    // Display results
    printf("\nOriginal Points:\n");
    for(i = 0; i < n; i++) {
        printf("(%.2f, %.2f)\n", points[i][0], points[i][1]);
    }

    printf("\nScaled Points:\n");
    for(i = 0; i < n; i++) {
        printf("(%.2f, %.2f)\n", scaled[i][0], scaled[i][1]);
    }

    return 0;
}

