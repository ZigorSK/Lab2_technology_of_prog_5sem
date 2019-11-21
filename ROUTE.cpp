#include "ROUTE.h"

ROUTE::ROUTE(int d, string str1, string str2)
{
	num_of_route = d;
	begin_point = str1;
	end_point = str2;
}

ROUTE::ROUTE(const ROUTE & obg)
{
	num_of_route = obg.num_of_route;
	begin_point = obg.begin_point;
	end_point = obg.end_point;
}

ROUTE::~ROUTE()
{

}

istream & operator>>(istream & stream, ROUTE & obg)
{
	int d;
	string str;

	cout << "Введите номер маршрута:" << endl;
	cin >> d;
	obg.set_num_of_route(d);


	cout << endl << "Введите название начального пункта маршрута:" << endl;
	cin >> str;
	obg.set_begin_point(str);

	cout << endl << "Введите название конечного пункта маршрута:" << endl;
	cin >> str;
	obg.set_end_point(str);

	system("cls");
	return stream;
}

ostream & operator<<(ostream & stream, ROUTE & obg)
{
	cout << obg.get_num_of_route() << " - Номер маршрута." << endl;
	cout << obg.get_begin_point() << " - Начальный пункт маршрута." << endl;
	cout << obg.get_end_point() << " - Конечный пункт маршрута." << endl;

	return stream;
}
