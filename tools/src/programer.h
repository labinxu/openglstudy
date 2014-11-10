#ifndef PROGRAMER_H
#define PROGRAMER_H
#include <vector>
#include "sprite.h"


namespace Camus
{


class Programer
{
  public:
    void createWindow(const char *wname, int w, int h, int model);
    bool init(int* cclr);
    std::vector<Sprite*>::iterator mouseReceiversBegin()
    {
        return m_mouseReceivers.begin();
    }
    std::vector<Sprite*>::iterator mouseReceiversEnd()
    {
        return m_motionReceivers.end();
    }

    std::vector<Sprite*>::iterator motionReceiversBegin()
    {
        return m_motionReceivers.begin();
    }
    std::vector<Sprite*>::iterator motionReceiversEnd()
    {
        return m_motionReceivers.end();
    }

    std::vector<Sprite*>::iterator keyboardReceiversBegin()
    {
        return m_keyboardReceivers.begin();
    }
    std::vector<Sprite*>::iterator keyboardReceiversEnd()
    {
        return m_keyboardReceivers.end();
    }

    static Programer* Instance();
  private:
    Programer(){}
    Programer(const Programer&);
    Programer* operator=(const Programer&);
  protected:
    bool init(int argc, char **argv)
    {
        m_argc = argc;
        m_argv = argv;
    }
  protected:
    int m_height;
    int m_width;
    static Programer *m_programer;
    int m_argc;
    char **m_argv;

    std::vector<Sprite*> m_mouseReceivers;
    std::vector<Sprite*> m_motionReceivers;
    std::vector<Sprite*> m_keyboardReceivers;
};


void keyboard (unsigned char key, int x, int y)
{
    Programer* pg = Programer::Instance();
    for (auto iter = pg->keyboardReceiversBegin();
         iter != pg->keyboardReceiversEnd(); ++iter) {
        (*iter)->keyboard(key, x, y);
    }
}

void motion(int x, int y)
{
    Programer* pg = Programer::Instance();
    for (auto iter = pg->motionReceiversBegin();
         iter != pg->motionReceiversEnd(); ++iter) {
        (*iter)->motion(x, y);
    }
}

void mouse(int bt, int state, int x, int y)
{
    Programer* pg = Programer::Instance();
    for (auto iter = pg->mouseReceiversBegin();
         iter != pg->mouseReceiversEnd(); ++iter) {
        (*iter)->mouse(bt, state, x, y);
    }

}
};

#endif
