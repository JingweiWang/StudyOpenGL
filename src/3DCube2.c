#include <GLUT/glut.h>
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45.0, float(w) / h, 0.1, 100.0);
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity(); //设置当前矩阵为单位矩阵
    gluLookAt(2.0, 1.8, 2.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    glColor3f(1.0, 0.0, 1.0);
    glutWireTeapot(1);

    glColor3f(0.0, 1.0, 0.0);
    glScalef(2, 2, 2); //x方向放大2倍
    //glRotated(15,0,1,0);
    glTranslated(-1.1, -1.1, 0);
    glutSolidCube(1.3);

    glFlush();
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Cube");
    init();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutMainLoop();
}
