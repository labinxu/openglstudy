#ifndef POLYGON_H_
#define POLYGON_H_

#include "IObject.h"
namespace KaMi
{
    class IGeometry;
    class kmPolygon : public IObject
    {
    public:
        kmPolygon(void);
        ~kmPolygon(void);
    public:
        void draw();
        void onUpdate();
    private:
        IGeometry *m_pGeometry;
    };
}

#endif