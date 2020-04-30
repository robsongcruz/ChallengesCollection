#include "CMenu.h"
#include <iostream>

CMenu::CMenu() :
        m_option(0)
{
    m_options.insert(std::pair<int, std::string> (1, "Easy"));
    m_options.insert(std::pair<int, std::string> (2, "Hard"));
    m_options.insert(std::pair<int, std::string> (3, "ScoreBoard"));
    m_options.insert(std::pair<int, std::string> (4, "Exit"));
}

CMenu::~CMenu()
{

}
    
void CMenu::PrintMenu()
{
    std::cout << "Menu\n";

    std::map<int, std::string>::iterator it;
    for (it = m_options.begin(); it != m_options.end(); it++)
    {
        std::cout << "[" << it->first << "] - " << it->second << "\n"; 
    }

    std::cout << "Choose: ";

}
    
bool CMenu::GetInput()
{
    int option;

    std::cin >> option;

    if(option < 0)
    {
        return false;
    }

    std::map<int, std::string>::iterator it = m_options.find(option);
    if (it != m_options.end())
    {
        m_option = it->first;
        return true;
    }

    return false;
}

int CMenu::GetOption()
{
    return m_option;
}