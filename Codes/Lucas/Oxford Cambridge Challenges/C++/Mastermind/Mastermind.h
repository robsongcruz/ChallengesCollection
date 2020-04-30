#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "IMenu.h"
#include "IScoreBoard.h"
#include "IEngine.h"
#include <memory>

class Mastermind
{
public:

    Mastermind();
    ~Mastermind();
    void Run();
    void InitGame();

private:

    std::unique_ptr<IMenu> m_menu;
    std::unique_ptr<IScoreBoard> m_scoreBoard;
    std::unique_ptr<IEngine> m_engine;
    bool m_exit;

};
#endif /* MASTERMIND_H */