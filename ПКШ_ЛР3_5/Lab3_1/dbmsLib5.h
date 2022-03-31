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
	//==================== ����� "������� ������ ����" ===========================
	//--------DBType-������������ ����� ����� ������ ��------ 
	enum DBType {
		NoType,
		Int32,
		Double,
		String,
		Date
	};
	enum Condition { Undefined, Equal, NotEqual, Less, Greater, LessOrEqual, GreaterOrEqual };
	const int LENGTH = 24;//����� ����� ������� � ����� �������.
	//ColumnDesc - �������� ������ � ������� ������� 
	//������ ���� string ����� ���������� ����� (length) ������ ������ �������, 
	//�� � ������ �������� �� ������������ ������ ����� ����������
	struct ColumnDesc {
		char colName[LENGTH];//��� �������
		DBType colType;//��� ������ � ������� �������
		int length; //������������ ����� ��������, ���������� 
		//��� ������������� ������ � �������
	};
	struct Strip {//������ ���������� �������
		int nField;//����� ����� 
		int* fieldWidth;//������ ����� � ������ (������)
	};
	typedef map<string, string> Row;
	typedef map<string, ColumnDesc> Header;

	string GetTabNameFromPath(string path);
	string ignoreBlanc(const string str);
	void* GetValue(string value, string columnName, Header hdr);
	void* SetValue(string value, string columnName, Header hdr);
	bool comparator(DBType type, void* obj1, Condition condition, void* obj);
	int GetLength(ColumnDesc colDesc);

	//------------------- ����� DBTableTxt ----------------------
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
		//����� ���������� �������:
		//screenWidth - ������ ������ (������� ��������)
		//nStrip - ����� ����� � ���������� (�������� ��������)
		//strips[nStrip] - �������� ����� �������: 
		//����� �������� � ������ ������� ������� � ������ (�������� ��������)
		void CreateTableMaket(Strip*& strips, int& nStrip, int screenWidth);
		friend void ReadDBTable5(DBTableTxt& tab, string fileName);//fileName=path+tableName
		friend void PrintTable5(DBTableTxt& tab, int screenWidth);//fileName=path+tableName
	};
}

#endif //����� _dbmsLib5_