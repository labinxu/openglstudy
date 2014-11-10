#include "programer.h"
#include <gl/freeglut.h>
#include "sprite.h"
using namespace Camus;

Programer* Programer::m_programer = NULL;
void Programer::createWindow(const char* wname, int w, int h, int model)
{
    glutInit(&m_argc, m_argv);
    glutInitDisplayMode (model);
    glutInitWindowSize (w, h );
    glutInitWindowPosition (w/2, h/2);
    glutCreateWindow (wname);
    // glutDisplayFunc(display);
    // glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();

}

bool Programer::init(int *cclr)
{
    glClearColor (cclr[0], cclr[1], cclr[2], cclr[3]);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-m_width, m_width, -m_height, m_height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    return true;
}

Programer* Programer::Instance()
{
    if (Programer::m_programer == NULL)
    {
        Programer::m_programer = new Programer();
    }

    return Programer::m_programer;

}

