//файл dbmsLib.h
#pragma once
#ifndef _dbmsLib5_
#define _dbmsLib5_
#include <iostream>
#include <strstream>
#include <iomanip>
#include <string>

using namespace std;
namespace dbmsLib5
{
	//-----------------класс DBDate5----------------------------
	class DBDate5
	{
		static const int arrDays[13];
		friend string DateToStr(DBDate5& date);
		friend ostream& operator<<(ostream& out, DBDate5& date);
		int day, month, year;
	public:
		DBDate5(string date);//формат строки: dd.mm.yyyy
		DBDate5(int d, int m, int y);
		DBDate5() :day(0), month(0), year(0) {};//конструктор по умолчанию
		DBDate5(DBDate5& dat) :day(dat.day), month(dat.month), year(dat.year) {}
		int GetDay();
		int GetMonth();
		int GetYear();
		//string DateToStr(DBDate5& date);
		bool IsLeapYear(int year); //год высокосный?
		int GetDaysInMonth(int month, int year);//Количество дней в месяце
		int DaysInCurYear();//Количество дней от начала года до текущей даты
		bool operator==(DBDate5& date);
		bool operator<(DBDate5& date);
		bool operator>(DBDate5& date);
		bool operator<= (DBDate5& date);
		bool operator>= (DBDate5& date);
		bool operator!= (DBDate5& date);
		DBDate5& operator+=(int days);//Прибавляет к текущей дате days дней
		DBDate5& operator-=(int days);//Вычитает из текущей даты days дней
		int operator-(DBDate5& date);	//Количество дней между текущей датой и date
									//Если текущая дата > date, результат < 0.
	};
}

#endif //конец _dbmsLib5_