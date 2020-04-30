#ifndef CMENU_H
#define CMENU_H

#include "IMenu.h"
#include <string>
#include <map>

class CMenu : public IMenu
{
public:

    CMenu();
    ~CMenu();
    void PrintMenu();
    bool GetInput();
    int GetOption();

private:

    std::map<int, std::string> m_options;
    int m_option;

};
#endif /* IMENU_H */