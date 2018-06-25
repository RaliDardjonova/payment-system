#ifndef _ORDINARYORDER_H
#define _ORDINARYORDER_H

#include "PaymentOrder.h"

class OrdinaryOrder: public PaymentOrder {
public:
    OrdinaryOrder();
    OrdinaryOrder(const OrdinaryOrder&);
    ~OrdinaryOrder();
    OrderPointer create() const;
    OrderPointer clone() const;

    void save(bool);
    std::string getCurrency() const;
    static void deleteFromDB(std::string);
private:
    static std::string currency;
};

#endif //_ORDINARYORDER_H
