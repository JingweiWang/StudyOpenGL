#include <GLUT/glut.h>
#include <math.h>

#define p 3.141593 / 180
#define N 1 //一阶N=1

void Koch(float x, float y, float len, float alpha, int n)
{
    if (n > 3)
    {
	len = len / 3;
	Koch(x, y, len, alpha, n - 1);
	x = x + len * cos(alpha * p); //p=3.141593/180
	y = y + len * sin(alpha * p);
	Koch(x, y, len, alpha - 60, n - 1);
	x = x + len * cos((alpha - 60) * p);
	y = y + len * sin((alpha - 60) * p);
	Koch(x, y, len, alpha + 60, n - 1);
	x = x + len * cos((alpha + 60) * p);
	y = y + len * sin((alpha + 60) * p);
	Koch(x, y, len, alpha, n - 1);
    }
    else
    {
	glVertex2f(x, y);
	glVertex2f(x + len * cos(alpha * p), y + len * sin(alpha * p));
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    Koch(100, 113.4, 200, 0, N + 3);
    Koch(300, 113.4, 200, 120, N + 3);
    Koch(200, 286.6, 200, 240, N + 3);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("KochSnow");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
    glutDisplayFunc(display);
    glutMainLoop();
}
