#include "KaMiWindow.h"
#include "kmRender.h"
#include <gl/glut.h>
#include "GeApis.h"
#include "GeMouse.h"

using namespace KaMi;
kmScrSurface::kmScrSurface(const WindowData &windata)
:m_winData(windata),tmpid(0)
{
   setMouseEventMgr(new IMouseEventMgr);
   glutInitDisplayMode (m_winData.winDisplayMode);
   glutInitWindowPosition(m_winData.winPosition.x,m_winData.winPosition.y);
   glutInitWindowSize (m_winData.winWidth,m_winData.winHeight);
   glutCreateWindow(m_winData.winName.c_str());

   typedef void(*RenderFn)();
   RenderFn fn = ISrcSurface::RenderEvent;

   glutDisplayFunc(fn);
   //glutReshapeFunc(KaMiReshapeFnPtr);

   typedef void (*MouseMgr)(kmInt32,kmInt32,kmInt32,kmInt32);
   MouseMgr mouseEv = ISrcSurface::MouseEvent;
   glutMouseFunc(mouseEv);

}

kmScrSurface::~kmScrSurface(void)
{

}

void kmScrSurface::setHeight( kmInt32 height )
{
    m_winData.winHeight = height;
}
void kmScrSurface::setWidth(kmInt32 width)
{
    m_winData.winWidth = width;
}

void kmScrSurface::moveTo(const GePoint2D& pos)
{
    m_winData.winPosition = pos;
}

void kmScrSurface::show()
{
   // glutIdleFunc(Idle);
    glutMainLoop();
}

void kmScrSurface::onUpdate()
{
    for (std::map<kmObjectId,kmObject*>::iterator it = m_kmObjects.begin(); it != m_kmObjects.end(); ++it)
    {
        it->second->onUpdate();
    }
}

void KaMi::kmScrSurface::onDraw()
{
    for (std::map<kmObjectId,kmObject*>::iterator it = m_kmObjects.begin(); it != m_kmObjects.end(); ++it)
    {
        it->second->draw();
    }

  
}

void KaMi::kmScrSurface::setClearColor( const kmColor& cor )
{
    m_pRender->setClearColor(cor);
}

kmObjectId kmScrSurface::addObject(kmObject *pObj)
{
    m_kmObjects.insert(std::make_pair(++tmpid,pObj));
    return tmpid;
}