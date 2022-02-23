#include <iostream>
#include <fstream>
#include <strstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include "dbmsLib5.h"

using namespace std;

// TODO:
// 1) День не должен быть больше максимального для конкретного месяца, но при этом учитывать високосный год (Конструкторы -> Проверка дня)

namespace dbmsLib5 {
	const int DBDate5::arrDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	DBDate5::DBDate5(string date) {
		int firstDotPos, LastDotPos;

		int tmp;

		firstDotPos = date.find_first_of(".");
		LastDotPos = date.find_last_of(".");

		// Проверка года
		tmp = atoi(date.substr(LastDotPos + 1).c_str());
		if (tmp > -1 && tmp < 9999)
		{
			this->year = tmp;
		}
		else
		{
			cerr << "Некорректно введён год: " << tmp << " - недопустимая запись!" << endl;
			exit(1);
		}

		tmp = atoi(date.substr(firstDotPos + 1, LastDotPos - firstDotPos - 1).c_str());
		if (tmp > 0 && tmp < 13)
		{
			this->month = tmp;
		}
		else
		{
			cerr << "Некорректно введён месяц: " << tmp << " - недопустимая запись!" << endl;
			exit(1);
		}

		tmp = atoi(date.substr(0, firstDotPos).c_str());
		if (tmp > 0 && tmp < 32)
		{
			this->day = tmp;
		}
		else 
		{
			cerr << "Некорректно введён день: " << tmp << " - недопустимая запись!" << endl;
			exit(1);
		}
		
		//this->day = atoi(date.substr(0, firstDotPos).c_str());
		//this->month = atoi(date.substr(firstDotPos + 1, LastDotPos - firstDotPos - 1).c_str());
		//this->year = atoi(date.substr(LastDotPos + 1).c_str());
		
		cout << this->day << " " << this->month << " " << this->year << endl;
	}
	DBDate5::DBDate5(int d, int m, int y)
	{

		if (y > -1 && y < 9999)
		{
			this->year = y;
		}
		else
		{
			cerr << "Некорректно введён год: " << y << " - недопустимая запись!" << endl;
			exit(1);
		}

		if (m > 0 && m < 13)
		{
			this->month = m;
		}
		else
		{
			cerr << "Некорректно введён месяц: " << m << " - недопустимая запись!" << endl;
			exit(1);
		}

		if (d > 0 && d < 32)
		{
			this->day = d;
		}
		else
		{
			cerr << "Некорректно введён день: " << d << " - недопустимая запись!" << endl;
			exit(1);
		}

		/*this->day = d;
		this->month = m;
		this->year = y;*/
		cout << this->day << " " << this->month << " " << this->year << endl;
	}
	int DBDate5::GetDay() {
		cout << this->day << endl;
		return this->day;
	}
	int DBDate5::GetMonth() {
		cout << this->month << endl;
		return this->month;
	}
	int DBDate5::GetYear() {
		cout << this->year << endl;
		return this->year;
	}
	bool DBDate5::IsLeapYear(int year) {
		if (year % 4 == 0)
		{
			return true;
		}
		return false;
	}
	int DBDate5::GetDaysInMonth(int month, int year) {
		/*if (!month)
		{
			month = DBDate5::GetMonth();
		}
		if (!year)
		{
			year = DBDate5::GetYear();
		}*/
		if (!DBDate5::IsLeapYear(year))
		{
			cout << DBDate5::arrDays[month] << endl;
			return DBDate5::arrDays[month];
		}
		else
		{
			if (month == 2)
			{
				cout << DBDate5::arrDays[month] + 1 << endl;
				return DBDate5::arrDays[month] + 1;
			}
		}
	}
	int DBDate5::DaysInCurYear() {
		int year = DBDate5::GetYear();
		if (DBDate5::IsLeapYear(year))
		{
			cout << 366 << endl;
			return 366;
		}
		else
		{
			cout << 365 << endl;
			return 365;
		}
	}
	/*bool DBDate5::operator==(DBDate5& date) {
		return true;
	}
	bool DBDate5::operator<(DBDate5& date) {
		return true;
	}
	bool DBDate5::operator>(DBDate5& date) {
		return true;
	}
	bool DBDate5::operator<=(DBDate5& date) {
		return true;
	}
	bool DBDate5::operator>=(DBDate5& date) {
		return true;
	}
	bool DBDate5::operator!=(DBDate5& date) {
		return true;
	}*/
	/*DBDate5& DBDate5::operator+=(int days) {
		cout << "+" << days << endl;
	}*/
	/*DBDate5& DBDate5::operator-=(int days) {
		cout << "-" << days << endl;
	}*/
	int DBDate5::operator-(DBDate5& date) {

		// Как работает: https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0

		int currDay = DBDate5::GetDay();
		int currMonth = DBDate5::GetMonth();
		int currYear = DBDate5::GetYear();

		int newDay = date.day;
		int newMonth = date.month;
		int newYear = date.year;

		int currA = (14 - currMonth) / 12;
		int currY = currYear + 4800 - currA;
		int currM = currMonth + 12 * currA - 3;
		int currJD = currDay + (153 * currM + 2) / 5 + 365 * currY + currY / 4 - currY / 100 + currY / 400;

		int newA = (14 - newMonth) / 12;
		int newY = newYear + 4800 - newA;
		int newM = newMonth + 12 * newA - 3;
		int newJD = newDay + (153 * newM + 2) / 5 + 365 * newY + newY / 4 - newY / 100 + newY / 400;

		return newJD - currJD;
	}
}