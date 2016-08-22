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
	//����dis�ر�
	cout << endl;
}

void end_connection(connection *p) { disconnect(*p); }

//ʹ��shared_ptr�İ汾
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