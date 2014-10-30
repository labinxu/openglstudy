#pragma once
#include <map>
#include <gl/glut.h>
#include "windowsmanager.h"
#include "KaMiWindow.h"
namespace KaMi{
class ISrcSurface;

class kmWindowManager :public IWindowManager
{
public:

    static kmWindowManager* Instance(int &argc,char** argv);
    static kmWindowManager* getInstnce();
public:
    ISrcSurface* createWindow(const WindowData &windata);
    ISrcSurface& getActiveWindow();
private: 
    kmWindowManager(void);
    kmWindowManager(int &argc,char**argv);
    ~kmWindowManager(void);
private:
    std::map<kmObjectId,ISrcSurface*> m_windows;
    static kmWindowManager* m_pWindowsManager;

private:
    ISrcSurface *m_pActiveWindow;
};
}
