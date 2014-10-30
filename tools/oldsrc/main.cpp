#if 0

#include <gl/glut.h>
//#include <boost/assign.hpp>
#include "GePoint.h"
#include "GeApis.h"

#include <vector>
using namespace std;

//using namespace Ge;

Color gColors[4];
vector<GePoint3D> GePoints;
void Divide_Tetra(const GePoint3D &pt1,const GePoint3D &pt2,const GePoint3D &pt3,const GePoint3D &pt4 ,int m);
void DrawTetra(const GePoint3D &pt1,const GePoint3D &pt2,const GePoint3D &pt3,const GePoint3D &pt4)
{
    DrawTriangle(pt1, pt2, pt3, gColors[0]);
    DrawTriangle(pt1, pt3, pt4, gColors[1]);
    DrawTriangle(pt1, pt4, pt2, gColors[2]);
    DrawTriangle(pt2, pt4, pt3, gColors[3]);
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    Divide_Tetra(GePoints[0], GePoints[1], GePoints[2], GePoints[3],4);
   // DrawTetra(GePoints[0], GePoints[1], GePoints[2], GePoints[3]);
    glEnd();
    glFlush();

}

void Divide_Tetra(const GePoint3D &pt1,const GePoint3D &pt2,const GePoint3D &pt3,const GePoint3D &pt4 ,int m)
{
    GePoint3D mid[6];
    if (m > 0)
    {
        mid[0] = (pt1 + pt2) / 2;
        mid[1] = (pt1 + pt3) / 2;
        mid[2] = (pt1 + pt4) / 2;
        mid[3] = (pt2 + pt3) / 2;
        mid[4] = (pt3 + pt4) / 2;
        mid[5] = (pt2 + pt4) / 2;

        Divide_Tetra(pt1, mid[0], mid[1], mid[2], m-1);
        Divide_Tetra(mid[0], pt2, mid[3], mid[5], m-1);
        Divide_Tetra(mid[1], mid[3], pt3, mid[4], m-1);
        Divide_Tetra(mid[2], mid[4], pt4, mid[5], m-1);
        
    }
    else
    {
        DrawTetra(pt1, pt2, pt3, pt4);
    }

}

void init (void)
{
    GePoints.push_back(GePoint3D(0.0, 0.0, 1.0));
    GePoints.push_back(GePoint3D(0.0, 0.942809, -0.33333));
    GePoints.push_back(GePoint3D(-0.816497,-0.471405, -0.33333));
    GePoints.push_back(GePoint3D(0.816497, -0.471405, 0.33333));
    
    gColors[0] = Color(1.0,0.0,0.0);
    gColors[1] = Color(0.0, 1.0 ,0.0);
    gColors[2] = Color(0.0, 0.0, 1.0);
    gColors[2] = Color(0.0, 0.0, 0.0);


    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //gluOrtho2D(-2.0,2.0,-2.0,2.0);
    //glMatrixMode(GL_MODELVIEW);
    //glClearColor (0.0, 0.0, 0.0, 0.0);
    //glColor3f(0.0, 0.0, 0.0);
   
}
void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    if(w <= h)
    {
        glOrtho(-1.0, 1.0, -1.0 * h/w, 1.0*w/h,  -100, 100.0);
    }
    else
    {
        glOrtho( -1.0 * w / h, 1.0 * w / h, -1.0, 1.0, -100, 100.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}
int main(int argc,char**argv)
{
    glutInit(&argc, argv); 
    glutCreateWindow (argv[0]);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB |GLUT_DEPTH);

    glutInitWindowSize (500, 500);
   
    init();
    glutDisplayFunc(display);
   
  //  glutReshapeFunc(reshape);
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutMainLoop();
    return 0;
}



#endif
