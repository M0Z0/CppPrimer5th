#include "ex13_22.h"

int main()
{
	string m = "hi mom";
	HasPtr h(m);
	HasPtr h2(h);
	HasPtr h3 = h;
	string d = "hi dad";
	string s = "hi son";
	h2 = d;
	h3 = s;
	swap(h2, h3);
	cout << "h: " << *h << endl;
	cout << "h2: " << *h2 << endl;
	cout << "h3: " << *h3 << endl;
	getchar();
}