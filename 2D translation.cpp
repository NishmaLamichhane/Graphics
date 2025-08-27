#include <stdio.h>

int main() {
    int n, i;
    float tx, ty;

    printf("Enter the number of vertices of the polygon: ");
    scanf("%d", &n);

    float x[n], y[n]; // Original coordinates
    float x_new[n], y_new[n]; // Translated coordinates

    // Input original coordinates
    printf("Enter the coordinates (x y) of each vertex:\n");
    for(i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%f %f", &x[i], &y[i]);
    }

    // Input translation factors
    printf("Enter the translation factors (tx ty): ");
    scanf("%f %f", &tx, &ty);

    // Perform translation
    for(i = 0; i < n; i++) {
        x_new[i] = x[i] + tx;
        y_new[i] = y[i] + ty;
    }

    // Output translated coordinates
    printf("\nOriginal\tTranslated\n");
    for(i = 0; i < n; i++) {
        printf("(%.2f, %.2f)\t=>\t(%.2f, %.2f)\n", x[i], y[i], x_new[i], y_new[i]);
    }

    return 0;
}

