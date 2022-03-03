#include <iostream>
#include <iomanip>
#include "dbmsLib5.h"
using namespace std;

typedef dbmsLib5::DBDate5 Date5;

int menu() {
	cout << "================= МАКЕТ СУБД ===================\n";
	cout << "\t1 - Создание объектов DBDate1 и проверка конструкторов\n";
	cout << "\t2 - Перегрузка и тестирование логических операторов сравнения\n";
	cout << "\t3 - Перегрузка и тестирование оператора DBDate1& operator+=(int days)\n"; 
	cout << "\t4 - Перегрузка и тестирование оператора DBDate1& operator-=(int days)\n"; 
	cout << "\t5 - Перегрузка и тестирование оператора int operator-(DBD1ate& date)\n";
	cout << "\t8 - Тестирование\n";
	cout << "\t10 - Выход\n";
	int choice;
	cout << "Выберите действие\n";
	cin >> choice;
	while (cin.fail()) {
		cout << "Ошибка ввода. Повторите ввод\n";
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

	cout << "Введите дату в формате дд.мм.гггг: "; cin >> date;
	testDate1 = Date5(date);

	cout << "Введите дату в формате дд.мм.гггг: "; cin >> date;
	testDate2 = Date5(date);

	cout << testDate1 << endl;
	cout << testDate2 << endl;

	// Операторы сравнения
	cout << "\tОператоры сравнения" << endl;
	cout << "testDate1 == testDate2: " << static_cast<int>(testDate1 == testDate2) << endl;
	cout << "testDate1 != testDate2: " << static_cast<int>(testDate1 != testDate2) << endl;
	cout << "testDate1 < testDate2: " << static_cast<int>(testDate1 < testDate2) << endl;
	cout << "testDate1 > testDate2: " << static_cast<int>(testDate1 > testDate2) << endl;
	cout << "testDate1 <= testDate2: " << static_cast<int>(testDate1 <= testDate2) << endl;
	cout << "testDate1 >= testDate2: " << static_cast<int>(testDate1 >= testDate2) << endl;

	// Прибаваить/вычесть кол-во дней из даты
	cout << "\tПрибаваить/вычесть кол-во дней из даты" << endl;
	cout << "Введите кол-во дней, которые надо прибавить к дате: "; cin >> daysAmnt;
	cout << testDate1 << " + " << daysAmnt << " = ";
	testDate1 = testDate1 += daysAmnt;
	cout << testDate1 << endl;

	cout << "Введите кол-во дней, которые надо вычесть из даты: "; cin >> daysAmnt;
	cout << testDate2 << " - " << daysAmnt << " = ";
	testDate2 = testDate2 += daysAmnt;
	cout << testDate2 << endl;

	// Разность дат
	cout << "\tРазность дат" << endl;
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
			cout << "Date1 до сложения: ";
			dateOut(date1, 1);
			date1 = date1 += 200;
			cout << "Date1+=200 = "; 
			dateOut(date1, 1);
			break;
		case 4: 
			cout << "Date2 до вычитания: ";
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
		case 10: return 0;//завершение работы
		default:cout << "Недопустимое действие. Повторите выбор\n";
			break;
		}
	}
	return 0;
}