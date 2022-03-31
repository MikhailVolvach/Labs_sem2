#include "dbmsLib5.h"

namespace dbmsLib5 {
	void DBTableTxt::PrintTable(int screenWidth)
	{
		cout << "Таблица " << this->tableName << endl;
		cout << setfill('=') << setw(screenWidth - 1) << "=" << setfill(' ') << endl;

		// Строка с именами заголовков
		for each(auto colHeadersIt in this->columnHeaders)
		{
			auto colHeadersItVal = colHeadersIt.second;
			cout << setfill(' ') << setw(colHeadersItVal.length + 3) << colHeadersItVal.colName;
		}
		cout << endl;
		// Строка с типами данных в соответствующих столбцах
		for each (auto colHeadersIt in this->columnHeaders)
		{
			auto colHeadersItVal = colHeadersIt.second;
			cout << setfill(' ') << setw(colHeadersItVal.length + 3);
			switch (colHeadersItVal.colType)
			{
			case 0:
				cout << "NoType";
				break;
			case 1:
				cout << "Int32";
				break;
			case 2:
				cout << "Double";
				break;
			case 3:
				cout << "String";
				break;
			case 4:
				cout << "Date";
				break;
			default:
				break;
			}
			//cout << "  ";
		}
		cout << endl;

		cout << setfill('-') << setw(screenWidth - 1) << "-" << setfill(' ') << endl;


		for each (Row row in this->data)
		{
			for each (auto colHeadersIt in this->columnHeaders)
			{
				auto colHeadersItVal = colHeadersIt.second;
				cout << setfill(' ') << setw(colHeadersItVal.length + 3) << row[colHeadersItVal.colName];
			}
			cout << endl;
		}
		cout << setfill('=') << setw(screenWidth - 1) << "=" << setfill(' ') << endl;
	}
}