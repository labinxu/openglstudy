#include <iostream>
#include "../tools/src/programer.h"
#include "../tools/src/player.h"
#define  GLUT_RGB                           0x0000
#define  GLUT_RGBA                          0x0000
#define  GLUT_INDEX                         0x0001
#define  GLUT_SINGLE                        0x0000
#define  GLUT_DOUBLE                        0x0002
#define  GLUT_ACCUM                         0x0004
#define  GLUT_ALPHA                         0x0008
#define  GLUT_DEPTH                         0x0010
#define  GLUT_STENCIL                       0x0020
#define  GLUT_MULTISAMPLE                   0x0080
#define  GLUT_STEREO                        0x0100
#define  GLUT_LUMINANCE                     0x0200
using namespace Camus;

int main(int argc, char **argv)
{

    Programer* pg = Programer::Instance();
    int clearColor[]={0, 0, 0, 0};
    pg->init(argc, argv, clearColor, GLUT_SINGLE|GLUT_RGB, 400, 400);
    Player* sp = pg->create<Player>();
    Register<Keyboard>::Regist(sp);
    Register<Mouse>::Regist(sp);
    Register<Motion>::Regist(sp);
    Point pt1(100, 100);
    Point pt2(-100, -100);
    pg->addToDrawer(new Line(pt1, pt2));
    pg->createWindow("OpenGL Window");
    return 0;

}
