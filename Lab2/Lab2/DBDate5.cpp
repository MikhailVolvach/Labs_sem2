#include <iostream>
#include <fstream>
#include <strstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include "dbmsLib5.h"

using namespace std;

namespace dbmsLib5 {
	const int DBDate5::arrDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	DBDate5::DBDate5(string date) {
		int firstDotPos, LastDotPos;

		//cout << date << endl;
		
		firstDotPos = date.find_first_of(".");
		LastDotPos = date.find_last_of(".");
		
		this->day = atoi(date.substr(0, firstDotPos).c_str());
		this->month = atoi(date.substr(firstDotPos + 1, LastDotPos - firstDotPos - 1).c_str());
		this->year = atoi(date.substr(LastDotPos + 1).c_str());
		
		cout << this->day << " " << this->month << " " << this->year << endl;
	}
	DBDate5::DBDate5(int d, int m, int y)
	{
		this->day = d;
		this->month = m;
		this->year = y;
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
		int diff;
		return diff;
	}
}