#ifndef ISCOREBOARD_H
#define ISCOREBOARD_H

#include <string>

class IScoreBoard
{
public:

    virtual ~IScoreBoard() = default;
    virtual void AddToScoreBoard(std::string name, int score) = 0;
    virtual bool RemoveFromScoreBoard(std::string name) = 0;
    virtual void PrintScoreBoard() = 0;

};
#endif /* ISCOREBOARD_H */