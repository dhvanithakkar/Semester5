#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include <iostream.h> 
#include <dos.h>

int points[100][3];

void draw_line(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
    delay(100);
}
void mark_points(int n){
    int offs = 0.1, i;
    for(i = 0; i < n; i++) {
    circle(points[i][0], points[i][1], offs);
    delay(100);
    }
}
int x_scale(int x, int x_max, int scale)
{
    return x * scale;
}
int y_scale(int y, int y_max, int scale)
{
    return y_max - y * scale;
}

void draw_margins(int x, int y)
{
    draw_line(0, 0, 0, y);
    draw_line(0, y, x, y);
    draw_line(x, y, x, 0);
    draw_line(x, 0, 0, 0);
}
void bubble_sort(int n) {  
  int i, j;  
  for (i = 0; i < n - 1; i++) {  
    for (j = 0; j < n - i - 1; j++) {  
      if (points[j][2] > points[j + 1][2]) {  
        int temp = points[j][2];  
        points[j][2] = points[j + 1][2];  
        points[j + 1][2] = temp;  
      }  
    }  
  }  
}  

void compute_angles(int n, int p0)
{
    
}


void main() {
    int n;
    int p0 = -1;
    int p0x = 5000, p0y = 5000, i, x, y;
    int x_max = 600, y_max = 450, scale = 30;
    int gdriver = DETECT, gmode;

    printf("Enter number of points:");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter x and y coordinates of point %d:\n", (i+1));
        scanf("%d", &x);
        scanf("%d", &y);
        x = x_scale(x, x_max, scale);
        y = y_scale(y, y_max, scale);
        if(x < p0x && y < p0y) {
            p0 = i;
            p0x = x;
            p0y = y;
        }
        points[i][0]= x;
        points[i][1]= y;
        points[i][2]= 0;
    }

    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
    mark_points(n);
    draw_margins(x_max, y_max);
    for(i = 1; i < n; i++)
    {
    draw_line(points[i-1][0], points[i-1][1], points[i][0], points[i][1]);
    }
    getch();
    closegraph();
}
