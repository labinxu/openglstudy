#include "kmTetra.h"
using namespace KaMi;
kmTetra::kmTetra(const kmVector3 pts[4])
{
    for (int i =0 ; i < 4 ; ++i)
    {
        m_pts[i] = pts[i];
    }
}
#define ColoredVertex(c, v) do{ glColor3fv(c); glVertex3fv(v); }while(0)
GLfloat
ColorR[] = {1, 0, 0},
ColorG[] = {0, 1, 0},
ColorB[] = {0, 0, 1},
ColorY[] = {1, 1, 0};
kmTetra::~kmTetra(void)
{
}
void kmTetra::render()
{
 
    glBegin(GL_TRIANGLES);
    // 平面ABC
    ColoredVertex(ColorR, m_pts[0].data);
    ColoredVertex(ColorG, m_pts[1].data);
    ColoredVertex(ColorB, m_pts[2].data);
    // 平面ACD
    ColoredVertex(ColorR, m_pts[0].data);
    ColoredVertex(ColorB, m_pts[2].data);
    ColoredVertex(ColorY, m_pts[3].data);
    // 平面CBD
    ColoredVertex(ColorB, m_pts[2].data);
    ColoredVertex(ColorG, m_pts[1].data);
    ColoredVertex(ColorY, m_pts[3].data);
    // 平面BAD
    ColoredVertex(ColorG,m_pts[1].data);
    ColoredVertex(ColorR, m_pts[2].data);
    ColoredVertex(ColorY, m_pts[3].data);
    glEnd();
}