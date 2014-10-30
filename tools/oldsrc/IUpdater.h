#ifndef IUPDATER_H_
#define IUPDATER_H_
namespace KaMi
{
    class IUpdater
    {
    public:
        virtual ~IUpdater(){}
    public:

        virtual void update() = 0;
    };

}
#endif