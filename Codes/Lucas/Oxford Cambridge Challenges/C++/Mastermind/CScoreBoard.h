#ifndef CSCOREBOARD_H
#define CSCOREBOARD_H

#include "IScoreBoard.h"
#include <map>

class CScoreBoard : public IScoreBoard
{
public:

    CScoreBoard();
    ~CScoreBoard();
    void AddToScoreBoard(std::string name, int score);
    bool RemoveFromScoreBoard(std::string name);
    void PrintScoreBoard();

private:

    std::map<int, std::string> m_scoreBoard;

};
#endif /* CSCOREBOARD_H */