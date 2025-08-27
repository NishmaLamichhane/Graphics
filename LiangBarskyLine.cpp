#include <stdio.h>

// Clipping window boundaries
float xmin, ymin, xmax, ymax;

// Function to perform Liang-Barsky line clipping
int liangBarsky(float x1, float y1, float x2, float y2,
                float *newX1, float *newY1, float *newX2, float *newY2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

    float u1 = 0.0f, u2 = 1.0f;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0)
                return 0; // Line is parallel and outside the clipping edge
        } else {
            float r = q[i] / p[i];
            if (p[i] < 0)
                u1 = (r > u1) ? r : u1;
            else
                u2 = (r < u2) ? r : u2;
        }
    }

    if (u1 > u2)
        return 0; // Line is outside

    *newX1 = x1 + u1 * dx;
    *newY1 = y1 + u1 * dy;
    *newX2 = x1 + u2 * dx;
    *newY2 = y1 + u2 * dy;

    return 1; // Line is clipped
}

int main() {
    float x1, y1, x2, y2;
    float clippedX1, clippedY1, clippedX2, clippedY2;

    // Input clipping window
    printf("Enter clipping window (xmin ymin xmax ymax): ");
    scanf("%f %f %f %f", &xmin, &ymin, &xmax, &ymax);

    // Input line coordinates
    printf("Enter line endpoints (x1 y1 x2 y2): ");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    // Perform clipping
    if (liangBarsky(x1, y1, x2, y2, &clippedX1, &clippedY1, &clippedX2, &clippedY2)) {
        printf("\nLine is inside the window after clipping.\n");
        printf("Clipped coordinates: (%.2f, %.2f) to (%.2f, %.2f)\n",
               clippedX1, clippedY1, clippedX2, clippedY2);
    } else {
        printf("\nLine is outside the clipping window.\n");
    }

    return 0;
}

