#ifndef _ORDINARYORDER_H
#define _ORDINARYORDER_H

#include "PaymentOrder.h"

class OrdinaryOrder: public PaymentOrder {
public:
    OrdinaryOrder();
    OrdinaryOrder(const OrdinaryOrder&);
    ~OrdinaryOrder();

    void save(bool);
    std::string getCurrency() const;
private:
    static std::string currency;
};

#endif //_ORDINARYORDER_H
