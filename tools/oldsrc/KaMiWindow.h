#pragma once

#include <map>
#include "KaMiObject.h"
#include "GeWindow.h"
#include "Types.h"

namespace KaMi{

class kmRender;
class kmScrSurface : public ISrcSurface
{
public:
    kmScrSurface(const WindowData &windata);
    ~kmScrSurface(void);

public:
    kmObjectId addObject(kmObject *pObj);
    void setHeight(kmInt32 height);
    void setWidth(kmInt32 width);
    void moveTo(const GePoint2D& pos);
    void show();
    void setRender(const kmRender*){};
    void setClearColor(const kmColor& cor);
    void onUpdate();
    void onDraw();
private:
    std::map<kmObjectId,kmObject*> m_kmObjects;
    WindowData m_winData;

    kmObjectId tmpid;
};
}