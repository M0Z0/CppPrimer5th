//
//  ex7_23.h
//  Exercise 7.23
//
//  Created by MAIKA on 2016.3.20.
//  Copyright (c) 2016 MAIKA. All rights reserved.
//

#ifndef CP5_ex7_23_h
#define CP5_ex7_23_h

#include <string>

class Screen
{
public:
	using pos = std::string::size_type;

	Screen() = default;  //C++11 features, recover the use of default constructor.
	Screen(pos h, pos w, char c) : height(h), width(w), contents(h*w, c){}

	char get()const { return contents[cursor]; }
	char get(pos r, pos c)const { return contents[r*width + c]; }

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

#endif