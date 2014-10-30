#pragma once
#include <string>
#include "Types.h"
#include "GePoint.h"
#include "GeWindow.h"

namespace KaMi{
class IWindowManager
{
public:
    IWindowManager();
    IWindowManager(int &argc,char **argv);
    virtual ~IWindowManager(void);
    virtual ISrcSurface& getActiveWindow() = 0;
public:
    virtual ISrcSurface* createWindow(const WindowData &windata) = 0;

};

}
