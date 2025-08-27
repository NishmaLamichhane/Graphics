#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p = 2 * dy - dx;
    int x = x1;
    int y = y1;

    putpixel(x, y, WHITE);

    for (x = x1 + 1; x <= x2; x++) {
        if (p < 0) {
            p = p + 2 * dy;
        } else {
            y++;
            p = p + 2 * dy - 2 * dx;
        }
        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    // Get input BEFORE initializing graphics mode
    printf("Enter starting point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter ending point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    // Now initialize graphics
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Call the line drawing function
    bresenhamLine(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

