#include <iostream>
#include <iomanip>
#include "dbmsLib5.h"
using namespace std;

typedef dbmsLib5::DBDate5 Date5;

int menu() {
	cout << "================= ����� ���� ===================\n";
	cout << "\t1 - �������� �������� DBDate1 � �������� �������������\n";
	cout << "\t2 - ���������� � ������������ ���������� ���������� ���������\n";
	cout << "\t3 - ���������� � ������������ ��������� DBDate1& operator+=(int days)\n"; 
	cout << "\t4 - ���������� � ������������ ��������� DBDate1& operator-=(int days)\n"; 
	cout << "\t5 - ���������� � ������������ ��������� int operator-(DBD1ate& date)\n";
	cout << "\t8 - ������������\n";
	cout << "\t10 - �����\n";
	int choice;
	cout << "�������� ��������\n";
	cin >> choice;
	while (cin.fail()) {
		cout << "������ �����. ��������� ����\n";
		cin.clear();
		cin.ignore(10, '\n');
		cin >> choice;
	}
	return choice;
}

//-----------------------------------------------------------------

void testing() {

	Date5 date("03.03.2020");
	Date5 date2("09.09.2021");
	Date5 date3(29, 2, 2000);
	Date5 date4("12.01.2000");
	Date5 date5("7.05.2000");

	date4 = date4 += 20;
	cout << "+120 " << date4.GetDay() << "." << date4.GetMonth() << "." << date4.GetYear() << endl;
	date5 = date5 -= 100;
	cout << "-100 " << date5.GetDay() << "." << date5.GetMonth() << "." << date5.GetYear() << endl;

	//date.GetDay();
	//date2.GetMonth();
	//date3.GetYear();

	//cout << date4.GetDaysInMonth(2, 2000) << " " << date4.GetDaysInMonth(2, 1999) << endl;

	//cout << "������� " << date - date2 << endl;

	
	//cout << 

}

//=================================================

void initializing() {
	Date5 date1("03.02.2000");
	Date5 date2(29, 02, 2000);
	Date5 date3;
	Date5 dateCopy(date1);

	//cout << "���� 1: " << dbmsLib5::DateToStr(date1) << endl;s
}



int main() {
	system("chcp 1251>nul");

	while (true) {
		switch (menu()) {
		case 1:
			initializing();
			break;
		case 2:

			//cout << ;
			break;
		case 3:
			break;
		case 4: 
			break;
		case 5:
			break;
		case 8:testing();
			break;
		case 10: return 0;//���������� ������
		default:cout << "������������ ��������. ��������� �����\n";
			break;
		}
	}
	return 0;
}