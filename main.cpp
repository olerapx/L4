#include <QCoreApplication>
#include "list.h"
#include "notebook.h"
#include <iostream>

int main()
{
Notebook n;
n.addRecord("Test WW II record", QDate::fromJulianDay(2431200));
n.addRecord("test near future record", QDate::fromJulianDay(2472340));
std::ofstream out;
out.open("record");
n.writeToFile(out);
out.close();
    return 0;
}
