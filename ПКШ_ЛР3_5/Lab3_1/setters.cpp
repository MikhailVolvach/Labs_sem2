#include "dbmsLib5.h"

namespace dbmsLib5 {
	void DBTableTxt::SetFileName(string path) {
		this->fileName = path.substr(path.find_last_of('/'));
	}
	void DBTableTxt::SetTableName(string tName)
	{
		this->tableName = tName;
	}
	void DBTableTxt::SetPrimaryKey(string key)
	{
		this->primaryKey = key;
	}
	void DBTableTxt::SetHeader(Header& hdr)
	{
		this->columnHeaders = hdr;
	}
	void* SetValue(string value, string columnName, Header hdr)
	{
		return nullptr;
	}
}