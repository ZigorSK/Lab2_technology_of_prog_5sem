#include "ArrayOfRoute.h"

ArrayOfRoute::~ArrayOfRoute()
{
	delete[] arr;
}

void ArrayOfRoute::input_array()
{
	for (int i = 0; i < get_digit_of_route(); i++)
	{
		do
		{
			int flag = 0;

			cin >> *(arr + i);

			//�������� �� ������������ ��������������(������ ��������)
			for (int j = 0; j < i; j++)
			{
				if ((*(arr + j)).get_num_of_route() == (*(arr + i)).get_num_of_route())
				{
					cout << "����� ������� � �������, ������� ��� ����������, ������� ����� �������� ������!!!" << endl;
					system("pause");
					system("cls");
					flag = 1;
					break;
				}
			}

			if (flag == 0)
				break;

		} while (1);
	}

	//���������� �� ������ ��������

	for (int i = 0; i < get_digit_of_route(); i++) {
		bool flag = true;
		for (int j = 0; j < get_digit_of_route() - (i + 1); j++)
		{
			if ((*(arr + j)).get_num_of_route() > (*(arr + j + 1)).get_num_of_route())
			{
				flag = false;
				//swap num_of_route
				int swap;
				swap = (*(arr + j)).get_num_of_route();
				(*(arr + j)).set_num_of_route((*(arr + j + 1)).get_num_of_route());
				(*(arr + j + 1)).set_num_of_route(swap);
				//swap begin_point
				string swap_str;
				swap_str = (*(arr + j)).get_begin_point();
				(*(arr + j)).set_begin_point((*(arr + j + 1)).get_begin_point());
				(*(arr + j + 1)).set_begin_point(swap_str);
				//swap end_point
				swap_str = (*(arr + j)).get_end_point();
				(*(arr + j)).set_end_point((*(arr + j + 1)).get_end_point());
				(*(arr + j + 1)).set_end_point(swap_str);
			}
		}

		if (flag)
			break;
	}
}

void ArrayOfRoute::output_array()
{
	int choice = 0, flag = 0;
	string str;

	cout << "[0] ����� �� ����� ���������� � ���������, ������� ���������� � ������, �������� �������� ������� � ����������; " << endl;
	cout << "[1] ����� �� ����� ���������� � ���������, ������� ������������� � ������, �������� �������� ������� � ����������; " << endl;

	cin >> choice;
	cout << endl << "������� ����� ��������." << endl;
	cin >> str;
	cout << endl;
	cout << endl;

	do
	{
		if (choice == 1)//������������� �������
		{
			for (int i = 0; i < get_digit_of_route(); i++)
			{
				if ((*(arr + i)).get_end_point() == str)
				{
					cout << *(arr + i)<<endl;
					flag = 1;
				}
			}
		}
		else//����������
		{
			if (choice == 0)
			{

				for (int i = 0; i < get_digit_of_route(); i++)
				{
					if ((*(arr + i)).get_begin_point() == str)
					{
						cout << *(arr + i)<<endl;
						flag = 1;
					}
				}

			}
			else
			{
				cout << "������� �������� �������. ������� ������." << endl;
				system("pause");
				system("clc");
				continue;
			}
		}
		break;

	} while (1);

	if (flag == 0)
	{
		cout << "�� ���������� ���������, ��������������� ��������� ������." << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("pause");
		system("cls");
	}
}

void ArrayOfRoute::show()
{
	for (int i = 0; i < get_digit_of_route(); i++)
		cout << *(arr + i) << endl;

	system("pause");
	system("cls");
}

void ArrayOfRoute::menu()
{
	int choice = 0;

	do
	{
		system("cls");
		cout << "[0] ��������� ���������� ������� �������." << endl
			<< "[1] ���� � ���������� ���������, ������ ����� ����������� �� ������� ���������." << endl
			<< "[2] ����� �� ����� ���������� � ���������, ������� ���������� ��� ��������� � ������, �������� �������� ������� � ����������" << endl
			<< "[3] ����� �� ����� ���� ���������." << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			input_array();
			break;
		case 2:
			output_array();
			break;
		case 3:
			show();
			break;
		case 0: break;

		default:
			cout << "������� ������� �������!" << endl;
			system("pause");
			system("cls");
		}

	} while (choice);
}
