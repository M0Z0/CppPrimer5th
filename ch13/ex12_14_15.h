#include <iostream>
#include <memory>

using namespace std;

struct destination {};
struct connection {};

connection connect(destination *pd)
{
	cout << "open" << endl;
	return connection();
}

void disconnect(connection c)
{
	cout << "close" << endl;
}

void f(destination &d)
{
	connection c = connect(&d);
	//忘记dis关闭
	cout << endl;
}

void end_connection(connection *p) { disconnect(*p); }

//使用shared_ptr的版本
void f1(destination &d)
{
	connection c = connect(&d);
	//shared_ptr<connection> p(&c, end_connection);
	shared_ptr<connection> p(&c,
		[](connection *p) { disconnect(*p); });
}

//int main()
//{
//	destination d;
//
//	f(d);
//
//	f1(d);
//
//	return 0;
//}