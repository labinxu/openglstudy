#if 0
#include "kmViewer.h"
#include "kmTetra.h"
#include "kmStageFactory.h"
using namespace KaMi;

int main(int argc,char** argv)
{
    kmViewer *myViewer = new kmViewer;
    myViewer->init(argc,argv);
    myViewer->createWin("GRID_MAP", 500, 500);
    kmStageFactory *stageFactory = kmStageFactory::instance();
  
    myViewer->show(stageFactory);
    return 0;

}

#endif