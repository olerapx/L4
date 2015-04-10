#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include "list.h"
#include "record.h"
#include "fstream"


//wrapper class representing List of struct Record
class Notebook
{
private:
    List<Record *> recordList;
    Record* createRecord(std::string content, time_t date);

public:
    void addRecord(std::string text, time_t date);
    void insertRecord(std::string text, time_t date, int pageIndex);
    void insertRecordAfterDate(std::string text, time_t date, time_t after);
    void insertRecordBeforeDate(std::string text, time_t date, time_t before);
    void insertRecordAfterContent(std::string text, time_t date, std::string after);
    void insertRecordBeforeContent(std::string text, time_t date, std::string before);
    void insertAtMid(std::string text, time_t date);

   void removeAtMid();
   void removeAtBegin();
   void removeAtEnd();
   void removeAt(unsigned int pageIndex);
   void removeByDate(time_t date);
   void removeByContent(std::string text);

   std::string readRecord(time_t date);
   std::string readRecord(unsigned int pageIndex);
   time_t readDate (std::string text);
   time_t readDate (unsigned int pageIndex);
   std::string readDateString(std::string text);
   std::string readDateString(unsigned int pageIndex);
  inline int getPageNumber() { return recordList.Len(); }

  int indexOf(time_t date);
  int indexOf(std::string text);

  void writeToFile (std::ofstream& out);

  inline unsigned int len(){return recordList.Len();}
};

#endif // NOTEBOOK_H
