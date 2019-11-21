#pragma once
#include<string>
#include<iostream>

using namespace std;

class ROUTE
{
	int num_of_route;
	string begin_point;
	string end_point;

public:

	ROUTE() : num_of_route(0), begin_point("Begin point undefined"), end_point("End point undefined") {};
	ROUTE(int d, string str1 = "Пункт А", string str2 = "Пункт B");
	ROUTE(const ROUTE &obg);
	~ROUTE();
	//setters
	void set_num_of_route(int data) { num_of_route = data; };
	void set_begin_point(string data) { begin_point = data; };
	void set_end_point(string data) { end_point = data; };

	//getters
	int get_num_of_route() { return num_of_route; };
	string get_begin_point() { return begin_point; };
	string get_end_point() { return end_point; };

	//Оператор вставки
	friend istream &operator>>(istream &stream, ROUTE &obg);
	//Оператор извлечения
	friend ostream &operator<<(ostream &stream, ROUTE &obg);

};