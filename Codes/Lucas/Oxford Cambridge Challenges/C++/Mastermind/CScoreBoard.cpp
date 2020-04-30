#include "CScoreBoard.h"
#include <iostream>
#include <string>

CScoreBoard::CScoreBoard()
{

}

CScoreBoard::~CScoreBoard()
{

}

void CScoreBoard::AddToScoreBoard(std::string name, int score)
{
    m_scoreBoard.insert(std::pair<int, std::string>(score, name));
}

bool CScoreBoard::RemoveFromScoreBoard(std::string name)
{
    if (name.empty())
    {
        return false;
    }

    std::map<int, std::string>::iterator it = m_scoreBoard.find(10);
    if (it != m_scoreBoard.end())
    {
        m_scoreBoard.erase(it);
        return true;
    }

    return false;
}

void CScoreBoard::PrintScoreBoard()
{
    std::cout << " Score Board\n";
    std::cout << "Name - Score\n";
    
    for (std::map<int, std::string>::iterator it = m_scoreBoard.begin(); it != m_scoreBoard.end(); it++)
    {
        std::cout << it->first << " - " << it->second << "\n";
    }
}