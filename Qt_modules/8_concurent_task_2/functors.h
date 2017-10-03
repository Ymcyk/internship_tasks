#ifndef FUNCTORS_H
#define FUNCTORS_H

#include <functional>

//std::function<int(int)> maping = [](int mapped) -> int { return mapped; };
//std::function<void(long long &, const int &)> scaling = [](long long &result, const int &intermediate) -> void { result += intermediate; };

//int maping(int mapped)
//{
//    return mapped;
//}

//void scaling(long long &result, const int &intermediate)
//{
//    result += intermediate;
//}

struct maping
{
    int operator() (int mapped)
    {
        return mapped;
    }
};

struct scaling
{
    void operator() (long long &result, const int &intermediate)
    {
        result += intermediate;
    }
};

#endif // FUNCTORS_H
