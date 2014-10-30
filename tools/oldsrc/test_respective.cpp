#if 1
#include <gl/glut.h>
#include "kmCamera.h"
#include <kmMatrix.h>
#include <iostream>
#include <kmViewer.h>
using namespace KaMi;
void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    glBegin(GL_LINES);
    glVertex3f(-1000,0,0);
    glVertex3f(1000,0,0);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0,1000,0);
    glVertex3f(0,-1000,0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(20.0f, 0.0f, 0.0f );
    glVertex3f( 20.0f, 20.0f, 0.0f); 
    glVertex3f( 00.0f, 20.0f, 0.0f);   
    glEnd();
    glFlush();

}
static void cross(GLfloat v1[3], GLfloat v2[3], GLfloat result[3])
{
    result[0] = v1[1]*v2[2] - v1[2]*v2[1];
    result[1] = v1[2]*v2[0] - v1[0]*v2[2];
    result[2] = v1[0]*v2[1] - v1[1]*v2[0];
}
static void normalize(GLfloat v[3])
{
    GLfloat r;

    r=(GLfloat)sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    if (r==0.0f)
    {
        return;
    }

    v[0]/=r;
    v[1]/=r;
    v[2]/=r;
}
static void __gluMakeIdentityf(GLfloat m[16])
{
    m[0+4*0] = 1; m[0+4*1] = 0; m[0+4*2] = 0; m[0+4*3] = 0;
    m[1+4*0] = 0; m[1+4*1] = 1; m[1+4*2] = 0; m[1+4*3] = 0;
    m[2+4*0] = 0; m[2+4*1] = 0; m[2+4*2] = 1; m[2+4*3] = 0;
    m[3+4*0] = 0; m[3+4*1] = 0; m[3+4*2] = 0; m[3+4*3] = 1;
}
void lookAt(GLfloat eyex, GLfloat eyey, GLfloat eyez,
       GLfloat centerx, GLfloat centery, GLfloat centerz,
       GLfloat upx, GLfloat upy, GLfloat upz)
{
    GLfloat forward[3], side[3], up[3];
    GLfloat m[4][4];

    forward[0] = centerx - eyex;
    forward[1] = centery - eyey;
    forward[2] = centerz - eyez;

    up[0] = upx;
    up[1] = upy;
    up[2] = upz;

    normalize(forward);

    /* Side = forward x up */
    cross(forward, up, side);
    normalize(side);

    /* Recompute up as: up = side x forward */
    cross(side, forward, up);

    __gluMakeIdentityf(&m[0][0]);
    m[0][0] = side[0];
    m[1][0] = side[1];
    m[2][0] = side[2];

    m[0][1] = up[0];
    m[1][1] = up[1];
    m[2][1] = up[2];

    m[0][2] = -forward[0];
    m[1][2] = -forward[1];
    m[2][2] = -forward[2];

    glMultMatrixf(&m[0][0]);
    glTranslatef(-eyex, -eyey, -eyez);
}


kmFloat m_focusDist;
kmFloat m_width;
kmFloat m_height;
kmMatrix m;
void  setUpPerspectiveProjection(kmFloat m_near_clip_dist,kmFloat m_far_clip_dist)
{
    
    float inv_sub = 1.0f / (m_far_clip_dist - m_near_clip_dist);

    m[0] = m_focusDist * 2.0f / m_width;
    m[4] = 0.0f;
    m[8] = 0.0f;
    m[12] = 0.0f;

    m[1] = 0.0f;
    m[5] = m_focusDist * 2.0f / m_height;
    m[9] = 0.0f;
    m[13] = 0.0f;

    m[2] = 0.0f;
    m[6] = 0.0f;
    m[10] = (m_far_clip_dist + m_near_clip_dist) * inv_sub;
    m[14] = 2.0f * m_far_clip_dist * m_near_clip_dist * inv_sub;

    m[3] = 0.0f;
    m[7] = 0.0f;
    m[11] = -1.0f;
    m[15] = 0.0f;
}

void mouse(int button,int state,int x,int y)
{
    p.viewToProj(x,y);
    std::cout<<"x = " <<x<<"y = "<<y<<std::endl;
}

void init()
{
    m_width =400;
    m_height = 400;
    m_focusDist =500;
    setUpPerspectiveProjection(1,1000);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int a =10;// 定义大小
   // glFrustum(-a,a,-a,a,199,200);
    gluPerspective(90,1,1,1000);
    //gluOrtho2D(-50,50,-50,50);
    glMatrixMode(GL_MODELVIEW);
    lookAt(0,0,500,0,0,0,0,1,0);
    
    kmVector3 p1(20,20,0);
    p1 = p1.toGlobleFrom(m);

}
int main(int argc,char**argv)
{
    glutInit(&argc, argv); 
    
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB |GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize (500, 500);
    glutCreateWindow (argv[0]);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
        init();
    glMatrixMode(GL_MODELVIEW);
    glutMainLoop();
    return 0;
}



#endif