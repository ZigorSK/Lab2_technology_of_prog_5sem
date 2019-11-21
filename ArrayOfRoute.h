#pragma once

#include"ROUTE.h"

class ArrayOfRoute
{
	ROUTE *arr;
	int digit_of_route;
public:
	ArrayOfRoute() : arr(nullptr) {};
	ArrayOfRoute(int quantity) : arr(new ROUTE[quantity]), digit_of_route(quantity) {};
	~ArrayOfRoute();

	//accessor methods
	void set_arr(ROUTE *d) { arr = d; };
	ROUTE *get_arr() { return arr; };

	void set_digit_of_route(int d) { digit_of_route = d; };
	int get_digit_of_route() { return digit_of_route; };

	void input_array();
	void output_array();
	void show();
	void menu();

};