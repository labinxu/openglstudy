#include <GL/freeglut.h>
#include <iostream>
#include <GL/glu.h>
#include <algorithm>
#include "../tools/include/headers.h"
using namespace std;


int xm, ym, xmm, ymm;
int first = 0;
void drawLine(Camus::Point pt1,Camus::Point pt2);

void init(int w, int h)
{
    glClearColor (0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w, w, -h, h);
    //glOrtho(-w, w, -h, h, -1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void)
{
    // std::cout << "display" << std::endl;
    // glClear(GL_COLOR_BUFFER_BIT);
    // glPointSize(10);
    // glBegin(GL_POINTS);
    // glColor3f(1, 0, 0);
    // glVertex3f(0, 0, 0);
    // glColor3f(1, 1, 0);
    // glVertex3f(100, 100, 0);
    // glEnd();
    // glFlush();
}


void reshape (int w, int h)
{
    std::cout<<"reshape"<<std::endl;
    glViewport (0, 0, w, h);
}


void viewportToModelView(int x, int y, double &posX, double &posY, double &posZ)
{
    GLint viewPort[4];
    GLdouble modelview[16];
    double projection[16];
    float winX, winY, winZ=1;
    //glPushMatrix();
    glGetIntegerv(GL_VIEWPORT, viewPort);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    //glPopMatrix();
    winX = x;
    winY = viewPort[3] - y;
    glReadPixels(winX, winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
    gluUnProject(winX, winY, 1, modelview, projection, viewPort, &posX, &posY, &posZ);

}
void mouse(int button, int state, int x, int y)
{
    std::cout << "mouse" << std::endl;
    GLint viewPort[4];
    GLdouble modelview[16];
    double projection[16];
    float winX, winY, winZ=1;
    double posX, posY, posZ;
    //glPushMatrix();
    glGetIntegerv(GL_VIEWPORT, viewPort);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    //glPopMatrix();
    winX = x;
    winY = viewPort[3] - y;
    glReadPixels(winX, winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
    gluUnProject(winX, winY, 1, modelview, projection, viewPort, &posX, &posY, &posZ);

    std::cout <<"button" << button <<": state "<< state<<std::endl;
    if(button == GLUT_LEFT_BUTTON)
    {
        xm = posX;
        ym = posY;

        if(state == GLUT_DOWN)
        {
            glLogicOp(GL_XOR);
            drawLine( Camus::Point(0, 0), Camus::Point(300, 300));
        }
    }
    std::cout << "x "<<posX<<" y "<<posY <<" z "<<posZ<< std::endl;
    //glutPostRedisplay();
}
void drawLine(Camus::Point pt1,Camus::Point pt2)
{
    glBegin(GL_LINES);
    glVertex3fv(pt1.data());
    glVertex3fv(pt2.data());
    glEnd();
    glFlush();
}
void motion(int x, int y)
{
    return;
    double posX, posY, posZ;
    viewportToModelView(x, y, posX, posY, posZ);
    if(first == 1)
    {
        drawLine(Camus::Point(xm, ym), Camus::Point(xmm, ymm));
    }
    xmm = posX;
    ymm = posY;
    //drawLine( Camus::Point(preposx, preposy), Camus::Point(posxx, posyy));
    drawLine(Camus::Point(xm, ym), Camus::Point(xmm, ymm));
    first = 1;
}

/* ARGSUSED1 */
void keyboard (unsigned char key, int x, int y)
{

}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   // glutKeyboardFunc(keyboard);
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
   init(500, 500);
   glutMainLoop();
   return 0;
}
