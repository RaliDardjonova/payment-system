#ifndef _DOCUMENT_H
#define _DOCUMENT_H
#include "Date.h"
#include "sql-controllers.h"

class Document{
public:
    Document();
    Document(const Document&);
    Document(std::string number);
    ~Document();
    int getType() const;
    std::string getNumber() const;
    Date getDate() const;
    std::string getDebitedParty() const;

    void setType(int);
    void setNumber(std::string);
    void setDate(Date);
    void setDebitedParty(std::string);
    int save();
private:
    int type;
    std::string number;
    Date date;
    std::string debitedParty;
};

#endif
