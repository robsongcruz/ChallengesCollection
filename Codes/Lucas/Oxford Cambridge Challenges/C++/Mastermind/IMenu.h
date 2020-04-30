#ifndef IMENU_H
#define IMENU_H

class IMenu
{
public:

    virtual ~IMenu() = default;
    virtual void PrintMenu() = 0;
    virtual bool GetInput() = 0;
    virtual int GetOption() = 0;

};
#endif /* IMENU_H */