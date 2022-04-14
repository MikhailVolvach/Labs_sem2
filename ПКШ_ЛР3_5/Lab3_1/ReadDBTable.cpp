#define _CRT_SECURE_NO_WARNINGS
#include "dbmsLib5.h"

namespace dbmsLib5 {
	void DBTableTxt::ReadDBTable(string tabName)
	{
		this->columnHeaders.clear();

		ifstream FILE(tabName);
		string line;
		getline(FILE, line);
		this->tableName = line.substr(0, line.find_first_of('|'));
		this->primaryKey = line.substr(line.find_first_of('|') + 1);

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
					this->columnHeaders[Title.colName] = Title;
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
			for (auto it = this->columnHeaders.begin(); it != this->columnHeaders.end(); it++)
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
					parRow.second = GetValue(word, it->second.colName, this->columnHeaders);

					row.insert(parRow);
				}
			}
			if (row.size())
			{
				this->data.push_back(row);
			}
		}
		FILE.close();
	}
}
