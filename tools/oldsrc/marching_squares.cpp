#if 0
#include "includes.h"

const GEfloat X_MAX = 1.0;
const GEfloat Y_MAX = 1.0;
const GEfloat X_MIN = -1.0;
const GEfloat Y_MIN = -1.0;


const int N_X = 50;
const int N_Y = 50;

const GEfloat THRESHOLD =0.0;
double f(double x,double y)
{
    double a = 0.49;
    double b = 0.5;

    return (x * x + y*y + a * a)*(x * x + y*y + a * a) - 4*a*a*x*x - b*b*b*b;
}

int cell(double a, double b, double c, double d)
{
    int n =0;
    if(a >THRESHOLD) n+=1;
    if(b > THRESHOLD) n+=8;
    if(c > THRESHOLD) n+=4;
    if(d > THRESHOLD) n+=2;
    return n;
}
void draw_one(int num,int i,int j, double a, double b, double c, double d)
{
    double dx = (X_MAX - X_MIN) / (N_X - 1.0);
    double dy = (Y_MAX - Y_MIN) / (N_Y - 1.0);

    double ox = X_MIN + i * (X_MAX - X_MIN) / N_X - 1.0;
    double oy = Y_MIN + j * (Y_MAX - Y_MIN) / N_Y - 1.0;

    int x1,y1,x2,y2;
    switch(num)
    {
    case 1:case 14:
        x1 = ox;
    }

}
void draw_adjacent(int num,int i,int j, double a, double b, double c, double d)
{

}
void draw_opposite(int num,int i,int j, double a, double b, double c, double d)
{

}
void lines(int num, int i ,int j, double a, double b,double c,double d)
{
    switch(num)
    {
    case 1:case 2:case 4:case 7:case 8:case 11:case 13:case 14:
        draw_one(num,i,j,a,b,c,d);

    case 3:case 6: case  9:case 12:
        draw_adjacent(num,i,j,a,b,c,d);
    case 5:case 10:
        draw_opposite(num,i,j,a,b,c,d);
    case 0:case 15:break;
    }
}
void display()
{
    double data[N_X][N_Y];

    glClear(GL_COLOR_BUFFER_BIT);
    
    for(int i =0; i < N_X; i++)
    {
        for (int j = 0; j < N_Y; j++)
        {
            data[i][j] = f(X_MIN + i*(X_MAX - X_MIN)/(N_X-1.0), Y_MIN + j * (Y_MAX - Y_MIN) / N_Y - 1.0);
        }
    }

    int c = 0;
    for (int i = 0; i < N_X; ++i)
    {
        for (int j =0 ; j < N_Y; ++j)
        {
            c = cell(data[i][j],data[i+1][j],data[i+1][j+1],data[i][j+1]);
            lines(c,i,j,data[i][j], data[i+1][j],data[i+1][j+1],data[i][j+1]);
        }
    }

    glFlush();

}
int main()
{

}
#endif