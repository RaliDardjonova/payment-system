#ifndef _ACCOUNT_H
#define _ACCOUNT_H

class Account{
public:
    Account();
    Account(const Account&);
    ~Account();



private:
    IBAN iban;
};

#endif
