#include "Averages.h"
#include "CMenu.h"

#include <iostream>

Averages::Averages() :
        m_exit(false)
{
    m_menu = std::unique_ptr<IMenu> (new CMenu);
}

Averages::~Averages()
{

}

void Averages::Run()
{
    m_menu->PrintMenu();

    while(!m_exit)
    {
        m_menu->GetInput();

        if ("quit" == m_menu->GetOption())
        {
            m_exit = true;
        }
        else if ("average" == m_menu->GetOption())
        {
            std::cout << "Average is " << CalcAverage(m_numberList) << "\n";
        }
        else if ("median" == m_menu->GetOption())
        {
            std::cout << "Average is " << CalcMedian(m_numberList) << "\n";
        }
        else if ("mode" == m_menu->GetOption())
        {
            std::cout << "Not implemented yet\n";
        }
        else if ("save" == m_menu->GetOption())
        {
            std::cout << "Not implemented yet\n";
        }
        else if ("open" == m_menu->GetOption())
        {
            std::cout << "Not implemented yet\n";
        }
        else
        {
            m_numberList.push_back(std::stoi(m_menu->GetOption()));
        }
        
    }
}

float Averages::CalcAverage(std::vector<int> arr)
{
    int sum = 0;

    for (auto i : arr)
    {
        sum += i;
    }

    return (float)sum / (float) arr.size();
}

float Averages::CalcMedian(std::vector<int> arr)
{
    if (arr.size() % 2)
    {
        return ((float)arr[(arr.size() / 2) - 1] + (float)arr[(arr.size() / 2)]) / 2;
    }
    else
    {
        return arr[arr.size() / 2];
    }
    
}

int Averages::CalcMode(std::vector<int> arr)
{
    return 0;
}