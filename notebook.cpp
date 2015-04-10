#include "notebook.h"

Record* Notebook::createRecord(std::string content, time_t date)
{
    Record* record=new Record();
    record->_content=content;
    record->_date=date;

    return record;
}

void Notebook::addRecord(std::string text, time_t date)
{
    Record* rec=createRecord(text, date);
    recordList.add(rec);

}

void Notebook::insertRecord(std::string text, time_t date, int pageIndex)
{
    Record* rec=createRecord(text, date);
    recordList.insert(rec, pageIndex);
}

void Notebook::insertRecordAfterDate(std::string text, time_t date, time_t after)
{
    int index = indexOf(after);
    if (index==-1) return;

    Record* rec=createRecord(text, date);
    recordList.insert(rec, index+1);
}

void Notebook::insertRecordBeforeDate(std::string text, time_t date, time_t before)
{
    int index = indexOf(before);
    if (index==-1) return;

    Record* rec=createRecord(text, date);
    recordList.insert(rec, index);
}

void Notebook::insertRecordAfterContent(std::string text, time_t date, std::string after)
{
    int index = indexOf(after);
    if (index==-1) return;

    Record* rec=createRecord(text, date);
    recordList.insert(rec, index+1);

}

void Notebook::insertRecordBeforeContent(std::string text, time_t date, std::string before)
{
    int index = indexOf(before);
    if (index==-1) return;

    Record* rec=createRecord(text, date);
    recordList.insert(rec, recordList.Len()/2);

}

void Notebook::insertAtMid(std::string text, time_t date)
{
     Record* rec=createRecord(text, date);
     recordList.insert(rec, recordList.Len()/2);
}

void Notebook::removeAtMid()
{
   int mid=(recordList.Len()%2==0)? recordList.Len()/2-1:recordList.Len()/2;
   delete recordList.at(mid);
   recordList.removeAt(mid);
}

void Notebook::removeAtBegin()
{
    delete recordList.at(0);
    recordList.removeAt(0);
}

void Notebook::removeAtEnd()
{
    delete recordList.at(recordList.Len()-1);
    recordList.removeAt(recordList.Len()-1);
}
void Notebook::removeAt(unsigned int pageIndex)
{
    delete recordList.at(pageIndex);
    recordList.removeAt(pageIndex);
}

void Notebook::removeByDate(time_t date)
{
    int index = indexOf(date);
    delete recordList.at(index);
    recordList.removeAt(index);
}

void Notebook::removeByContent(std::string text)
{
    int index=indexOf(text);
    delete recordList.at(index);
    recordList.removeAt(index);
}

std::string Notebook::readRecord(time_t date)
{    
    int index = indexOf(date);
    return recordList.at(index)->_content;
}

std::string Notebook::readRecord(unsigned int pageIndex)
{
    return recordList.at(pageIndex)->_content;
}

time_t Notebook::readDate (std::string text)
{
    int index = indexOf(text);
    return recordList.at(index)->_date;
}

time_t Notebook::readDate (unsigned int pageIndex)
{
 return recordList.at(pageIndex)->_date;
}

std::string Notebook::readDateString(std::string text)
{
     int index = indexOf(text);
    return ctime(&recordList.at(index)->_date);
}

std::string Notebook::readDateString(unsigned int pageIndex)
{
     return ctime(&recordList.at(pageIndex)->_date);
}

int Notebook::indexOf(time_t date)
{
     for(unsigned int i=0;i<recordList.Len();i++)
          if (recordList.at(i)->_date==date) return i;

    return -1;
}

int Notebook::indexOf(std::string text){
    for(unsigned int i=0;i<recordList.Len();i++)
         if (recordList.at(i)->_content==text) return i;

   return -1;
}

void Notebook::writeToFile (std::ofstream& out)
{
    for (unsigned int i=0;i<recordList.Len();i++)
    {
        out<<"Date: "<<ctime(&recordList.at(i)->_date)<<"\n";
        out<<"Record: " <<recordList.at(i)->_content<<"\n\n\n";
    }
}
