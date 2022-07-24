#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

int xstart, ystart, xend, yend;
void init()
{

    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y)
{
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void Bresalgo(int xstart, int ystart, int xend, int yend)
{
    int dx = abs(xend - xstart);
    int dy = abs(yend - ystart);
    int twody = 2 * dy, twodyminusdx = 2 * (dy - dx);
    int p = 2 * dy - dx;
    int x, y;
    if (xstart > xend)
    {
        x = xend;
        y = yend;
        xend = xstart;
    }
    else
    {
        x = xstart;
        y = ystart;
    }
    draw_pixel(x, y);
    while (x < xend)
    {
        x++;
        if (p < 0)
            p += twody;
        else
        {
            y++;
            p += twodyminusdx;
        }
        draw_pixel(x, y);
    }
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Bresalgo(xstart, ystart, xend, yend);
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter (x1, y1, x2, y2)\n");
    scanf("%d%d%d%d", &xstart, &ystart, &xend, &yend);
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham's Line Drawing");
    init();
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
