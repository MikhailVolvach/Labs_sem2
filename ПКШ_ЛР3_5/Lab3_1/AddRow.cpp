#include "dbmsLib5.h"

namespace dbmsLib5 {
	void DBTableTxt::AddRow(int index)
	{
		cout << "Таблица " << this->GetTableName() << endl;
		cout << "ID последней записи: " << this->data.size() << endl;
		pair<string, void*> parRow;
		Row row = (*new Row);

		string strData = "";
		for (auto it = this->columnHeaders.begin(); it != this->columnHeaders.end(); ++it)
		{
			cout << "Enter " << it->second.colName << ": "; cin >> strData;
			parRow.first = it->second.colName;
			parRow.second = GetValue(strData, it->second.colName, this->columnHeaders);

			row.insert(parRow);
		}
		if (!strData.size())
		{
			cerr << "Некорректный ввод данных" << endl;
			return;
		}
		this->data.push_back(row);
	}
}