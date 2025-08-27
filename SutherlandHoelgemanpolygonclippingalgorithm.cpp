 #include <stdio.h>

#define MAX_VERTICES 100

typedef struct {
    float x, y;
} Point;

Point inputPolygon[MAX_VERTICES], clippedPolygon[MAX_VERTICES];
int inputCount, clippedCount;

// Clipping window boundaries
float xmin, ymin, xmax, ymax;

// Helper function to find intersection of a polygon edge and clip edge
Point intersect(Point p1, Point p2, int edge) {
    Point i;
    float m = (p2.y - p1.y) / (p2.x - p1.x);

    switch(edge) {
        case 0: // Left
            i.x = xmin;
            i.y = p1.y + m * (xmin - p1.x);
            break;
        case 1: // Right
            i.x = xmax;
            i.y = p1.y + m * (xmax - p1.x);
            break;
        case 2: // Bottom
            i.y = ymin;
            i.x = p1.x + (1/m) * (ymin - p1.y);
            break;
        case 3: // Top
            i.y = ymax;
            i.x = p1.x + (1/m) * (ymax - p1.y);
            break;
    }
    return i;
}

// Function to check if point is inside boundary
int inside(Point p, int edge) {
    switch(edge) {
        case 0: return p.x >= xmin;
        case 1: return p.x <= xmax;
        case 2: return p.y >= ymin;
        case 3: return p.y <= ymax;
    }
    return 0;
}

// Sutherland-Hodgman polygon clipping function
void clipPolygon(int edge) {
    Point temp[MAX_VERTICES];
    int tempCount = 0;
    Point S, E;
    int i;

    for (i = 0; i < inputCount; i++) {
        E = inputPolygon[i];
        S = inputPolygon[(i - 1 + inputCount) % inputCount];

        int Ein = inside(E, edge);
        int Sin = inside(S, edge);

        if (Sin && Ein) {
            // Case 1: Both inside
            temp[tempCount++] = E;
        } else if (Sin && !Ein) {
            // Case 2: S inside, E outside
            temp[tempCount++] = intersect(S, E, edge);
        } else if (!Sin && Ein) {
            // Case 3: S outside, E inside
            temp[tempCount++] = intersect(S, E, edge);
            temp[tempCount++] = E;
        }
        // Case 4: Both outside ? Do nothing
    }

    for (i = 0; i < tempCount; i++) {
        clippedPolygon[i] = temp[i];
    }
    inputCount = tempCount;
    for (i = 0; i < inputCount; i++) {
        inputPolygon[i] = clippedPolygon[i];
    }
}

// Main driver
int main() {
    int i;
    printf("Enter number of vertices in polygon: ");
    scanf("%d", &inputCount);

    printf("Enter coordinates (x y) of each vertex:\n");
    for (i = 0; i < inputCount; i++) {
        scanf("%f %f", &inputPolygon[i].x, &inputPolygon[i].y);
    }

    printf("Enter clipping window (xmin ymin xmax ymax): ");
    scanf("%f %f %f %f", &xmin, &ymin, &xmax, &ymax);

    for (i = 0; i < 4; i++) {
        clipPolygon(i); // Clip against Left, Right, Bottom, Top
    }

    printf("\nClipped polygon vertices:\n");
    for (i = 0; i < inputCount; i++) {
        printf("(%.2f, %.2f)\n", inputPolygon[i].x, inputPolygon[i].y);
    }

    return 0;
}

