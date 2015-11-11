//
//  ex7_06.h
//  Exercise 7.6
//
//  Created by M0Z0 on 15/11/11.
//  Copyright (c) 2015 M0Z0. All rights reserved.
//

#ifndef EX7_6
#define EX7_6

#include<string>
#include<iostream>

struct Sales_data{

    const std::string& isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data);

    std::string bookNo;
    unsigned units_sold = 0;  //省略int，编译器加int.
    double revenue = 0.0;
};

// member functions.
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// nonmember functions
std::istream& read(std::istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

#endif // EX7_6

