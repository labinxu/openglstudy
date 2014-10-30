#if 0

#include <gl/glut.h>
#include <cstdio>
#include <cstdlib>
#include "KaMiWindowManager.h"
#include "Vector3.h"

using namespace KaMi;
class kmRect : public kmObject
{
public:
    kmRect(const kmVector3& ptLb,const kmVector3 & ptRt):m_leftbt(ptLb),m_rightbt(ptRt){}
    void draw()
    {
        glColor3f(m_color.R,m_color.G,m_color.B);
        glBegin(GL_LINE_LOOP);
        //glRectf(m_leftbt.x,m_leftbt.y,m_rightbt.x,m_rightbt.y);
        glVertex2f(m_leftbt.x,m_leftbt.y);
        glVertex2f(m_leftbt.x,m_rightbt.y);
        glVertex2f(m_rightbt.x,m_rightbt.y);
        glVertex2f(m_rightbt.x,m_leftbt.y);
        glEnd();
    }
    void show()
    {
        glFlush();
    }
    void onUpdate()
    {
        static int i =0;
        if (i==0)
        {
            draw();
        }
    }
private:
    kmVector3 m_leftbt;
    kmVector3 m_rightbt;
};
int main(int argc,char**argv)
{
    kmWindowManager *pWndMgr = kmWindowManager::Instance(argc,argv);
    WindowData data;
    data.winDisplayMode = GLUT_SINGLE |GLUT_RGB;
    data.winHeight = 500;
    data.winWidth = 500;
    data.winName = argv[0];
    ISrcSurface *pwin = pWndMgr->createWindow(data);
    pwin->addObject(new kmRect(kmVector3(-25,-25),kmVector3(25,25)));
    //pwin->setClearColor(kmColor(1,1,1));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50,50,-50,50);
    glMatrixMode(GL_MODELVIEW);
    /*glShadeModel(GL_FLAT);*/
    pwin->show();
    return 0;
}
#endif