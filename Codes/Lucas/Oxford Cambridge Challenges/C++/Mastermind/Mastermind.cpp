#include "Mastermind.h"
#include <iostream>

#include "CMenu.h"
#include "CScoreBoard.h"

Mastermind::Mastermind() :
        m_exit(false)
{
    m_menu = std::unique_ptr<IMenu> (new CMenu);
    m_scoreBoard = std::unique_ptr<IScoreBoard> (new CScoreBoard);
}

Mastermind::~Mastermind()
{

}

void Mastermind::Run()
{
    while(!m_exit)
    {
        m_menu->PrintMenu();
        m_menu->GetInput();

        switch (m_menu->GetOption())
        {
        case 1:
            // Easy
            std::cout << "Starting easy mode...\n";
            break;
        
        case 2:
            // Hard;
            std::cout << "Starting hard mode...\n";
            break;
        
        case 3:
            m_scoreBoard->PrintScoreBoard();
            break;
        
        case 4:
            m_exit = true;
            break;

        default:
            std::cout << "Invalid option" << m_menu->GetOption() << "\n";
            break;
        }
    }
}

void Mastermind::InitGame()
{

}