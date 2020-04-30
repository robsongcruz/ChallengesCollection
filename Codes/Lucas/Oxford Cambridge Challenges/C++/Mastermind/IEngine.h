#ifndef IENGINE_H
#define IENGINE_H

#include <map>

class IEngine
{
public:

    virtual ~IEngine();
    virtual int GetScore() = 0;
    virtual std::map<int ,int> GetPairs() = 0;

};
#endif /* IENGINE_H */