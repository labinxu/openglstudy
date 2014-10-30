#include "KaMiRender.h"
#include <gl/GLut.h>

KaMiRender::KaMiRender(void)
{
    GePoints.push_back(GePoint3D(0.0, 0.0, 1.0));
    GePoints.push_back(GePoint3D(0.0, 0.942809, -0.33333));
    GePoints.push_back(GePoint3D(-0.816497,-0.471405, -0.33333));
    GePoints.push_back(GePoint3D(0.816497, -0.471405, 0.33333));

    gColors[0] = Color(1.0,0.0,0.0);
    gColors[1] = Color(0.0, 1.0 ,0.0);
    gColors[2] = Color(0.0, 0.0, 1.0);
    gColors[2] = Color(0.0, 0.0, 0.0);
}

KaMiRender::~KaMiRender(void)
{
}

void KaMiRender::DrawTetra(const GePoint3D &pt1,const GePoint3D &pt2,const GePoint3D &pt3,const GePoint3D &pt4)
{
    DrawTriangle(pt1, pt2, pt3, gColors[0]);
    DrawTriangle(pt1, pt3, pt4, gColors[1]);
    DrawTriangle(pt1, pt4, pt2, gColors[2]);
    DrawTriangle(pt2, pt4, pt3, gColors[3]);
}
void KaMiRender::do_render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
         DrawTetra(GePoints[0], GePoints[1], GePoints[2], GePoints[3]);
    glEnd();
    glFlush();
}
