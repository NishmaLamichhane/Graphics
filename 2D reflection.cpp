#include <stdio.h>

int main() {
    float x, y, rx, ry;
    int choice;

    printf("Enter the coordinates of the point (x y): ");
    scanf("%f %f", &x, &y);

    printf("\nChoose the line of reflection:\n");
    printf("1. x-axis\n");
    printf("2. y-axis\n");
    printf("3. y = x\n");
    printf("4. y = -x\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            rx = x;
            ry = -y;
            printf("Reflected over x-axis: (%.2f, %.2f)\n", rx, ry);
            break;
        case 2:
            rx = -x;
            ry = y;
            printf("Reflected over y-axis: (%.2f, %.2f)\n", rx, ry);
            break;
        case 3:
            rx = y;
            ry = x;
            printf("Reflected over y = x: (%.2f, %.2f)\n", rx, ry);
            break;
        case 4:
            rx = -y;
            ry = -x;
            printf("Reflected over y = -x: (%.2f, %.2f)\n", rx, ry);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

