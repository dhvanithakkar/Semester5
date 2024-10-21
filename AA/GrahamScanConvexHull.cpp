/*
OKAY. SO.
Margins and scaling in graphics.h library
Syntax of graphics
did not take tan for slope of line from p0.

bottom most point is p0. or leftmost.
take slope of each point wrt p0 and sort accordingly. we have now numbered the points.
if slope is same, find distance from p0, smallest first.
CHANGE COLOUR IF IT IS TO BE DELETED
*/

#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dos.h>

struct Point{
    int x, y;
    float slope;
}

Point points[100];

void draw_line(Point p1, Point p2, int colour = 15){
    setcolor(colour)
    line(p1.x, p1.y, p2.x, p2.y);
    delay(100);
    setcolor(WHITE);
}

void mark_points(int n){
    int offs = 0.1, i;
    for (i = 0; i < n; i++){
        circle(points[i].x, points[i].y, offs);
        delay(100);
    }
}

int x_scale(int x, int x_max, int scale){
    return x * scale;
}

int y_scale(int y, int y_max, int scale){
    return y_max - y * scale;
}

void draw_margins(int x, int y, int colour){
    setcolor(colour);
    line(0, 0, 0, y);
    line(0, y, x, y);
    line(x, y, x, 0);
    line(x, 0, 0, 0);
    setcolor(WHITE);
}

bool slope1_gt_slope2(Point p1, Point p2){
    return points[j].slope > points[j + 1].slope;
}

bool dist1_gt_dist2(Point p0, Point p1, Point p2){

}

void bubble_sort(int n){
    int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (slope1_gt_slope2(p1, p2) || (points[j].slope == points[j + 1].slope &&)){
                Point temp = points[j];
                points[j] = points[j + 1];
                points[j + 1] = temp;
            }
        }
    }
}

void get_slope(Point p0, Point p1){
    int x1 = p1.x, y1 = p1.y;
    int x2 = p2.x, y2 = p2.y;
}

void all_angles(int n, int p0){
    int x1 = points[p0].x, y1 = points[p0].y;

    for (int i = 0; i < n; i++){
        if (i == p0){
            points[i].slope = 0;
            continue;
        }
        int x2 = points[i].x, y2 = points[i].y;

        float slope = (y2 - y1) / (x2 - x1);

        points[i].slope = slope;
    }
}

int distSq(Point p1, Point p2){
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

void main(){
    int n;
    int p0 = -1;
    int p0x = 5000, p0y = 5000, i, x, y;
    int x_max = 600, y_max = 450, scale = 30;
    int gdriver = DETECT, gmode;

    printf("Enter number of points:");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("Enter x and y coordinates of point %d:\n", (i + 1));
        scanf("%d", &x);
        scanf("%d", &y);
        x = x_scale(x, x_max, scale);
        y = y_scale(y, y_max, scale);
        if (y < p0y) || (p0y == y && x < p0x){
            p0 = i;
            p0x = x;
            p0y = y;
        }
        points[i].x = x;
        points[i].y = y;
        points[i].slope = 0;
    }

    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
    mark_points(n);
    draw_margins(x_max, y_max);
    compute_angles(n, p0);
    bubble_sort(n);
    for (i = 1; i < n; i++){
        draw_line(points[0], points[i]);
    }
    getch();
    closegraph();
}

Point nextToTop(stack<Point> &S){
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;             
    return (val > 0) ? 1 : 2; 
}

int compare(const void *vp1, const void *vp2){
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

void convexHull(Point points[], int n){
    // Find the bottommost point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++){
        int y = points[i].y;

        // Pick the bottom-most or choose the left
        // most point in case of tie
        if ((y < ymin) || (ymin == y &&
                           points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // Place the bottom-most point at first position
    swap(points[0], points[min]);

    // Sort n-1 points with respect to the first point.
    // A point p1 comes before p2 in sorted output if p2
    // has larger polar angle (in counterclockwise
    // direction) than p1
    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);

    // If two or more points make same angle with p0,
    // Remove all but the one that is farthest from p0
    // Remember that, in above sorting, our criteria was
    // to keep the farthest point at the end when more than
    // one points have same angle.
    int m = 1; // Initialize size of modified array
    for (int i = 1; i < n; i++){
        // Keep removing i while angle of i and i+1 is same
        // with respect to p0
        while (i < n - 1 && orientation(p0, points[i],
                                        points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++; // Update size of modified array
    }

    // If modified array of points has less than 3 points,
    // convex hull is not possible
    if (m < 3)
        return;

    // Create an empty stack and push first three points
    // to it.
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // Process remaining n-3 points
    for (int i = 3; i < m; i++){
        // Keep removing top while the angle formed by
        // points next-to-top, top, and points[i] makes
        // a non-left turn
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    // Now stack has the output points, print contents of stack
    while (!S.empty()){
        Point p = S.top();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        S.pop();
    }
}

// Driver program to test above functions
int main(){
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
