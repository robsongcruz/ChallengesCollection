#ifndef AVERAGES_H
#define AVERAGES_H

#include "IMenu.h"

#include <memory>
#include <vector>

class Averages
{
public:

    Averages();
    ~Averages();
    void Run();
    float CalcAverage(std::vector<int> arr);
    float CalcMedian(std::vector<int> arr);
    int CalcMode(std::vector<int> arr);

private:

    std::unique_ptr<IMenu> m_menu;
    std::vector<int> m_numberList;
    bool m_exit;

};
#endif /* AVERAGES_H */