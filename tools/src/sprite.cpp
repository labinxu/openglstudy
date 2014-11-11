#include "sprite.h"
#include <iostream>
#include "programer.h"
using namespace Camus;
using namespace std;


void Sprite::keyboard(unsigned char key, int x, int y)
{
    std::cout<<"key: "<<key<<" x: "<<x<<" y: "<<y<<std::endl;
}

void Sprite::mouse(int bt, int state, int x, int y)
{
    std::cout<<"bt: "<<bt<<" x: "<<x<<" y: "<<y<<" state: "<<state<<std::endl;

}
