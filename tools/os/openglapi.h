#ifndef OPENGLAPI_H
#define OPENGLAPI_H
#include <gl/gl.h>

namespace Camus
{

template<class Iterator>
inline void draw_polygon(Iterator beg, Iterator end)
{
    glBegin(GL_LINE_LOOP);
    for (; beg != end; ++beg) {
        glVertex3fv(beg->data());
    }
    glEnd();
}

template<class Iterator>
inline void draw_line(Iterator beg, Iterator end)
{
    glBegin(GL_LINES);
    for (; beg != end; ++beg) {
        glVertex3fv(beg->data());
    }
    glEnd();
}

}



#endif /* OPENGLAPI_H */
