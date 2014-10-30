#include "kmRender.h"
#include "GeWindow.h"
#include <gl/GLut.h>
using namespace KaMi;

kmRender::kmRender( ISrcSurface* pwin )
:m_pWin(pwin),m_cCr(1,1,1,1)
{
}

void KaMi::kmRender::render()
{
    if (0 != m_pWin)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        m_pWin->onUpdate();
        glFlush();
    }
}

void KaMi::kmRender::setClearColor(const kmColor &cor)
{ 
    m_cCr = cor;
    glClearColor(m_cCr.R,m_cCr.G,m_cCr.B,m_cCr.A);
   
}
