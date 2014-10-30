#include "GeApis.h"
#include <gl/glut.h>

//namespace Ge
//{
void DrawPoint(const GePoint3D& point)
{
    glBegin(GL_POINTS);
    glColor3f(point.x / 250 , point.y /250, point.z /250);
    glVertex3f(point.x,point.y,point.z);
    glEnd();
}

void Triangel(const GePoint3D &pt1,const GePoint3D &pt2,const GePoint3D &pt3)
{
    glVertex3f(pt1.x, pt1.y, pt1.z);
    glVertex3f(pt2.x, pt2.y, pt2.z);
    glVertex3f(pt3.x, pt3.y, pt3.z);
}

void DrawTriangle( const GePoint3D &pt1,const GePoint3D &pt2,const GePoint3D &pt3,const Color &cor )
{
    glColor3f(cor.R,cor.G,cor.B);
    Triangel(pt1,pt2,pt3);
}

void DrawLine( const GePoint3D& pt1,const GePoint3D& pt2,const Color &cor)
{
    glColor3f(cor.R,cor.G,cor.B);
    glBegin(GL_LINE);
    glVertex3f(pt1.x,pt1.y,pt1.z);
    glVertex3f(pt2.x,pt2.y,pt2.z);
    glEnd();
}



//}