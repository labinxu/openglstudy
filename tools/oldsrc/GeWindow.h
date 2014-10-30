
#ifndef GEWINDOW_H_
#define GEWINDOW_H_

#include <string>
#include "GePoint.h"

struct WindowData
{
    WindowData(const std::string& name ,kmInt32 width,kmInt32 height,unsigned int disMod,const GePoint2D &pos)
        :winName(name),
        winWidth(width),
        winHeight(height),
        winDisplayMode(disMod),
        winPosition(pos)
    {

    }

    WindowData(){}

    unsigned int winDisplayMode;
    std::string winName;
    kmInt32 winWidth;
    kmInt32 winHeight;
    GePoint2D winPosition;
};
namespace KaMi{

class kmRender;
class IMouseEventMgr;
class IUpdater;
class kmObject;
class ISrcSurface
{
public:
    ISrcSurface();
    virtual ~ISrcSurface() {}
protected:
    void render();
    void mouseEvent(kmInt32 button,kmInt32 state,kmInt32 x,kmInt32 y);
public:
    
    virtual void moveTo(const GePoint2D& pos) = 0;
    //virtual void setDispMod( );
    virtual void setWidth(kmInt32 width) = 0;
    virtual void setHeight(kmInt32 height) = 0;
    virtual void show() = 0;
    virtual void onUpdate() = 0 ;
    virtual void onDraw() = 0;
    virtual kmObjectId addObject(kmObject *pObj) = 0;
    virtual void setClearColor(const kmColor &color) = 0;
public:
    void setRender( kmRender*);
    void setMouseEventMgr(IMouseEventMgr *);
protected:
    static void RenderEvent();
    static void ReshapeEvent(kmInt32 x,kmInt32 y);
    static void MouseEvent(kmInt32 button,kmInt32 state,kmInt32 x, kmInt32 y);
    static void Update();
    static void Draw();
protected:
    kmRender *m_pRender;
    IMouseEventMgr *m_pMouseMgr;
    IUpdater *m_pUpdater;
};

}
#endif