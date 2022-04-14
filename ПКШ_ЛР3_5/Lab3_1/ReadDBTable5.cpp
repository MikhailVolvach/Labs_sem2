#include "stdafx.h"

namespace dbmsLib
{
	void ReadDBTable5(DBTableTxt& tab, string fileName) {
		tab.columnHeaders.clear();

		ifstream FILE(fileName);
		string line;
		getline(FILE, line);
		tab.tableName = line.substr(0, line.find_first_of('|'));
		tab.primaryKey = line.substr(line.find_first_of('|') + 1);
		cout << tab.tableName << '|' << tab.primaryKey << endl;

		getline(FILE, line);
		ColumnDesc Title;
		int i = 0;
		int cnt = 0;
		string word = "";
		line.push_back('|');
		while (i < line.length())
		{
			if (line[i] != '|' && line[i] != '\0' && line[i] != '\n')
			{
				word += line[i];
			}
			else
			{
				switch (cnt)
				{
				case 0: {
					strcpy(Title.colName, word.c_str());
					cout << Title.colName << endl;
					word = "";
					cnt++;
					break;
				}
				case 1: {
					if (word == "NoType")
					{
						Title.colType = NoType;
					}
					if (word == "Int32")
					{
						Title.colType = Int32;
					}
					if (word == "Double")
					{
						Title.colType = Double;
					}
					if (word == "String")
					{
						Title.colType = String;
					}
					if (word == "Date")
					{
						Title.colType = Date;
					}
					word = "";
					cnt++;
					break;

				}
				case 2: {
					Title.length = stoi(word);
					tab.columnHeaders[Title.colName] = Title;
					word = "";
					cnt++;
					break;
				}
				default:
					break;
				}
				cnt %= 3;
			}
			i++;
		}

		pair<string, void*> parRow;
		while (!FILE.eof())
		{
			Row row = *(new Row);
			getline(FILE, line);
			i = 0;
			for (auto it = tab.columnHeaders.begin(); it != tab.columnHeaders.end(); it++)
			{
				string word = "";
				while (line[i] != '|' && line[i] != '\0' && line[i] != '\n')
				{
					if (line[i] != ' ')
					{
						word += line[i];
					}
					i++;
				}

				if (line[i] == '|')
				{
					i++;
				}
				
				if (word.size())
				{
					parRow.first = it->first;
					parRow.second = GetValue(word, it->second.colName, tab.columnHeaders);

					row.insert(parRow);
				}
			}
			if (row.size())
			{
				tab.data.push_back(row);
			}
		}
		FILE.close();
	}

}
