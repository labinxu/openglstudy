#if 0
#include <math.h>
#include <gl/glut.h>
#include "kmMathUtil.h"
#include <float.h>
#include <iostream>
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
    glVertex3fv(vertices[a]);
    glVertex3fv(vertices[b]);
    glVertex3fv(vertices[c]);
    glVertex3fv(vertices[d]);
    glEnd();
}

void colorCube()
{
    polygon(1, 0, 3, 2, 0);
    polygon(3, 7, 6, 2, 1);
    polygon(7, 3, 0, 4, 2);
    polygon(2, 6, 5, 1, 3);
    polygon(4, 5, 6, 7, 4);
    polygon(5, 4, 0, 1, 5);
}
static GLfloat theta[] = {0, 0, 0};
static GLint axis = 2;
static GLdouble viewer[] ={0,0,5};
static GLint dist = 5;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // update the viewpoint .
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
   /* gluLookAt(viewer[0],viewer[1],viewer[2], 0, 0, 0, 0, 1, 0);
    glRotatef(theta[0], 1, 0, 0);
    glRotatef(theta[1], 0, 1, 0);
    glRotatef(theta[2], 0, 0, 1);*/
    glRotatef(-45, 1, 0, 0);
    glTranslatef(0,0,-dist);
    colorCube();
    glFlush();
    glutSwapBuffers();
}

void mouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        axis =0;
    }
    else if(btn = GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
    {
        axis =1;
    }
    else if (btn == GLUT_RIGHT_BUTTON &&state == GLUT_DOWN)
    {
        axis =2;
    }

    theta[axis] += 2;
    if (theta[axis] > 360)
    {
        theta[axis] -= 360;
    }
    display();
}
void keys(unsigned char key,int x, int y)
{
    switch (key)
    {
    case 'x':
       // viewer[0] -= 1;
        dist +=1;
        break;
    case 'X':
        //viewer[0] += 1;
        dist -=1;
        break;
    case 'y':
        viewer[1] -= 1;
        break;
    case 'Y':
        viewer[1] += 1;
        break;
    case 'z':
        viewer[2] -= 1;
        break;
    case 'Z':
        viewer[2] += 1;
        break;
    }
    display();
}
void myReshape(int w, int h)
{
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
    {
        glFrustum(-2, 2, -2.0*h/w, 2.0*h/w, 2, 20);
    }
    else
    {
        glFrustum(-2, 2, - 2* w /h, -2.0 * w / h, 2, 20);
    }
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("colorcube");
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keys);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
#endif