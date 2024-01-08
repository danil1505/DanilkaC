#ifndef RECORD_H
#define RECORD_H

#include <string>
#include "people.h"
#include "order.h"

class Record {
public:
    Record(const std::string& date, const People& customer, const Order& order);

    std::string getDate() const;
    const People& getCustomer() const;
    const Order& getOrder() const;

private:
    std::string date;
    People customer;
    Order order;
};

Record::Record(const std::string& date, const People& customer, const Order& order)
    : date(date), customer(customer), order(order) {}

std::string Record::getDate() const {
    return date;
}

const People& Record::getCustomer() const {
    return customer;
}

const Order& Record::getOrder() const {
    return order;
}

#endif 
