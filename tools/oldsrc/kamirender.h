#pragma once
#include "kmRender.h"
#include "GeApis.h"
#include "GePoint.h"
#include <vector>
using namespace std;


class KaMiRender :public kmRender
{
public:
    KaMiRender(void);
    ~KaMiRender(void);
    void DrawTetra(const GePoint3D &pt1,const GePoint3D &pt2,const GePoint3D &pt3,const GePoint3D &pt4);
protected:
    void do_render();

    Color gColors[4];
    vector<GePoint3D> GePoints;
};
