#include "dbmsLib5.h"

using namespace std;

namespace dbmsLib5 {
	// Конструкторы
	DBTableTxt::DBTableTxt(string tabName)
	{
		this->tableName = tabName;
	}
	DBTableTxt::DBTableTxt(string tabName, Header hdr, string primKey)
	{
		this->tableName = tabName;
		this->columnHeaders = hdr;
		this->primaryKey = primKey;
	}
}