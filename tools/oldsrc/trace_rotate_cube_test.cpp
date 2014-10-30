#if 0

#include <math.h>
#include <gl/glut.h>
#include "kmMathUtil.h"
#include <float.h>
#include <iostream>
#include "Vector3.h"
#include "kmMainIncludes.h"
using namespace std;;
using namespace KaMi;

int winWidth,winHeight;
GLfloat angle = 0,axis[3],trans[3];
bool trackingMouse = false;
bool redrawContinue = false;
bool trackballMove = false;

kmVector3 gCurPos;
kmVector3 gPrePos;
/*
  draw the  cube
*/

#include "Vector3.h"
KaMi::kmVector3 verts[] =
{
    KaMi::kmVector3(-1, -1, -1),KaMi::kmVector3(1, -1, -1),
    KaMi::kmVector3(1, 1, -1), KaMi::kmVector3(-1, 1, -1),
    KaMi::kmVector3(-1, -1, 1), KaMi::kmVector3(1, -1, 1),
    KaMi::kmVector3(1, 1, 1) ,KaMi::kmVector3(-1, 1, 1)
};

GLfloat vertices[][3] = 
{
    {-1, -1, -1},{1, -1, -1},
    {1, 1, -1},{-1, 1, -1},
    {-1, -1, 1},{1, -1, 1},
    {1, 1, 1},{-1, 1, 1}
};
GLfloat colors[][3] =
{
    {0, 0, 0},{1, 0, 0},
    {1, 1, 0},{0, 1, 0},
    {0, 0, 1},{1, 0, 1},
    {1, 1, 1},{0, 1, 1}
};
void polygon(int a,int b, int c, int d, int face)
{
    glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glVertex3fv(verts[a].vertices());
    glVertex3fv(verts[b].vertices());
    glVertex3fv(verts[c].vertices());
    glVertex3fv(verts[d].vertices());
    glEnd();
}

//void polygon1(int a,int b, int c, int d, int face)
//{
//    glBegin(GL_POLYGON);
//    glColor3fv(colors[a]);
//    glVertex3fv(vertices[a]);
//    glVertex3fv(vertices[b]);
//    glVertex3fv(vertices[c]);
//    glVertex3fv(vertices[d]);
//    glEnd();
//}

void colorCube()
{
    polygon(1, 0, 3, 2, 0);
    polygon(3, 7, 6, 2, 1);
    polygon(7, 3, 0, 4, 2);
    polygon(2, 6, 5, 1, 3);
    polygon(4, 5, 6, 7, 4);
    polygon(5, 4, 0, 1, 5);
}
// 
GLfloat lastPos [3] ={0, 0, 0};
int curx, cury;
int startx, startY;
void trackball_ptov(int x, int y ,int width, int height, KaMi::kmVector3 &pos)
{
    pos[KaMi::kmVector3::kmX] =   x ;
    pos[KaMi::kmVector3::kmY] =  y;
    GLfloat d = sqrt(GLfloat (x*x + y*y));
    pos[KaMi::kmVector3::KmZ] = 1;

}
void trackball_ptov(int x, int y ,int width, int height, float v[3])
{
    //must use the float
    GLfloat d, a;
    if(height ==0 || width == 0)
        return;
    v[0] = (2.0 * x - width) / width;
    v[1] = (height - 2.0 * y)/ height;
    d = sqrt(v[0]*v[0] + v[1] * v[1]);
    v[2] = cos(kmPi / 2) *(d < 1) ? d : 1 ;
    a = 1.0F /(float) sqrt(v[0] * v[0] +v[1]*v[1] + v[2] * v[2]);
    v[0] *= a;
    v[1] *= a;
    v[2] *= a;
}
void mouseMotion(int x, int y)
{
    gPrePos = gCurPos;
    gCurPos[kmVector3::kmX] = x;
    gCurPos[kmVector3::kmY] = y;
    gCurPos[kmVector3::KmZ] = 1;
    glutPostRedisplay();
}
void mouseMotion1(int x, int y)
{
    GLfloat curPos[3], dx , dy, dz;
    trackball_ptov(x, y, winWidth,winHeight,curPos);

    if(trackingMouse)
    {
        dx = curPos[0] - lastPos[0];
        dy = curPos[1] - lastPos[1];
        dz = curPos[2] - lastPos[2];
        
        if(dx || dy || dz)
        {
            angle = 90 * sqrt(dx * dx + dy*dy + dz * dz);
            axis[0] = lastPos[1] * curPos[2] - lastPos[2] * curPos[1];
            axis[1] = lastPos[2] * curPos[0] - lastPos[0] * curPos[2];
            axis[2] = lastPos[0] * curPos[1] - lastPos[1] * curPos[0];
            
            lastPos[0] = curPos[0];
            lastPos[1] = curPos[1];
            lastPos[2] = curPos[2];
 
        }
    }
    glutPostRedisplay();
}
void startMotion(int x, int y)
{
    trackingMouse = true;
    redrawContinue = false;
    startx = x;
    startY = y;
    curx = x, cury = y;
    trackball_ptov(x, y, winWidth, winHeight,lastPos);
    trackballMove = true;
}
void stopMotion(int x, int y)
{
    trackingMouse = false;
    if(startx != x || startY != y)
    {
        redrawContinue = true;
    }
    else 
    {
        angle = 0;
        redrawContinue = false;
        trackballMove = false;
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(trackballMove)
    {
        kmVector3 tmpv = CrossProduct(gCurPos,gPrePos);
        glRotatef(2, tmpv[0], tmpv[1], tmpv[2]);
       // glRotatef(angle, 0, 1, 0);
    }
    colorCube();
    glutSwapBuffers();
}
void mouseButton(int button, int state, int x, int y)
{
    if (GLUT_LEFT_BUTTON == button )
        switch(state)
    {
        case GLUT_DOWN:
            gCurPos[kmVector3::kmX] = x;
            gCurPos[kmVector3::kmY] = y;
            gCurPos[kmVector3::KmZ] = 1;
            trackballMove = true;
            break;
        case GLUT_UP:
            trackballMove= false;
            break;
    }
}
void mouseButton1(int button, int state, int x, int y)
{
    if(GLUT_LEFT_BUTTON == button)
    {
        switch (state)
        {
        case GLUT_DOWN:
            y = winHeight - y;
            startMotion(x, y);
            break;
        case GLUT_UP:
            stopMotion(x, y);
            break;
            
        default:
            break;
        }
    }
}
void myReshape(int w, int h)
{
    glViewport(0, 0 , w, h);
    winWidth = w;
    winHeight = h;
}
void spinCube()
{
    if(redrawContinue)
    {
        glutPostRedisplay();
    }
}
#include "KaMiWindowManager.h"
#include "GeMouse.h"

class MyMouseMgr :public IMouseEventMgr
{
public:
    void mouseEvent(kmInt button,kmInt state,kmInt x,kmInt y)
    {
        if (GLUT_LEFT_BUTTON == button )
            switch(state)
        {
            case GLUT_DOWN:
                gCurPos[kmVector3::kmX] = x;
                gCurPos[kmVector3::kmY] = y;
                gCurPos[kmVector3::KmZ] = 1;
                trackballMove = true;
                break;
            case GLUT_UP:
                trackballMove= false;
                break;
        }
    }
};
#include "kmRender.h"
struct MyRender :public kmRender
{
    MyRender(ISrcSurface *src):kmRender(src){}
    void render()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if(trackballMove)
        {
            kmVector3 tmpv = CrossProduct(gCurPos,gPrePos);
            glRotatef(2, tmpv[0], tmpv[1], tmpv[2]);
            // glRotatef(angle, 0, 1, 0);
        }
        colorCube();
        glutSwapBuffers();
    }
};


kmMain()
{
    kmCreateWindow("Includes", 500, 500);
    kmLooping();
    return 0;
}

int main1(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("colorcube");
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    //glutIdleFunc(spinCube);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMotion);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2,-2, 2);
    glMatrixMode(GL_MODELVIEW);
    glutMainLoop();
    return 0;
}
#endif