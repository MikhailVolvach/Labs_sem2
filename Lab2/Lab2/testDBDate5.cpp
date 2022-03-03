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
	Date5 testDate1;
	Date5 testDate2;
	Date5 testDate3;
	Date5 testDate4;

	string date;

	int daysAmnt = 0;

	cout << "������� ���� � ������� ��.��.����: "; cin >> date;
	testDate1 = Date5(date);

	cout << "������� ���� � ������� ��.��.����: "; cin >> date;
	testDate2 = Date5(date);

	cout << testDate1 << endl;
	cout << testDate2 << endl;

	// ��������� ���������
	cout << "\t��������� ���������" << endl;
	cout << "testDate1 == testDate2: " << static_cast<int>(testDate1 == testDate2) << endl;
	cout << "testDate1 != testDate2: " << static_cast<int>(testDate1 != testDate2) << endl;
	cout << "testDate1 < testDate2: " << static_cast<int>(testDate1 < testDate2) << endl;
	cout << "testDate1 > testDate2: " << static_cast<int>(testDate1 > testDate2) << endl;
	cout << "testDate1 <= testDate2: " << static_cast<int>(testDate1 <= testDate2) << endl;
	cout << "testDate1 >= testDate2: " << static_cast<int>(testDate1 >= testDate2) << endl;

	// ����������/������� ���-�� ���� �� ����
	cout << "\t����������/������� ���-�� ���� �� ����" << endl;
	cout << "������� ���-�� ����, ������� ���� ��������� � ����: "; cin >> daysAmnt;
	cout << testDate1 << " + " << daysAmnt << " = ";
	testDate1 = testDate1 += daysAmnt;
	cout << testDate1 << endl;

	cout << "������� ���-�� ����, ������� ���� ������� �� ����: "; cin >> daysAmnt;
	cout << testDate2 << " - " << daysAmnt << " = ";
	testDate2 = testDate2 += daysAmnt;
	cout << testDate2 << endl;

	// �������� ���
	cout << "\t�������� ���" << endl;
	cout << "testDate1 - testDate2 = " << testDate1 - testDate2 << endl;
}

void dateOut(Date5& date, int nomber) {
	cout << "Date" << nomber << ": day=" << date.GetDay() << " month=" << date.GetMonth() << " year=" << date.GetYear() << endl;
}

//=================================================
int main() {
	system("chcp 1251>nul");

	Date5 date1;
	Date5 date2;
	Date5 date3;
	Date5 date4;


	while (true) {
		switch (menu()) {
		case 1:
			//initializing();
			date1 = Date5("27.09.2001");
			date2 = Date5(13, 01, 1800);
			date4 = date1;

			dateOut(date1, 1);
			dateOut(date2, 2);
			dateOut(date3, 3);
			dateOut(date4, 4);
			break;
		case 2:
			cout << "date1 == date4: " << static_cast<int>(date1 == date4) << endl;
			cout << "date1 == date2: " << static_cast<int>(date1 == date2) << endl;
			cout << "date1 < date2: " << static_cast<int>(date1 < date2) << endl;
			cout << "date2 < date1: " << static_cast<int>(date2 < date1) << endl;
			cout << "date1 > date4: " << static_cast<int>(date1 > date4) << endl;
			cout << "date1 > date2: " << static_cast<int>(date1 > date2) << endl;
			cout << "date1 <= date2: " << static_cast<int>(date1 <= date2) << endl;
			cout << "date1 <= date4: " << static_cast<int>(date1 <= date4) << endl;
			cout << "date2 >= date1: " << static_cast<int>(date2 >= date1) << endl;
			cout << "date1 >= date4: " << static_cast<int>(date1 >= date4) << endl;
			cout << "date1 != date4: " << static_cast<int>(date1 != date4) << endl;
			cout << "date1 != date2: " << static_cast<int>(date1 != date2) << endl;
			//cout << ;
			break;
		case 3:
			cout << "Date1 �� ��������: ";
			dateOut(date1, 1);
			date1 = date1 += 200;
			cout << "Date1+=200 = "; 
			dateOut(date1, 1);
			break;
		case 4: 
			cout << "Date2 �� ���������: ";
			dateOut(date2, 2);
			date2 = date2 -= 300;
			cout << "Date2-=300 = ";
			dateOut(date2, 2);
			break;
		case 5:
			dateOut(date1, 1);
			dateOut(date2, 2);
			cout << "Date2 - Date1 = " << date1 - date2 << endl;
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