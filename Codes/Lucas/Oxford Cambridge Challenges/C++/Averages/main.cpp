#include "IMenu.h"
#include "CMenu.h"
#include "Averages.h"

#include <memory>
#include <iostream>

int main()
{
    std::unique_ptr<Averages> app (new Averages);

    app->Run();    

    return 0;
}