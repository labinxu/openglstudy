#include "KaMiWindowManager.h"
#include "KaMiWindow.h"
#include "kmRender.h"
#include <gl/glut.h>

using namespace KaMi;
kmWindowManager* kmWindowManager::m_pWindowsManager = NULL;
kmWindowManager::kmWindowManager(void):m_pActiveWindow(NULL)
{
}

kmWindowManager::kmWindowManager( int &argc,char**argv ):m_pActiveWindow(NULL)
{
    glutInit(&argc,argv);
}

kmWindowManager::~kmWindowManager(void)
{

}
ISrcSurface* kmWindowManager::createWindow(const WindowData &windata)
{
    std::pair<const std::map<kmObjectId,ISrcSurface*>::iterator,bool > poser = m_windows.insert(std::make_pair(m_windows.size()+1,new kmScrSurface(windata)));
    if (!poser.second)
    {
        //error
    }
    m_pActiveWindow = poser.first->second;
    m_pActiveWindow->setRender(new kmRender(m_pActiveWindow));
    m_pActiveWindow->setClearColor(kmColor(1,1,1,1));
    return m_pActiveWindow;
}

kmWindowManager* kmWindowManager::Instance(int &argc,char** argv )
{
    if (NULL == m_pWindowsManager)
    {
        m_pWindowsManager = new kmWindowManager(argc,argv);
    }
    return m_pWindowsManager;
}

kmWindowManager* kmWindowManager::getInstnce()
{
    return m_pWindowsManager;
}

ISrcSurface& kmWindowManager::getActiveWindow()
{
    return *m_pActiveWindow;
}
