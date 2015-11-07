//
//  ex7_02.h
//  Exercise 7.2
//
//  Created by M0Z0 on 15/10/26.
//  Copyright (c) 2015 M0Z0. All rights reserved.
//

#ifndef EX7_2_H
#define EX7_2_H

#include<string>

struct Sales_data
{
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

public:
    inline std::string isbn()const{ return bookNo; }
    Sales_data& combine(Sales_data&);
};

Sales_data& combine(Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
//test
#endif // EX7_2_H

