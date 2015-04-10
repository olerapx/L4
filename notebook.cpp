#include "notebook.h"

Record* Notebook::createRecord(std::string content, QDate date)
{
    Record* record;
    record->_content=content;
    record->_date=date;
    return record;
}

void Notebook::addRecord(std::string text, QDate date)
{
    Record* rec=createRecord(text, date);
    recordList.add(rec);

}

void Notebook::insertRecord(std::string text, QDate date, int pageIndex)
{
    Record* rec=createRecord(text, date);
    recordList.insert(rec, pageIndex);
}

void Notebook::insertRecordAfterDate(std::string text, QDate date, QDate after)
{

}

void Notebook::insertRecordBeforeDate(std::string text, QDate date, QDate before)
{

}

void Notebook::insertRecordAfterContent(std::string text, QDate date, std::string after)
{

}

void Notebook::insertRecordBeforeContent(std::string text, QDate date, std::string before)
{

}

void Notebook::insertAtMid(std::string text, QDate date)
{
     Record* rec=createRecord(text, date);
     recordList.insertAtMid(rec);
}

void Notebook::removeAtMid()
{
   int mid=(recordList.Len()%2==0)? recordList.Len()/2-1:recordList.Len()/2;
   delete recordList.at(mid);

   recordList.removeAtMid();
}

void Notebook::removeAtBegin()
{
    delete recordList.at(0);
    recordList.removeAtBegin();
}

void Notebook::removeAtEnd()
{
    delete recordList.at(recordList.Len()-1);
    recordList.removeAtEnd();

}
void Notebook::removeAt(int pageIndex)
{
    delete recordList.at(pageIndex);
    recordList.removeAt(pageIndex);

}

void Notebook::removeByDate(QDate date)
{

}

void Notebook::removeByContent(std::string text)
{

}

std::string Notebook::readRecord(QDate date)
{

}

std::string Notebook::readRecord(int pageIndex)
{

}

QDate Notebook::readDate (std::string text)
{

}

QDate Notebook::readDate (int pageIndex)
{

}
