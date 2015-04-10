#include <QCoreApplication>
#include "list.h"
#include "notebook.h"
#include <iostream>

int main()
{

    Notebook n;
    n.addRecord("First record", time(0));
    n.addRecord("Second record", time(0));
    std::ofstream out;
    out.open("record");
    n.writeToFile(out);
    out.close();
    return 0;
}
