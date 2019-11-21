#include<iostream>
#include"Header.h"
#include<fstream>

using namespace std;

int main()
{
	system("chcp 1251");
	int choice = 0;

	do
	{
		system("cls");
		cout << "�������� �������." << endl << "[0] ����� �� ���������." << endl << "[1] ����������� ������ (����� Route)." << endl
			<< "[2] �������� ������ (���������, ��������� ����� �� ����� ������ �� ���������� ���������� �����)." << endl;

		cin >> choice;
		switch (choice)
		{
		case 1://������� 1
		{
			try
			{
				int d;
				cout << "������� ���������� ���������:";
				cin >> d;
				if (d < 1)
					throw d;
				ArrayOfRoute obg(d);
				obg.menu();
			}
			catch(int d)
			{
				cout << d << " ��������� �� ����� ���� �������!!!" << endl;
				system("pause");
				system("cls");
			}
			break;
		}
		case 2://������� 2
		{
			try
			{
				int flag = 0;
				string str;
				ifstream input;
				input.open("file.txt", std::ios::in);

				if (!input.is_open())
					throw input;
				
				while(!input.eof())
				{
					flag = 0;
					getline(input, str);

					if (str.size() < 4)
					{
						if (str.size() == 2)
						{
							if (((str[0] >= '0') && (str[0] <= '9')) && ((str[1] >= '0') && (str[1] <= '9')))
							{
								flag = 1;
							}
						}
						else
						{
							if (str.size() == 3)
							{
								if (((str[0] >= '0') && (str[0] <= '9')) && ((str[1] >= '0') && (str[1] <= '9')) && ((str[2] == ' ') || (str[2] == '-') || (str[2] == '+') || (str[2] == '/') || (str[2] == '*')))
								{
									flag = 1;
								}
							}
						}
					}
					else
					{
						if (((str[0] >= '0') && (str[0] <= '9')) && ((str[1] >= '0') && (str[1] <= '9')) && ((str[2] == ' ') || (str[2] == '-') || (str[2] == '+') || (str[2] == '/') || (str[2] == '*')))
						{
							flag = 1;
						}
						else
						{
							if (((str[str.size() - 2] >= '0') && (str[str.size() - 2] <= '9')) && ((str[str.size() - 1] >= '0') && (str[str.size() - 1] <= '9')) && ((str[str.size() - 3] == ' ') || (str[str.size() - 3] == '-') || (str[str.size() - 3] == '+') || (str[2] == '/') || (str[str.size() - 3] == '*')))
							{
								flag = 1;
							}
							else
							{
								for (int i = 1; i < str.size() - 3; i++)
								{

									if (((str[i] >= '0') && (str[i] <= '9')) && ((str[i + 1] >= '0') && (str[i + 1] <= '9')) && ((str[i + 2] == ' ') || (str[i + 2] == '-') || (str[i + 2] == '+') || (str[i + 2] == '/') || (str[i + 2] == '*')) && ((str[i - 1] == ' ') || (str[i - 1] == '-') || (str[i - 1] == '+') || (str[i - 1] == '/') || (str[i - 1] == '*')))
									{
										flag = 1;
										break;
									}

								}
							}
						}
					}
					if (flag == 0)
						cout << str << endl;

				}
				system("pause");
				input.close();
			}
			catch( ifstream &input)
			{
				cout << "������� ����������, �� ������� ������� ����" << endl;
				system("pause");
				system("cls");
			}

			break;
		}
		case 0: break;

		default:
			cout << "������� ������� �������!" << endl;
			system("pause");
			system("cls");
		}

	} while (choice);

	return 0;
}