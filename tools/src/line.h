#ifndef LINE_H
#define LINE_H
#include "primitive.h"


namespace Camus
{

class Line: public Primitive
{
  public:
    Line(Point &&pt1, Point &&pt2)
            :start_pt(pt1), end_pt(pt2){
        std::cout<<"rhrs "<<std::endl;
    }
    Line(Point &pt1, Point &pt2)
            :start_pt(pt1), end_pt(pt2){}

  private:
    virtual void draw();
    Point start_pt;
    Point end_pt;
};

};


#endif /* LINE_H */
