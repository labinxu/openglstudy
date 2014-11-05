#ifndef GOD_H
#define GOD_H



namespace Camus
{
void InitProgramer(int argc, char **argv)
{
    Programer::Instance()->init(argc, argv);
}


class Programer
{
  public:
    void createWindow(int w, int h, int model);
    void init(int* cclr);

    static Programer* Instance();
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
};


};
#endif /* GOD_H */
