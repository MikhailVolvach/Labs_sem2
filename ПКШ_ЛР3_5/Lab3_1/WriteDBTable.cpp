#include "stdafx.h"

namespace dbmsLib {
	void WriteDBTable5(DBTableTxt& tab, string fileName)
	{
		ofstream File(fileName);

		File << tab.tableName << "|" << tab.primaryKey << endl;
		for (auto colHeadersIt = tab.columnHeaders.begin(); colHeadersIt != tab.columnHeaders.end(); ++colHeadersIt)
		{
			auto colHeadersItVal = colHeadersIt->second;
			File << colHeadersItVal.colName << "|" << tab.TypeName(colHeadersItVal.colType) << "|" << colHeadersItVal.length << "|";
		}
		File << endl;

		for each (Row row in tab.data)
		{
			for (auto rowIt = row.begin(); rowIt != row.end(); ++rowIt)
			{
				auto colHeadersItVal = rowIt->second;
				File << setfill(' ') << setw(tab.columnHeaders[rowIt->first].length) << tab.valueToString(row, rowIt->first) << "|";
			}
			File << endl;
		}
		File.close();
	}
}