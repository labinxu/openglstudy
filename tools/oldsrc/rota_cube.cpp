#if 0
#include <gl/glut.h>
#include <cstdlib>
#include <Windows.h>
GLfloat vertices[] = {
    -1, -1, -1, 1, -1,-1,
    1, 1,-1, -1, 1, -1, -1, -1, 1,
    1, -1, 1, 1, 1, 1, -1, 1, 1
};

GLfloat colors[] =
{
    0, 0, 0, 1, 0, 0,
    1, 1, 0, 0, 1, 0, 0, 0, 1,
    1, 0, 1, 1, 1, 1, 0, 1, 1
};

GLubyte cubeIndices[] =
{
    0, 3, 2, 1, 2, 3, 7, 6, 0, 4,7,3,1,2,6,5,4,5,6,7,0,1,5,4
};

static GLfloat theta[] = {0,0,0};
static GLint axis = 2;


void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta[0], 1, 0, 0);
    glRotatef(theta[1], 0, 1, 0);
    glRotatef(theta[2], 0, 0, 1);
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 1, 1);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

void spinCube()
{
    Sleep(50);
    theta[axis] += 2;
    if(theta[axis] > 360 ){
        theta[axis] -= 360;
    }
    glutPostRedisplay();
}

void mouse(int button,int state,int x, int y){

    if(GLUT_LEFT_BUTTON == button && GLUT_DOWN == state){
        axis = 0;
    }
    if (GLUT_MIDDLE_BUTTON == button && GLUT_DOWN == state)
    {
        axis = 1;
    }
   
 if (GLUT_RIGHT_BUTTON == button && GLUT_DOWN == state)
    {
        axis = 2;
    }
}

void myReshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w > h){
        glOrtho(-2, 2, -2* h / w, 2 *h / w, -10, 10);
    }
    else{
        glOrtho(-2*w/h, 2 * w / h, -2,2, -10, 10);
    }
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("colorcube");
    glutDisplayFunc(Display);
    glutReshapeFunc(myReshape);
    glutIdleFunc(spinCube);
    glutMouseFunc(mouse);
    glEnable(GL_DEPTH_TEST);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glRenderMode(GL_FLAT);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glColor3f(1, 1, 1);
    glutMainLoop();
        
}
#endif
