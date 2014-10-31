#ifndef POINT_H
#define POINT_H

namespace Camus
{
  class Point
  {
  public:
    Point(float x, float y, float z = 0)
    {
        m_data[0] = x;
        m_data[1] = y;
        m_data[2] = z;
    }

    float* data()
    {
      return m_data;
    }

  public:
    float m_data[3];
  };
};



#endif /* POINT_H */
