#include "IScoreBoard.h"
#include "CScoreBoard.h"
#include "IMenu.h"
#include "CMenu.h"
#include <memory>
#include <iostream>
#include "Mastermind.h"

int main ()
{
    std::unique_ptr<Mastermind> game (new Mastermind);

    game->Run();

    return 0;
}