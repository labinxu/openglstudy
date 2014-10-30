#ifndef IGEOMETRY_H_
#define IGEOMETRY_H_
namespace KaMi
{
    class IGeometry
    {
    public:
        virtual ~IGeometry(){}
        virtual void addVertices();
    };
}
#endif