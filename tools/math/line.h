#ifndef LINE_H
#define LINE_H
#include "./include/point.h"


namespace Camus
{
    class Line
    {
      public:
        Line(const Point& pt1, const Point &pt2)
        :start_pt(pt1),
        end_pt(pt2){}

        void draw();

      private:
        Point start_pt;
        Point end_pt;
    };
};


#endif /* LINE_H */
