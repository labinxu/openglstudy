#ifndef  KM_MAIN_INCLUDES_H
#define KM_MAIN_INCLUDES_H
#include "Types.h"
namespace KaMi {
     

#define kmMain() \
    int kmMain_(); \
    int main(int argc,char** argv) { \
    kmInitKaMi(argc,argv);\
    kmMain_();}\
    int kmMain_()

    void kmInitKaMi(int ,char**);
    void kmCreateWindow(const char*szName,kmInt32 width,kmInt32 height);
    void kmLooping();

}

#endif