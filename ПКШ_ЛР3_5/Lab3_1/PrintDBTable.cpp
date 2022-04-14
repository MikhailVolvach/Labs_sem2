#include "stdafx.h"

namespace dbmsLib
{
	void PrintTable5(DBTableTxt& tab, int screenWidth) {
		// Получение макета страницы
		dbmsLib::Strip* strips;
		int nStrip;
		tab.CreateTableMaket(strips, nStrip, screenWidth);

		if (nStrip < 1)
		{
			cerr << "Данных нет" << endl;
			exit(1);
		}

		cout << "Таблица " << tab.tableName << endl;

		auto colHeadersIterSave = tab.columnHeaders.begin();

		string keySave = tab.data.begin()->begin()->first;
		size_t rowCnt = 0;
		for (size_t i = 0; i < nStrip; i++)
		{
			auto colHeadersIt = colHeadersIterSave;
			auto colHeadersIterTmp = colHeadersIterSave;
			auto rowIt = tab.data.begin()->begin();
			if (i > 0)
			{
				cout << "Продолжение таблицы " << tab.tableName << endl;
			}
			cout << setfill('=') << setw(screenWidth) << "=" << setfill(' ') << endl;
			// Вывод шапки таблицы
			size_t j = 0;
			for (colHeadersIt = colHeadersIterTmp; colHeadersIt != tab.columnHeaders.end() && j < strips[i].nField; ++colHeadersIt)
			{
				cout << setw(strips[i].fieldWidth[j]) << colHeadersIt->second.colName;
				++colHeadersIterSave;
				++j;
			}
			cout << endl;
			j = 0;
			for (colHeadersIt = colHeadersIterTmp; colHeadersIt != tab.columnHeaders.end() && j < strips[i].nField; ++colHeadersIt)
			{
				cout << setw(strips[i].fieldWidth[j]) << tab.TypeName(colHeadersIt->second.colType);
				j++;
			}
			cout << endl;

			cout << setfill('-') << setw(screenWidth) << "-" << setfill(' ') << endl;

			// Вывод содержимого таблицы
			for each(Row row in tab.data)
			{
				j = 0;
				for (colHeadersIt = colHeadersIterTmp; colHeadersIt != tab.columnHeaders.end() && j < strips[i].nField; ++colHeadersIt)
				{
					cout << setw(strips[i].fieldWidth[j]) << tab.valueToString(row, colHeadersIt->second.colName);
					++j;
				}
				cout << endl;
				++rowCnt;
			}
			cout << setfill('=') << setw(screenWidth) << "=" << setfill(' ') << endl;
		}
	}
}