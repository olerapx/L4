#ifndef NOTEBOOK_H
#define NOTEBOOK_H
#include "list.h"
#include "record.h"
#include "fstream"

class Notebook
{
private:
    List<Record *> recordList;
    Record* createRecord(std::string content, QDate date);

public:
    void addRecord(std::string text, QDate date);
    void insertRecord(std::string text, QDate date, int pageIndex);
    void insertRecordAfterDate(std::string text, QDate date, QDate after);
    void insertRecordBeforeDate(std::string text, QDate date, QDate before);
    void insertRecordAfterContent(std::string text, QDate date, std::string after);
    void insertRecordBeforeContent(std::string text, QDate date, std::string before);
    void insertAtMid(std::string text, QDate date);

   void removeAtMid();
   void removeAtBegin();
   void removeAtEnd();
   void removeAt(int pageIndex);
   void removeByDate(QDate date);
   void removeByContent(std::string text);

   std::string readRecord(QDate date);
   std::string readRecord(int pageIndex);
   QDate readDate (std::string text);
   QDate readDate (int pageIndex);

  inline int getPageNumber() { return recordList.Len(); }

  int indexOf(QDate date);
  int indexOf(std::string text);

  void writeToFile (std::ofstream& out);
};

#endif // NOTEBOOK_H
