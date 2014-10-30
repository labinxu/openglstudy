#if 0

#include <kmGLUTViewer.h>
#include <kmLine.h>
#include <iostream>
#include "kmTetra.h"
#include "kmLight.h"

using namespace KaMi;

 
int main(int argc, char **argv)
{

    kmViewer *myViewer = new kmViewer;
    myViewer->init(argc,argv);
    myViewer->createWin("hello gl", 500, 500);
    kmGeVector3d pts[4] =
    {
        kmGeVector3d(0.5f, -sqrt(6.0f)/12, -sqrt(3.0f)/6),
        kmGeVector3d(-0.5f, -sqrt(6.0f)/12, -sqrt(3.0f)/6),
        kmGeVector3d(0.0f, -sqrt(6.0f)/12,   sqrt(3.0f)/3),
        kmGeVector3d(0.0f,    sqrt(6.0f)/4,              0)
    };
    kmGeVector3d pts1[4] =
    {
        kmGeVector3d(1.0f, -sqrt(6.0f)/6, -sqrt(3.0f)/3),
        kmGeVector3d(-1.0f, -sqrt(6.0f)/6, -sqrt(3.0f)/3),
        kmGeVector3d(0.5f, -sqrt(6.0f)/6,   sqrt(3.0f)/4),
        kmGeVector3d(0.5f,    sqrt(6.0f)/2,              1)
    };
    glMatrixMode(GL_MODELVIEW);//设置当前矩阵为视图矩阵
    glLoadIdentity();//指定的矩阵为单位矩阵(视图矩阵)
    glRotatef(45, 1, 0, 0);//旋转视图矩阵
   // glTranslatef(-1,-1, -1);//平移视图矩阵
    kmLight *light = new kmLight( EN_LIGHT0);
    GLfloat light_position[] ={1,2,3,0};
    light->setValue(KM_POSITION,light_position);
    GLfloat lg_diffuse[]={1,0,0,1};
    light->setValue(KM_DIFFUSE,lg_diffuse);
    GLfloat lg_ambient[]={1,0,0,1};
    light->setValue(KM_AMBIENT,lg_ambient);
    GLfloat lg_specular[]={1,1,1,1};
    light->setValue(KM_SPECULAR,lg_specular);
   // light->turnOn();

    kmTetra *pTetra = new kmTetra(pts);
    pTetra->setColor(kmColor(1,0,0));
    kmTetra *pTetra2 = new kmTetra(pts1);
    pTetra2->addChild(pTetra);
    pTetra2->setColor(kmColor(0,1,0));
    myViewer->show(pTetra2);
}

#endif