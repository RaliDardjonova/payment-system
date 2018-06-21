#ifndef _ORDINARYORDER_H
#define _ORDINARYORDER_H

#include "PaymentOrder.h"

class OrdinaryOrder: public PaymentOrder {
private:
    static std::string currency;
};

#endif //_ORDINARYORDER_H
