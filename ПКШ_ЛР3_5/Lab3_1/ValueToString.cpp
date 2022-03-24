#include "dbmsLib5.h"

namespace dbmsLib5 {
	string DBTableTxt::valueToString(Row& row, string columnName)
	{
		char buf[80] = { 0 };
		if (this->columnHeaders.find(columnName) != this->columnHeaders.end())
		{
			void* value = row[columnName];//
			ostrstream os(buf, 80);
			switch (columnHeaders[columnName].colType) {
			case Int32: os << setw(8) << *(int*)value << '\0'; break;
			case Double: os << setw(12) << *(double*)value << '\0'; break;
			case String:os << setw(columnHeaders[columnName].length) <<
				ignoreBlanc(*(string*)value) << '\0'; break;
				//case Date: os << setw(12) << *(DBDate*)value << '\0'; break;
			default: cout << setw(8) << "NoType" << '\0';
				system("pause"); break;
			}
		}
		else
			cout << "column not found " << endl;
		return buf;
	}
}