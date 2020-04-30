#ifndef IMENU_H
#define IMENU_H

#include <string>

class IMenu
{
public:

    virtual ~IMenu() = default;
    virtual void PrintMenu() = 0;
    virtual bool GetInput() = 0;
    virtual std::string GetOption() = 0;

};
#endif /* IMENU_H */