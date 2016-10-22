#include <GLUT/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_POLYGON);
        glVertex2i(0, 0);
        glVertex2i(0, 100);
        glVertex2i(100, 100);
        glVertex2i(100, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2i(100, 100);
        glVertex2i(300, 100);
        glVertex2i(200, 300);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2i(299, 381);
        glVertex2i(327, 299);
        glVertex2i(362, 316);
        glVertex2i(381, 355);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2i(0, 400);
        glVertex2i(100, 300);
        glVertex2i(66, 300);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Graphics2D");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
    glutDisplayFunc(display);
    glutMainLoop();
}
