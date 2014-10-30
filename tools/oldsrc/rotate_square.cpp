#if 0
#include <gl/glut.h>
#include <math.h>
#include "KaMiWindowManager.h"
#include "KaMiRender.h"
#include "Vector3.h"
using namespace KaMi;
static GLdouble thetar = 0;
GLfloat x=25,y=25;
GLfloat PI = 3.1415926;
void square()
{
    glBegin(GL_QUADS);
        glVertex2f(x,y);
        glVertex2f(-y,x);
        glVertex2f(-x,-y);
        glVertex2f(y, -x);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    square();
    glutSwapBuffers();
    glFlush();
    return;
    GLfloat vertices[3][2]={{0, 0}, {25, 50}, {50, 0}};
    GLfloat p[2]={7.5, 5};
    glBegin(GL_POINTS);
    for (int k =0 ; k< 5000; k++)
    {
        int j = rand() % 3;
        p[0] = (p[0]+vertices[j][0])/2;
        p[1] = (p[1] + vertices[j][1])/2;
        glVertex2fv(p);
    }
    glEnd();
    
    //glFlush();
}

void Idle()
{
    thetar += 1;
    if (thetar >= 360)
    {
        thetar -= 360;
    }
    x = 25 * cos(PI/180 * thetar);
    y = 25 * sin(PI/180 * thetar);

    glutPostRedisplay();
}

void mouse(int button,int state ,int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        glutIdleFunc(Idle);
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        glutIdleFunc(NULL);
    }
}
void Init()
{
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50,50,-50,50);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel(GL_FLAT);

}

void Reshape(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
    {
        gluOrtho2D(-50, 50,-50 * h / w, 50*h/w);
    }
    else
    {
        gluOrtho2D(50*w/h,50*w/h,-50,50);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int main(int argc,char **argv)
{/*
    thetar =10;
    IWindowManager *pWinManager = KaMiWindowManager::Instance(argc,argv);
    WindowData winData("KaMiWindow",500,500,GLUT_SINGLE|GLUT_RGB |GLUT_DEPTH,GePoint2D(0.0,0.0));
    winData.winName = "KamiWindow";

    IWindow *pWin = pWinManager->createWindow(winData);
    pWin->setRender(new MyRender);
    pWin->setBlankgroundColor(0.0,1.0,0.0);
    pWin->moveTo(GePoint2D(200,200));
    glClearColor(0.0, 0.0, 0.0, 1.0);
    pWin->show();*/

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE| GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition(0,0);
    glutCreateWindow (argv[0]);
    glutDisplayFunc(display);
    //glutReshapeFunc(Reshape);
    glutMouseFunc(mouse);
    Init();
    
    glutMainLoop();
    return 0;

}
#endif