#ifndef Ge_RENDER_H_
#define Ge_RENDER_H_
#include "Types.h"
namespace KaMi
{

class ISrcSurface;
class kmRender
{
public:
    kmRender(ISrcSurface* pwin);
    virtual void render();
    void setClearColor(const kmColor &cor);
private:
    ISrcSurface *m_pWin;
    kmColor m_cCr;
};

}
#endif