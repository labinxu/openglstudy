#include <GL/freeglut.h>
#include <iostream>
#include <GL/glu.h>
using namespace std;


void init(int w, int h)
{
    glClearColor (0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w, w, -h, h);
    //glOrtho(-w, w, -h, h, -1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void)
{
    std::cout << "display" << std::endl;
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glColor3f(1, 1, 0);
    glVertex3f(100, 100, 0);
    glEnd();
    glFlush();
}


void reshape (int w, int h)
{
    std::cout<<"reshape"<<std::endl;
    glViewport (0, 0, w, h);
}


void mouse(int button, int state, int x, int y)
{
    std::cout << "mouse" << std::endl;
    GLint viewPort[4];
    GLdouble modelview[16];
    double projection[16];
    float winX, winY, winZ=1;
    double posX, posY, posZ;
    //glPushMatrix();
    glGetIntegerv(GL_VIEWPORT, viewPort);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    //glPopMatrix();
    winX = x;
    winY = viewPort[3] - y;
    glReadPixels(winX, winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
    gluUnProject(winX, winY, 1, modelview, projection, viewPort, &posX, &posY, &posZ);

    std::cout <<"button" << button <<": state "<< state<<std::endl;

    std::cout << "x "<<posX<<" y "<<posY <<" z "<<posZ<< std::endl;
    //glutPostRedisplay();
}

void motion(int x, int y)
{
    std::cout << "motion" << "x "<<x <<" :y "<<y<< std::endl;
    static int pre_x = 0;
    static int pre_y = 0;
    if (pre_x == 0)
    {
        pre_x = x;
        pre_y = y;
        return;
    }
    int diffx = x - pre_x;
    int diffy = y - pre_y;

    pre_x = x;
    pre_y = y;
}

/* ARGSUSED1 */
void keyboard (unsigned char key, int x, int y)
{

}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   // glutKeyboardFunc(keyboard);
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
   init(500, 500);
   glutMainLoop();
   return 0;
}
