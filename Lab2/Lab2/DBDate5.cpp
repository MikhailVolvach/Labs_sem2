#include <iostream>
#include <strstream>
#include <iomanip>
#include <string>
#include "dbmsLib5.h"

using namespace std;

// TODO:
// 1) День не должен быть больше максимального для конкретного месяца, но при этом учитывать високосный год (Конструкторы -> Проверка дня)

namespace dbmsLib5
{
	const int DBDate5::arrDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
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
			if (this->month == 2 && !IsLeapYear(this->year) && tmp >= 29)
			{
				cerr << "Неккоректно введён день: для " << this->year << "года 29 февраля быть не может" << endl;
				exit(1);
			}
			this->day = tmp;
		}
		else
		{
			cerr << "Некорректно введён день: " << tmp << " - недопустимая запись!" << endl;
			exit(1);
		}

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
			if (this->month == 2 && !IsLeapYear(this->year) && d >= 29)
			{
				cerr << "Неккоректно введён день: для " << this->year << " года 29 февраля быть не может" << endl;
				exit(1);
			}
			this->day = d;
		}
		else
		{
			cerr << "Некорректно введён день: " << d << " - недопустимая запись!" << endl;
			exit(1);
		}

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
	string dbmsLib5::DateToStr(DBDate5& date)
	{
		return to_string(date.day) + "." + to_string(date.month) + "." + to_string(date.year);
	}
	bool DBDate5::IsLeapYear(int year) {
		if (year % 4 == 0)
		{
			return true;
		}
		return false;
	}
	int DBDate5::GetDaysInMonth(int month, int year) {

		if (!this->IsLeapYear(year))
		{
			cout << this->arrDays[month] << endl;
			return this->arrDays[month];
		}
		else
		{
			if (month == 2)
			{
				cout << this->arrDays[month] + 1 << endl;
				return this->arrDays[month] + 1;
			}
		}
	}
	int DBDate5::DaysInCurYear() {
		int amnt = 0;

		int Year = this->year;
		int Month = this->month;
		int Day = this->day;

		for (size_t i = 1; i < Month; i++)
		{
			amnt += arrDays[i];
		}
		amnt += Day;
		if (IsLeapYear(Year) && month > 2)
		{
			amnt++;
		}

		return amnt;

	}
	bool DBDate5::operator==(DBDate5& date) {
		if ((date.year == this->year) && (date.month == this->month) && (date.day == this->day)) return true;
		return false;

	}
	bool DBDate5::operator<(DBDate5& date) {
		int currYear = this->year;
		int currMonth = this->month;
		int currDay = this->day;

		int newYear = date.year;
		int newMonth = date.month;
		int newDay = date.day;

		if (currYear > newYear) return true;

		if (currYear == newYear)
		{
			if (currMonth > newMonth) return true;

			if (currMonth == newMonth)
			{
				if (currDay > newDay) return true;
				return false;
			}
			return false;
		}
		if (currYear > newYear) return true;

		return false;
	}
	bool DBDate5::operator>(DBDate5& date) {

		int currYear = this->year;
		int currMonth = this->month;
		int currDay = this->day;

		int newYear = date.year;
		int newMonth = date.month;
		int newDay = date.day;

		if (currYear > newYear)
		{
			return true;
		}
		if (currYear == newYear)
		{
			if (currMonth > newMonth)
			{
				return true;
			}
			if (currMonth == newMonth)
			{
				if (currDay > newDay)
				{
					return true;
				}
				return false;
			}
			return false;
		}
		if (currYear > newYear)
		{
			return true;
		}
		return false;
	}
	bool DBDate5::operator<=(DBDate5& date) {

		int currYear = this->year;
		int currMonth = this->month;
		int currDay = this->day;

		int newYear = date.year;
		int newMonth = date.month;
		int newDay = date.day;

		if (currYear > newYear)
		{
			return false;
		}
		if (currYear < newYear)
		{
			return true;
		}
		if (currMonth > newMonth)
		{
			return false;
		}
		if (currMonth < newMonth)
		{
			return true;
		}
		if (currDay > newDay)
		{
			return false;
		}
		if (currDay <= newDay)
		{
			return true;
		}
		return false;
	}
	bool DBDate5::operator>=(DBDate5& date) {
		int currYear = this->year;
		int currMonth = this->month;
		int currDay = this->day;

		int newYear = date.year;
		int newMonth = date.month;
		int newDay = date.day;

		if (currYear < newYear)
		{
			return false;
		}
		if (currYear > newYear)
		{
			return true;
		}
		if (currMonth < newMonth)
		{
			return false;
		}
		if (currMonth > newMonth)
		{
			return true;
		}
		if (currDay < newDay)
		{
			return false;
		}
		if (currDay >= newDay)
		{
			return true;
		}
		return false;
	}
	bool DBDate5::operator!=(DBDate5& date) {
		int currDay = this->day;
		int currMonth = this->month;
		int currYear = this->year;

		int newDay = date.day;
		int newMonth = date.month;
		int newYear = date.year;

		if (currYear != newYear)
		{
			return true;
		}
		if (currMonth != newMonth)
		{
			return true;
		}
		if (currDay != newDay)
		{
			return true;
		}

		return false;
	}
	DBDate5& DBDate5::operator+=(int days) {
		int currDay = this->day;
		int currMonth = this->month;
		int currYear = this->year;

		int cnt = 0;

		int currMonthDays = 0;

		days += currDay;
		currDay = 0;
		while (days >= 28)
		{
			currMonthDays = arrDays[currMonth];
			days -= currMonthDays;
			if (currMonth == 2 && IsLeapYear(currYear))
				days--;
			currMonth++;
			currYear += currMonth / 13;
			currMonth %= 13;
		}
		currDay += days;



		DBDate5 NewDate(currDay, currMonth, currYear);
		return NewDate;
	}
	DBDate5& DBDate5::operator-=(int days) {
		int currDay = this->day;
		int currMonth = this->month;
		int currYear = this->year;

		days -= currDay;
		currDay = 0;

		int currMonthDays = 0;
		currMonth--;
		/*while (days >= 28)
		{
			currMonthDays = arrDays[currMonth];
			days -= currMonthDays;
			if (currMonth == 2 && IsLeapYear(currYear))
			{

			}
			currDay = arrDays[currMonth];
			
			
			currMonth--;
			if (currMonth == 0) {
				currMonth = 12;
				currYear--;
			}

		}*/
		while (days >= 28)
		{
			currMonthDays = arrDays[currMonth];
			days -= currMonthDays;
			if (currMonth == 2 && IsLeapYear(currYear))
			{
				days--;
			}
			currMonth--;
			if (currMonth == 0)
			{
				currMonth = 12;
				currYear--;
			}
		}


		currDay = arrDays[currMonth] - days;

		DBDate5 NewDate(currDay, currMonth, currYear);
		return NewDate;
	}
	int DBDate5::operator-(DBDate5& date) {

		// Как работает: https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0

		int currDay = this->day;
		int currMonth = this->month;
		int currYear = this->year;

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