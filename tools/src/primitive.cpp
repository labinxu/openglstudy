#include "primitive.h"
#include <assert.h>
#include <gl/gl.h>
#include <iostream>


using namespace Camus;
Drawer *GlobalDrawer=NULL;
void InitDrawer(Drawer*drawer)
{
    GlobalDrawer = drawer;
    std::cout<<"init drawer initialize"<<std::endl;
}


