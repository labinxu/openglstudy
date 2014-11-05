#include "god.h"
#include <gl/freeglut.h>

using namespace Camus;


void God::createWindow(int w, int h, int model)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (model);
    glutInitWindowSize (w, h );
    glutInitWindowPosition (w/2, h/2);
    glutCreateWindow (argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    // glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    init(500, 500);
    glutMainLoop();

}
