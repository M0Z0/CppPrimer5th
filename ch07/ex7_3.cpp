//
//  ex7_3.cpp
//  Exercise 7.3
//
//  Created by M0Z0 on 15/11/5.
//  Copyright (c) 2015 M0Z0. All rights reserved.
//

#include "ex7_2.h"
#include <iostream>
using namespace std;

int main()
{
    Sales_data totsl;
    if(cin >> total){
        sales_data trans;
        while(cin >> trans){
            if(total.isbn() == trans.isbn)
                total.combine(trans);
            else{
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    }else{
        cerr << "No data?" << endl;
    }
    return 0;
}
