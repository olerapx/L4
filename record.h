#ifndef RECORD_H
#define RECORD_H
#include <string.h>
#include <iostream>
#include <ctime>


struct Record
{
    std::string _content;
    time_t _date;
};

#endif // RECORD_H
