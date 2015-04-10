#include <QCoreApplication>
#include "list.h"
#include <iostream>

int main()
{
    List<int> list;
    list<< 5;
    list<<3;
    list<<4;
 list.removeAtBegin();
 list.removeAtEnd();
    for (int i=0;i<list.Len();i++)
        std::cout <<list[i]<<" ";
    std::cout <<"\n";
    return 0;
}
