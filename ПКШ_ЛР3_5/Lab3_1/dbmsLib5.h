#pragma once
#ifndef _dbmsLib5_
#define _dbmsLib5_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <strstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/* TODO:
* 1) Read

*/
namespace dbmsLib5 {
	//==================== Класс "Таблица макета СУБД" ===========================
	//--------DBType-перечисление типов полей таблиц БД------ 
	enum DBType {
		NoType,
		Int32,
		Double,
		String,
		Date
	};
	enum Condition { Undefined, Equal, NotEqual, Less, Greater, LessOrEqual, GreaterOrEqual };
	const int LENGTH = 24;//длина имени таблицы и имени столбца.
	//ColumnDesc - описание данных в столбце таблицы 
	//данные типа string имеют одинаковую длину (length) внутри одного столбца, 
	//но в разных столбцах их максимальный размер может отличаться
	struct ColumnDesc {
		char colName[LENGTH];//имя столбца
		DBType colType;//тип данных в столбце таблицы
		int length; //максимальное число символов, допустимое 
		//для представления данных в столбце
	};
	struct Strip {//полоса распечатки таблицы
		int nField;//число полей 
		int* fieldWidth;//ширина полей в полосе (массив)
	};
	typedef map<string, string> Row;
	typedef map<string, ColumnDesc> Header;

	string GetTabNameFromPath(string path);
	string ignoreBlanc(const string str);
	void* GetValue(string value, string columnName, Header hdr);
	void* SetValue(string value, string columnName, Header hdr);
	bool comparator(DBType type, void* obj1, Condition condition, void* obj);
	int GetLength(ColumnDesc colDesc);

	//------------------- класс DBTableTxt ----------------------
	class DBTableTxt {

		Header columnHeaders;
		string tableName;
		string primaryKey;
		vector<Row> data;
		string fileName;
	public:
		DBTableTxt() {}
		DBTableTxt(string tabName);
		DBTableTxt(string tabName, Header hdr, string primKey);
		const char* TypeName(DBType type);
		~DBTableTxt() {}
		vector<int> IndexOfRecord(void* keyValue, string keyColumnName);
		//string valueToString(Row& row, string columnName);
		void ReadDBTable(string tabName);//tabName=path+tableName
		void PrintTable(int screenWidth);
		void WriteDBTable(string tabName);//tabName=path+tableName	
		int GetSize();
		DBType GetType(char* columnName);
		Row operator[](int ind);
		void SetFileName(string path);
		void SetTableName(string tName);
		void SetPrimaryKey(string key);
		string GetFileName();
		string GetTableName();
		string GetPrimaryKey() { return primaryKey; }
		Header GetHeader();
		void SetHeader(Header& hdr);
		/*Row CreateRow();
		Row GetRow(int index);
		void AddRow(Row row, int index);*/
		//Макет распечатки таблицы:
		//screenWidth - ширина экрана (входной параметр)
		//nStrip - число полос в распечатке (выходной параметр)
		//strips[nStrip] - описание полос таблицы: 
		//число столбцов и ширина каждого столбца в полосе (выходной параметр)
		void CreateTableMaket(Strip*& strips, int& nStrip, int screenWidth);
		friend void ReadDBTable5(DBTableTxt& tab, string fileName);//fileName=path+tableName
		friend void PrintTable5(DBTableTxt& tab, int screenWidth);//fileName=path+tableName
	};
}

#endif //конец _dbmsLib5_