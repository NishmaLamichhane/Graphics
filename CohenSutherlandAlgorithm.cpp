#include <stdio.h>

// Define region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Window boundaries
float x_min, y_min, x_max, y_max;

// Function to compute region code for a point (x, y)
int computeCode(float x, float y) {
    int code = INSIDE;

    if (x < x_min)
        code |= LEFT;
    else if (x > x_max)
        code |= RIGHT;

    if (y < y_min)
        code |= BOTTOM;
    else if (y > y_max)
        code |= TOP;

    return code;
}

// Cohen-Sutherland line clipping algorithm
void cohenSutherlandClip(float x1, float y1, float x2, float y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both endpoints inside: trivially accept
            accept = 1;
            break;
        } else if (code1 & code2) {
            // Both endpoints share an outside zone: trivially reject
            break;
        } else {
            // Some segment lies within the rectangle
            int code_out;
            float x, y;

            // Choose one endpoint outside the rectangle
            code_out = code1 ? code1 : code2;

            // Find intersection point
            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Replace point outside with intersection point
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        printf("Line accepted from (%.2f, %.2f) to (%.2f, %.2f)\n", x1, y1, x2, y2);
    } else {
        printf("Line rejected.\n");
    }
}

int main() {
    float x1, y1, x2, y2;

    printf("Enter coordinates of clipping window:\n");
    printf("x_min y_min: ");
    scanf("%f %f", &x_min, &y_min);
    printf("x_max y_max: ");
    scanf("%f %f", &x_max, &y_max);

    printf("\nEnter line coordinates:\n");
    printf("x1 y1: ");
    scanf("%f %f", &x1, &y1);
    printf("x2 y2: ");
    scanf("%f %f", &x2, &y2);

    cohenSutherlandClip(x1, y1, x2, y2);

    return 0;
}

