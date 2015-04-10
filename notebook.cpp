#include "notebook.h"

Record* Notebook::createRecord(std::string content, QDate date)
{
    Record* record=new Record();
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
    int index = indexOf(after);
    if (index==-1) return;

    Record* rec=createRecord(text, date);
    recordList.insert(rec, index+1);
}

void Notebook::insertRecordBeforeDate(std::string text, QDate date, QDate before)
{
    int index = indexOf(before);
    if (index==-1) return;

    Record* rec=createRecord(text, date);
    recordList.insert(rec, index);
}

void Notebook::insertRecordAfterContent(std::string text, QDate date, std::string after)
{
    int index = indexOf(after);
    if (index==-1) return;

    Record* rec=createRecord(text, date);
    recordList.insert(rec, index+1);

}

void Notebook::insertRecordBeforeContent(std::string text, QDate date, std::string before)
{
    int index = indexOf(before);
    if (index==-1) return;

    Record* rec=createRecord(text, date);
    recordList.insert(rec, index);

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

std::string Notebook::readRecord(QDate date)
{    
    int index = indexOf(date);
    return recordList.at(index)->_content;
}

std::string Notebook::readRecord(int pageIndex)
{
    return recordList.at(pageIndex)->_content;
}

QDate Notebook::readDate (std::string text)
{
    int index = indexOf(text);
    return recordList.at(index)->_date;
}

QDate Notebook::readDate (int pageIndex)
{
 return recordList.at(pageIndex)->_date;
}


int Notebook::indexOf(QDate date)
{
     for(int i=0;i<recordList.Len();i++)
          if (recordList.at(i)->_date==date) return i;


    return -1;
}

int Notebook::indexOf(std::string text){
    for(int i=0;i<recordList.Len();i++)
         if (recordList.at(i)->_content==text) return i;


   return -1;

}

void Notebook::writeToFile (std::ofstream& out)
{
for (int i=0;i<recordList.Len();i++)
  out<< "Date: " << recordList.at(i)->_date.toString("dd MMMM yyyy").toStdString()<<"г.\nRecord: " <<recordList.at(i)->_content<<"\n\n\n";

}
