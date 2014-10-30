#ifndef IOBJECT_H_
#define IOBJECT_H_

namespace KaMi
{
    class IObject
    {
    public:
        virtual ~IObject(){}
    public:
        virtual void draw() = 0 ;
        virtual void onUpdate() = 0;
    };
}

#endif