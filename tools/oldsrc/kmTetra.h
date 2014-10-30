#ifndef KM_TETRA_H
#define KM_TETRA_H
#include <kmGeometry.h>
#include <kmVector3d.h>
namespace KaMi{

class kmTetra : public kmGeometry
{
public:
    kmTetra(const kmVector3 pts[4]);
    ~kmTetra(void);
public:
    void render();
private:
    kmVector3 m_pts[4];
};

}
#endif
