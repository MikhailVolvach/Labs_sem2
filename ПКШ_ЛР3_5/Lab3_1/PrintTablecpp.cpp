#include "dbmsLib5.h"

namespace dbmsLib5 {
	void DBTableTxt::PrintTable(int screenWidth)
	{
		// ��������� ������ ��������
		Strip* strips;
		int nStrip;
		this->CreateTableMaket(strips, nStrip, screenWidth);

		if (nStrip < 1)
		{
			cerr << "������ ���" << endl;
			exit(1);
		}

		cout << "������� " << this->tableName << endl;

		auto colHeadersIterSave = this->columnHeaders.begin();

		string keySave = this->data.begin()->begin()->first;
		size_t rowCnt = 0;
		for (size_t i = 0; i < nStrip; i++)
		{
			auto colHeadersIt = colHeadersIterSave;
			auto colHeadersIterTmp = colHeadersIterSave;
			auto rowIt = this->data.begin()->begin();
			if (i > 0)
			{
				cout << "����������� ������� " << this->tableName << endl;
			}
			cout << setfill('=') << setw(screenWidth) << "=" << setfill(' ') << endl;
			// ����� ����� �������
			size_t j = 0;
			for (colHeadersIt = colHeadersIterTmp; colHeadersIt != this->columnHeaders.end() && j < strips[i].nField; ++colHeadersIt)
			{
				cout << setw(strips[i].fieldWidth[j]) << colHeadersIt->second.colName;
				++colHeadersIterSave;
				++j;
			}
			cout << endl;
			j = 0;
			for (colHeadersIt = colHeadersIterTmp; colHeadersIt != this->columnHeaders.end() && j < strips[i].nField; ++colHeadersIt)
			{
				cout << setw(strips[i].fieldWidth[j]) << this->TypeName(colHeadersIt->second.colType);
				j++;
			}
			cout << endl;

			cout << setfill('-') << setw(screenWidth) << "-" << setfill(' ') << endl;

			// ����� ����������� �������
			for each (Row row in this->data)
			{
				j = 0;
				for (colHeadersIt = colHeadersIterTmp; colHeadersIt != this->columnHeaders.end() && j < strips[i].nField; ++colHeadersIt)
				{
					cout << setw(strips[i].fieldWidth[j]) << this->valueToString(row, colHeadersIt->second.colName);
					++j;
				}
				cout << endl;
				++rowCnt;
			}
			cout << setfill('=') << setw(screenWidth) << "=" << setfill(' ') << endl;
		}
	}
}