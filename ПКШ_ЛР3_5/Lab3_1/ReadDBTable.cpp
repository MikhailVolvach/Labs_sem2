#include "dbmsLib5.h"

namespace dbmsLib5 {
	void DBTableTxt::ReadDBTable(string tabName)
	{
		//cout << tabName << endl;
		ifstream FILE(tabName);
		string line;
		getline(FILE, line);  // Первая строка
		this->tableName = line.substr(0, line.find_first_of('|'));

		getline(FILE, line);  // Вторая строка
		ColumnDesc Title;
		int i = 0;
		int cnt = 0;
		string word = "";
		line.append("|");
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
					cout << "Title.colName = " << Title.colName << endl;
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
					cout << "Title.coltype = " << Title.colType << endl;
					word = "";
					cnt++;
					break;

				}
				case 2: {
					Title.length = stoi(word);
					cout << "Title.length = " << Title.length << endl;
					word = "";
					cnt++;
					break;
				}
				default:
					break;
				}
			}

			if (cnt == 2)
			{
				this->columnHeaders[Title.colName] = Title;
			}
			cnt %= 3;
			i++;
		}

		i = 0;
		Row new_row;

		/*auto colName = this->columnHeaders.begin()->first;
		for (auto it = this->columnHeaders.begin(); it != this->columnHeaders.end(); ++it)
		{
			cout << it->second.colName << endl;
		}*/
		while (!FILE.eof())
		{
			getline(FILE, line);
			for (auto it = this->columnHeaders.begin(); it != this->columnHeaders.end(); it++)
			{
				new_row[it->second.colName] = "Данные";
			}
			this->data.push_back(new_row);
			//cout << line << endl;
			//for (size_t i = 0; i < this->columnHeaders.size(); i++)
			//{
			//	Header currentH = this->columnHeaders;
			//	auto a = currentH.begin();
			//	cout << a->first << endl;

			//	//new_row[this->columnHeaders - ];
			//}

			//auto colName2 = this->columnHeaders.end()->first;
			//cout << colName << " " /*<< colName2*/ << endl;
			//cout << colName->first << endl;
		}
	}
}