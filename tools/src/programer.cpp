#include "programer.h"
#include "sprite.h"
#include <gl/freeglut.h>
#include <iostream>
using namespace Camus;

Programer* Programer::m_programer = NULL;
void display()
{
}
void reshape(int ,int)
{}
void Programer::init(int argc, char **argv,
              int *cclr, int displaymodel,
              int w, int h)
{
    m_argc = argc;
    m_argv = argv;
    m_width = w;
    m_height = h;
    m_cclr = cclr;
    m_displayModel = displaymodel;
}

void Programer::createWindow(const char* wname)
{
    glutInit(&m_argc, m_argv);
    glutInitDisplayMode (m_displayModel);
    glutInitWindowSize (m_width, m_height );
    // glutInitWindowPosition (w/2, h/2);
    glutCreateWindow(wname);
    this->init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}

void Programer::init()
{
    glClearColor (m_cclr[0], m_cclr[1], m_cclr[2], m_cclr[3]);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-m_width, m_width, -m_height, m_height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

Programer* Programer::Instance()
{
    if (Programer::m_programer == NULL)
    {
        Programer::m_programer = new Programer();
    }

    return Programer::m_programer;

}

void Camus::keyboard (unsigned char key, int x, int y)
{
    std::cout<<"keyboard"<<std::endl;
    Programer* pg = Programer::Instance();
    for(auto it = pg->_keyboardReceivers.begin();
        it != pg->_keyboardReceivers.end();
        ++it)
    {
        (*it)(key, x, y);
    }
    return;
}

void Camus::motion(int x, int y)
{
    std::cout<<"MOTION"<<std::endl;
    return;
    Programer* pg = Programer::Instance();
    for (auto iter = pg->motionReceiversBegin();
         iter != pg->motionReceiversEnd(); ++iter) {
        (*iter)->motion(x, y);
    }
}

void Camus::mouse(int bt, int state, int x, int y)
{
    Programer* pg = Programer::Instance();
    for (auto iter = pg->_mouseReceivers.begin();
         iter != pg->_mouseReceivers.end(); ++iter){
        (*iter)(bt, state, x, y);
    }

}

