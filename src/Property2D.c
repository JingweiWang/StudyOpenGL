#include <GLUT/glut.h>

void display(void)
{
    int i;
    float pointSize = 0;
    float lineWidth = 0;
    int polygonMode[2];
    int lineStipples[] = {
        //1010 1010 1010 1010 = 10 10 10 10
        0xAAAA,
        //0000 1111 0000 1111 =  0 15  0 15
        0x0F0F,
        //1111 1111 1111 0000 = 15 15 15  0
        0xFFF0,
        //0000 0000 0000 1111 =  0  0  0 15
        0x000F,
        //0001 0001 0001 0001 =  1  1  1  1
        0x1111};

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    //Point
    glGetFloatv(GL_POINT_SIZE, &pointSize);
    for (i = 0; i < 5; i++) //以递增尺寸绘制5个点
    {
        glPointSize((float)(i + 1));
        glBegin(GL_POINTS);
            glVertex2f(-0.4f + i / 5.0f, 0.8f);
        glEnd();
    }
    glPointSize(pointSize); //点尺寸恢复为前面的值

    // Line Width
    glGetFloatv(GL_LINE_WIDTH, &lineWidth);
    for (i = 0; i < 5; i++)
    {
        glLineWidth((float)(i + 1));
        glBegin(GL_LINES);
            glVertex3f(-0.6f, 0.7f - i * 0.1f, 0.0f);
            glVertex3f(0.6f, 0.7f - i * 0.1f, 0.0f);
        glEnd();
    }
    glLineWidth(lineWidth);

    // Polygon Mode
    glGetIntegerv(GL_POLYGON_MODE, polygonMode);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.8f, 0.0f, 0.0f);
        glVertex3f(-0.6f, 0.0f, 0.0f);
        glVertex3f(-0.7f, 0.2f, 0.0f);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);
        glVertex3f(0.1f, 0.0f, 0.0f);
        glVertex3f(-0.1f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.2f, 0.0f);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    glBegin(GL_TRIANGLES);
        glVertex3f(0.6f, 0.0f, 0.0f);
        glVertex3f(0.8f, 0.0f, 0.0f);
        glVertex3f(0.7f, 0.2f, 0.0f);
    glEnd();

    glPolygonMode(GL_FRONT, polygonMode[0]);
    glPolygonMode(GL_BACK, polygonMode[1]);

    // Line Stipple
    glEnable(GL_LINE_STIPPLE);
    for (i = 0; i < 5; i++)
    {
        glLineStipple(1, lineStipples[i]);
        glBegin(GL_LINES);
            glVertex3f(-0.6f, -0.1f - i * 0.1f, 0.0f);
            glVertex3f(-0.1f, -0.1f - i * 0.1f, 0.0f);
        glEnd();
        glLineStipple(3, lineStipples[i]);
        glBegin(GL_LINES);
            glVertex3f(0.6f, -0.1f - i * 0.1f, 0.0f);
            glVertex3f(0.1f, -0.1f - i * 0.1f, 0.0f);
        glEnd();
    }
    glDisable(GL_LINE_STIPPLE);

    //LINE LOOP
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.35f, -0.75f, 0.0f);
        glVertex3f(0.35f, -0.75f, 0.0f);
        glVertex3f(0.2f, -0.57f, 0.0f);
        glVertex3f(0.0f, -0.65f, 0.0f);
        glVertex3f(-0.2f, -0.57f, 0.0f);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Property2D");
    glClearColor(0.95, 0.95, 0.95, 1.0);
    //gluOrtho2D(0.0,400.0, 0.0,400.0);
    glutDisplayFunc(display);
    glutMainLoop();
}
