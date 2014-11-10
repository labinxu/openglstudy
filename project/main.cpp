#include <GL/freeglut.h>
#include <iostream>
#include <GL/glu.h>
#include <algorithm>
#include <math.h>
#include "../tools/include/headers.h"
using namespace std;



int xm, ym, xmm, ymm;
int first = 0;
void drawLine(Camus::Point pt1,Camus::Point pt2);
void DrawRect(Camus::Point pt1,Camus::Point pt2,Camus::Point pt3,Camus::Point pt4)
{
    glBegin(GL_QUADS);
    glVertex3fv(pt1.data());
    glVertex3fv(pt2.data());
    glVertex3fv(pt3.data());
    glVertex3fv(pt4.data());
    glEnd();
}
void init(int w, int h)
{
    std::cout<<"init"<<std::endl;
    glClearColor (0, 0, 0, 1);
    glColor3f(1, 1, 0);
    glShadeModel(GL_FLAT);
    return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w, w, -h, h);
    //glOrtho(-w, w, -h, h, -1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glLogicOp(GL_XOR);
    //glEnable(GL_COLOR_LOGIC_OP);
}
float thetar = 0;
void idle()
{
    std::cout<<"idle"<<std::endl;
    thetar += 2;
    if (thetar >= 360)
        thetar -= 360;
    glutPostRedisplay();
}
void display(void)
{
    //std::cout<<"dispaly"<<std::endl;
    float theta = thetar/(3.1415926/180);
    Camus::Point p1(-100*cos(theta), -100*sin(theta));
    Camus::Point p2(-100*sin(theta), 100*cos(theta));
    Camus::Point p3(100*cos(theta), 100*sin(theta));
    Camus::Point p4(100*sin(theta), -100*cos(theta));
    glClear(GL_COLOR_BUFFER_BIT);
    DrawRect(p1, p2, p3, p4);
    //glFlush();

    glutSwapBuffers();
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
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w, w, -h, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
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
    if(button == GLUT_LEFT_BUTTON)
    {
        if(state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
            return;
            thetar+=2;
            if(thetar >= 360)
            {
                thetar -= 360;
            }
            std::cout<<"thetar: "<<thetar<<std::endl;

        }
    }
    return;
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

        if(state == GLUT_DOWN)
        {
            xm = posX;
            ym = posY;
            //drawLine( Camus::Point(xm, ym), Camus::Point(300, 300));
            glLogicOp(GL_XOR);
            first = 0 ;
        }
        else if(state= GLUT_UP)
        {
            //drawLine( Camus::Point(xm, ym), Camus::Point(ymm, ymm));
            glLogicOp(GL_AND);
            drawLine( Camus::Point(xm, ym), Camus::Point(posX, posY));
        }

    }

    std::cout << "x "<<posX<<" y "<<posY <<" z "<<posZ<< std::endl;
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
    drawLine(Camus::Point(xm, ym), Camus::Point(xmm, ymm));
    first = 1;
}

/* ARGSUSED1 */
void keyboard (unsigned char key, int x, int y)
{
    std::cout<<"key "<<key<<std::endl;
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE| GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    // glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutIdleFunc(idle);
    init(500, 500);
    glutMainLoop();
   return 0;
}
