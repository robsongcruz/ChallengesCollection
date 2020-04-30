#include "CMenu.h"
#include <iostream>

CMenu::CMenu() :
        m_option("")
{
    m_options.insert(std::pair<std::string , std::string> ("average", "Average"));
    m_options.insert(std::pair<std::string , std::string> ("median", "Median"));
    m_options.insert(std::pair<std::string , std::string> ("mode", "Mode"));
    m_options.insert(std::pair<std::string , std::string> ("save", "Save to file"));
    m_options.insert(std::pair<std::string , std::string> ("open", "Open file"));
    m_options.insert(std::pair<std::string , std::string> ("quit", "Exit"));
}

CMenu::~CMenu()
{

}
    
void CMenu::PrintMenu()
{
    std::cout << "Menu\n";

    std::map<std::string , std::string>::iterator it;
    for (it = m_options.begin(); it != m_options.end(); it++)
    {
        std::cout << "[" << it->first << "] - " << it->second << "\n"; 
    }

    std::cout << "Choose: ";

}
    
bool CMenu::GetInput()
{
    std::string option;

    std::cin >> option;

    if(option.empty())
    {
        return false;
    }

    m_option = option;

    return true;
}

std::string CMenu::GetOption()
{
    return m_option;
}