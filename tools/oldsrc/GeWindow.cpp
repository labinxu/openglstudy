#include "GeWindow.h"
#include "KaMiWindowManager.h"
#include "kmRender.h"
#include "GeMouse.h"
#include "IUpdater.h"
using namespace KaMi;

ISrcSurface::ISrcSurface():
m_pRender(NULL),
m_pMouseMgr(NULL),
m_pUpdater(NULL){

}

void ISrcSurface::RenderEvent()
{
    kmWindowManager* pMgr = kmWindowManager::getInstnce();
    if (NULL != pMgr)
    {
         pMgr->getActiveWindow().render();
    }
}

void ISrcSurface::setRender( kmRender* render)
{
    m_pRender = render;
}

void ISrcSurface::setMouseEventMgr(IMouseEventMgr *pMouseMgr)
{
    m_pMouseMgr = pMouseMgr;
}

void ISrcSurface::render()
{
    m_pRender->render();
}

void ISrcSurface::MouseEvent( kmInt32 button,kmInt32 state,kmInt32 x, kmInt32 y )
{
    kmWindowManager* pMgr = kmWindowManager::getInstnce();
    if (NULL != pMgr)
    {
        pMgr->getActiveWindow().mouseEvent(button, state, x, y);
    }
}

void ISrcSurface::mouseEvent( kmInt32 button,kmInt32 state,kmInt32 x,kmInt32 y )
{
    m_pMouseMgr->mouseEvent(button, state, x, y);
}

void ISrcSurface::Update()
{
    kmWindowManager* pMgr = kmWindowManager::getInstnce();
    if (NULL != pMgr)
    {
        pMgr->getActiveWindow().onUpdate();
    }
}

void KaMi::ISrcSurface::Draw()
{
    kmWindowManager* pMgr = kmWindowManager::getInstnce();
    if (NULL != pMgr)
    {
        pMgr->getActiveWindow().onDraw();
    }
}
