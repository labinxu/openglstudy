#if 0
#include "includes.h"

#include <memory>
#define MAX_POLYGONS 8
#define MAX_VERTICES 10

#include <stdlib.h>
#include <stdio.h>

void myMouse(int ,int ,int ,int);
void myMotion(int,int);
void myDisplay();
void myReshape(int,int);
void color_menu(int);
void main_menu(int);
int pick_polygon(int ,int );

void myInit();



struct polygon
{
    int color;
    bool used;
    int xmin,xmax,ymin,ymax;
    float xc,yc;
    int nvertices;
    int y[MAX_VERTICES];
    int x[MAX_VERTICES];
};

bool picking = false;
bool moving = false;
int in_polygon = -1;
int present_color = 0;

GLsizei wh = 500,ww =  500;
int draw_mode = 0; //»æÖÆÄ£Ê½
GLfloat colors[8][3] =
{
    {1.0, 0.0, 0.0},
    {1.0, 0.0, 0.0},
    {1.0, 1.0, 0.0},
    {1.0, 0.0, 1.0},
    {1.0, 0.0, 1.0},
    {1.0, 0.0 ,1.0},
    {1.0, 1.0, 0.0},
    {1.0, 1.0, 1.0}
};


polygon polygons[MAX_POLYGONS];

int main(int argc,char **argv)
{
   // memset(polygons,0,sizeof(polygon)*MAX_POLYGONS);
    int c_menu;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(ww,wh);

    glutCreateWindow("polygen modeler");
    glutDisplayFunc(myDisplay);
    myInit();

    c_menu = glutCreateMenu(color_menu);

    glutAddMenuEntry("Blank", 0);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);
    glutAddMenuEntry("Cyan", 4);
    glutAddMenuEntry("Magenta", 5);
    glutAddMenuEntry("Yellow", 6);
    glutAddMenuEntry("White", 7);

    glutCreateMenu(main_menu);

    glutAddMenuEntry("new polygon", 1);
    glutAddMenuEntry("end polygon", 2);
    glutAddMenuEntry("delete polygon", 3);
    glutAddMenuEntry("move polygon", 4);
    glutAddMenuEntry("quit", 5);


    glutAddSubMenu("Colors", c_menu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutReshapeFunc(myReshape);
    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);


    /*
    */

    glutMainLoop();
}

void myInit()
{

    glClearColor(0.5, 1.5, 0.5, 1.0);
    for (int i = 0; i < MAX_POLYGONS; ++i)
    {
        polygons[i].used = false;
    }
}

void color_menu(int index)
{
    present_color = index;
    if (in_polygon >= 0)
    {
        polygons[in_polygon].color = index;
    }
}


int pick_polygon(int x,int y)
{
    // select the polygon which bound box ;
    for (int i = 0; i < MAX_POLYGONS; ++i)
    {
        if (polygons[i].used)
        {
            if (x >= polygons[i].xmin && x <= polygons[i].xmax
                &&
                y >= polygons[i].ymin && y <= polygons[i].ymax)
            {
                in_polygon = i;
                moving = true;
                return i;
            }
            printf("not in a polygon\n");
        }
    }
    return -1;
}
void myMouse(int btn,int state ,int x ,int y)
{
    y = wh -y;
    if (btn == GLUT_LEFT_BUTTON 
        && state == GLUT_DOWN 
        && !picking 
        && !moving)
    {
        // add vertex;
        //moving = false;
        if (in_polygon >= 0)
        {
            if (polygons[in_polygon].nvertices == MAX_VERTICES)
            {
                printf("exceeds maximum number vertices");
                exit(0);
            }
            int i = polygons[in_polygon].nvertices;
            polygons[in_polygon].x[i] = x;
            polygons[in_polygon].y[i] = y;
            polygons[in_polygon].nvertices += 1;

        }
    }

    if (btn == GLUT_LEFT_BUTTON 
        && state == GLUT_DOWN
        && picking
        && !moving)
    {
        picking =  false;
        moving = false;

        int j = pick_polygon(x, y);
        if (j >= 0)
        {
            polygons[j].used = false;
            in_polygon = -1;
            glutPostRedisplay();
        }
    }
}
void myMotion(int x,int y)
{
    int selectId = 0;
    if (moving)
    {
        y = wh - y;
        selectId = pick_polygon(x, y);
        if ((selectId) < 0)
        {
            printf("not in a polygon\n");
            return;
        }
    }
    printf("x = %d, y = %d\n",x,y);
    float dx = x - polygons[selectId].xc;
    float dy = y = polygons[selectId].yc;

    for (int i=0; i< polygons[selectId].nvertices; i++)
    {
        polygons[selectId].x[i] += dx;
        polygons[selectId].y[i] += dy;
    }

    // update the bound box
    polygons[selectId].xc += dx;
    polygons[selectId].yc += dy;
    if (dx > 0)
    {
        polygons[selectId].xmax += dx;
    }
    else
    {
        polygons[selectId].xmin += dx;
    }

    if (dy > 0)
    {
        polygons[selectId].ymax += dy;
    }
    else
    {
        polygons[selectId].ymin += dy;
    }
    glutPostRedisplay();
}
void myReshape(int w,int h )
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0,0,w,h);

    ww = w;
    wh = h;
}
void myDisplay()
{
    // display all the active polygons;
    int j = 0;

    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0 ; i < MAX_POLYGONS; ++i)
    {
        if (polygons[i].used)
        {
            glColor3fv(colors[polygons[i].color]);
            glBegin(GL_POLYGON);
            for (int j = 0; j < polygons[i].nvertices; ++j)
            {
                glVertex2i(polygons[i].x[j],polygons[i].y[j]);
            }
            glEnd();
        }
    }

    glFlush();
}
void main_menu(int index)
{
    int i =0 ;
    switch(index)
    {
    case 1:// menu :new polygon 
        moving = false;
        for (i =0 ; i < MAX_POLYGONS; ++i)
        {
            if(!polygons[i].used)
            {
                break;
            }
        }
        if (MAX_POLYGONS == i)
        {
            printf("max polygons");
            return;
        }

        polygons[i].color = present_color;
        polygons[i].used = true;
        polygons[i].nvertices =0;
        in_polygon =i;
        picking = false;
        break;
    case 2:

        moving = false;
        if(in_polygon >=0)
        {
            polygons[in_polygon].xmax = polygons[in_polygon].xmin = polygons[in_polygon].x[0];
            polygons[in_polygon].ymax = polygons[in_polygon].ymin = polygons[in_polygon].y[0];

            polygons[in_polygon].xc = polygons[in_polygon].x[0];
            polygons[in_polygon].yc = polygons[in_polygon].y[0];

            for (int i = 1; i < polygons[in_polygon].nvertices; ++i)
            {
                if (polygons[in_polygon].x[i] < polygons[in_polygon].xmin)
                {
                    polygons[in_polygon].xmin = polygons[in_polygon].x[i];
                }
                else if(polygons[in_polygon].xmax < polygons[in_polygon].x[i])
                {
                    polygons[in_polygon].xmax = polygons[in_polygon].x[i];
                }
                

                if (polygons[in_polygon].y[i] < polygons[in_polygon].ymin )
                {
                    polygons[in_polygon].ymin = polygons[in_polygon].y[i];
                }
                else if (polygons[in_polygon].ymax < polygons[in_polygon].y[i])
                {
                    polygons[in_polygon].ymax = polygons[in_polygon].y[i];
                }

                polygons[in_polygon].xc += polygons[in_polygon].x[i];
                polygons[in_polygon].yc += polygons[in_polygon].y[i];

            }
            // center point
            polygons[in_polygon].xc = polygons[in_polygon].xc / polygons[in_polygon].nvertices;
            polygons[in_polygon].yc = polygons[in_polygon].yc / polygons[in_polygon].nvertices;

        }
        in_polygon = - 1;
        break;

    case 3:
        picking = true;
        moving = false;
        break;
    case 4:
        moving = true;
        break;
    case 5:
        exit(0);
        break;
    default:
        break;
    }

}

#endif