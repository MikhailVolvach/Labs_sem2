#include "dbmsLib5.h"

namespace dbmsLib5 {
	string DBTableTxt::GetFileName()
	{
		return this->fileName;
	}
	string DBTableTxt::GetTableName()
	{
		return this->tableName;
	}
	Header DBTableTxt::GetHeader()
	{
		return this->columnHeaders;
	}
	DBType DBTableTxt::GetType(char* columnName)
	{
		return this->columnHeaders[columnName].colType;
	}
	string GetTabNameFromPath(string path)
	{
		char tName[100];
		int pos1 = path.find_last_of('\\');
		int pos2 = path.find_last_of('.');
		return path.substr(pos1, pos2 - pos1 - 1); // tName
	}
	Row DBTableTxt::GetRow(int index)
	{
		return this->data[index];
	}
	void* GetValue(string value, string columnName, Header hdr)
	{
		switch (hdr[columnName].colType)
		{
		case Int32:		return new int(stoi(value)); break;
		case Double:	return new double(stod(value)); break;
		case String:	return new string(value); break;
			//case Date:		return new DBDate(value); break;
		default: cout << "Недопустимый тип данных в столбце\n" <<
			columnName << endl;
		}
		return 0;
	}
	int GetLength(ColumnDesc colDesc)
	{
		return colDesc.length;
	}
	int DBTableTxt::GetSize()
	{
		return this->data.size();
	}
}