#include <QCoreApplication>
#include "list.h"
#include "notebook.h"
#include <iostream>

int main()
{
    Notebook n;
    std::string lorem="Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt"
                      " ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco"
                      " laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in "
                      "voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat"
                      " non proident, sunt in culpa qui officia deserunt mollit anim "
                      "id est laborum.";
    n.addRecord("WW 2 beginning", time_t(-957269000L)); //hardcoded date: 1 sep 1939
    n.addRecord("Now", time(0L));
    n.addRecord(lorem, time(0L));
  for (int i=0;i<4;i++)
     n.addRecord("Record "+std::to_string(i), time(0L));

  n.removeAtMid();
  n.removeAtEnd();

  for (unsigned int i=0;i<n.len();i++)
      std::cout<<"Record: " <<n.readRecord(i)<<"\nAt date: "<<n.readDateString(i)<<"\n";

    std::ofstream out;
    out.open("record");
    n.writeToFile(out);
    out.close();
    return 0;
}
