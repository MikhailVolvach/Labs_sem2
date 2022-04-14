#include "dbmsLib5.h"

namespace dbmsLib5 {
	void DBTableTxt::AddRow(int index)
	{
		cout << "������� " << this->GetTableName() << endl;
		cout << "ID ��������� ������: " << this->data.size() << endl;
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
			cerr << "������������ ���� ������" << endl;
			return;
		}
		this->data.push_back(row);
	}
}