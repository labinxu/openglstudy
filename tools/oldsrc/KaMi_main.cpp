#if 0
#include "KaMiWindowManager.h"
#include "KaMiRender.h"

int main(int argc,char** argv)
{
    WindowManager *pWinManager = KaMiWindowManager::Instance(argc,argv);
    WindowData winData("KaMiWindow",500,500,GLUT_SINGLE|GLUT_RGB |GLUT_DEPTH,GePoint2D(0.0,0.0));
    winData.winName = "KamiWindow";
   
    GeWindow *pWin = pWinManager->createWindow(winData);
    pWin->setRender(new KaMiRender);
    pWin->setBlankgroundColor(0.0,1.0,0.0);
    pWin->moveTo(GePoint2D(200,200));
    glClearColor(0.0, 0.0, 0.0, 1.0);
    pWin->show();
}

#endif