#include "kmMainIncludes.h"
#include "KaMiWindowManager.h"
#include "includes.h"

using namespace KaMi;

kmWindowManager *gpWndMgr;

void KaMi::kmInitKaMi(int argc,char**argv)
{
     kmWindowManager::Instance(argc,argv);
    
}

void KaMi::kmCreateWindow( const char*szName,kmInt32 width,kmInt32 height )
{
    WindowData data;
    data.winDisplayMode = GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH;
    data.winHeight = width;
    data.winWidth = height;
    data.winName = szName;

    kmWindowManager::getInstnce()->createWindow(data);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2,-2, 2);
    glMatrixMode(GL_MODELVIEW);
}

void KaMi::kmLooping()
{
    glutMainLoop();
}
