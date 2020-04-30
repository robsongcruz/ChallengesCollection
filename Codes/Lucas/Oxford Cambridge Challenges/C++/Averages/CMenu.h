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
    std::string GetOption();

private:

    std::map<std::string , std::string> m_options;
    std::string m_option;

};
#endif /* IMENU_H */