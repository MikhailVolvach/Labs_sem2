#include "dbmsLib5.h"

using namespace std;

namespace dbmsLib5 {
	
	//****************************************************
	// Класс DBTableTxt
	//****************************************************
	// Конструкторы
	DBTableTxt::DBTableTxt(string tabName)
	{
		this->tableName = tabName;
	}
	DBTableTxt::DBTableTxt(string tabName, Header hdr, string primKey)
	{
		this->tableName = tabName;
		this->columnHeaders = hdr;
		this->primaryKey = primKey;
	}

	// Геттеры
	string DBTableTxt::GetFileName()
	{
		return this->fileName;
	}
	string DBTableTxt::GetTableName()
	{
		return this->tableName;
	}
	Header DBTableTxt::GetHeader()
	{
		return this->columnHeaders;
	}
	DBType DBTableTxt::GetType(char* columnName)
	{
		return this->columnHeaders[columnName].colType;
	}
	string GetTabNameFromPath(string path)
	{
		char tName[100];
		int pos1 = path.find_last_of('\\');
		int pos2 = path.find_last_of('.');
		//	strcpy_s(tName,100,path.c_str());
		//	tName[pos2]='\0';
		//	strcpy_s(tName,80,tName+pos1+1);
		return path.substr(pos1, pos2 - pos1 - 1); // tName
	}
	Row DBTableTxt::GetRow(int index)
	{
		return Row();
	} // Реализовать
	void* GetValue(string value, string columnName, Header hdr)
	{
		switch (hdr[columnName].colType)
		{
		case Int32:		return new int(stoi(value)); break;
		case Double:	return new double(stod(value)); break;
		case String:	return new string(value); break;
			//case Date:		return new DBDate(value); break;
		default: cout << "Недопустимый тип данных в столбце\n" <<
			columnName << endl;
		}
		return 0;
	}
	int GetLength(ColumnDesc colDesc)
	{
		return 0;
	}
	int DBTableTxt::GetSize()
	{
		return 0;
	}

	// Сеттеры
	void DBTableTxt::SetFileName(string path)
	{
		this->fileName = path.substr(path.find_last_of('/'));
	}
	void DBTableTxt::SetTableName(string tName)
	{
		this->tableName = tName;
	}
	void DBTableTxt::SetPrimaryKey(string key)
	{
		this->primaryKey = key;
	}
	void DBTableTxt::SetHeader(Header& hdr)
	{
		this->columnHeaders = hdr;
	}
	void* SetValue(string value, string columnName, Header hdr)
	{
		return nullptr;
	}

	// Чтение из файла
	void DBTableTxt::ReadDBTable(string tabName)
	{
		//cout << tabName << endl;
		ifstream FILE(tabName);
		while (!FILE.eof())
		{
			string line;
			getline(FILE, line);  // Первая строка
			this->tableName = line.substr(0, line.find_first_of('|'));

			getline(FILE, line);  // Вторая строка
			ColumnDesc Title;
			int i = 0;
			int cnt = 0;
			string word = "";
			while (line[i] != ' ' || line[i] != '\n')
			{
				if (line[i] != '|')
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
						//strcpy(Title.colType)
						if (word == "NoType")
						{
							Title.colType = NoType;
							word = "";
							cnt++;
							break;
						}
						if (word == "Int32")
						{
							Title.colType = Int32;
							word = "";
							cnt++;
							break;
						}
						if (word == "Double")
						{
							Title.colType = Double;
							word = "";
							cnt++;
							break;
						}
						if (word == "String")
						{
							Title.colType = String;
							word = "";
							cnt++;
							break;
						}
						if (word == "Date")
						{
							Title.colType = Date;
							word = "";
							cnt++;
							break;
						}
						cout << "Title.coltype = " << Title.colType << endl;
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

		}
	}
	
	// Вывод на экран
	void DBTableTxt::PrintTable(int screenWidth)
	{
		//cout << "Таблица " << this->GetTableName() << endl;
		//cout << fill("=") << setw(screenWidth) << endl;

		cout << "Таблица " << this->tableName << endl;
		cout << setfill('=') << setw(screenWidth - 1) << "=" << setfill(' ') << endl;
		//			  Group		  Name	    StudentID
		//			String		String			Int32	
		cout << "\tGroup\tName\tStudentID" << endl;
		cout << "\tString\tString\tInt32" << endl;
		cout << setfill('-') << setw(screenWidth - 1) << "-" << setfill(' ') << endl;
		cout << "\tДанные таблицы" << endl;
		cout << setfill('=') << setw(screenWidth - 1) << "=" << setfill(' ') << endl;
	}

	// Запись в файл
	void DBTableTxt::WriteDBTable(string tabName)
	{
	}


	const char* DBTableTxt::TypeName(DBType type)
	{
		return nullptr;
	}

	vector<int> DBTableTxt::IndexOfRecord(void* keyValue, string keyColumnName)
	{
		return vector<int>();
	}

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

	

	Row DBTableTxt::operator[](int ind)
	{
		return Row();
	}
	
	Row DBTableTxt::CreateRow()
	{
		return Row();
	}

	void DBTableTxt::AddRow(Row row, int index)
	{
	}

	void DBTableTxt::CreateTableMaket(Strip*& strips, int& nStrip, int screenWidth)
	{
		Header::iterator headerIter, contHeaderIter;
		int nColumn = (int)columnHeaders.size();
		//Заполнение массива ширины полей для печати таблицы 
		int* fieldW = new int[nColumn];
		headerIter = columnHeaders.begin();
		for (int k = 0; k < nColumn; k++) {
			//что шире: заголовок или данные?
			fieldW[k] = (headerIter->second.length > headerIter->first.size()) ?
				headerIter->second.length + 2 : headerIter->first.size() + 2;
			headerIter++;
		}
		int currCol = 0;//порядковый номер столбца в таблице
		nStrip = 1;//число полос в распечатке таблицы
		int sumWidth = 0;//суммарная ширина столбцов в полосе
		int n = 0;//число столбцов в полосе
		int buff[40] = { 0 };//объявление и обнуление буфера для временного 
		//хранения числа столбцов в полосе (n<40)
		for (currCol = 0; currCol < nColumn; currCol++) {
			if (fieldW[currCol] >= screenWidth - 1) {
				cout << "Ширина столбца " << currCol << " больше ширины экрана\n";
				cout << "Таблицу нельзя распечатать" << endl;
				nStrip = 0;
				return;
			}
			sumWidth += fieldW[currCol];
			if ((sumWidth < screenWidth - 1) && (currCol < nColumn - 1)) {
				n++;
				continue;
			}
			if ((sumWidth >= screenWidth - 1)) {//выход за границу экрана 
				currCol--;
				buff[nStrip - 1] = n;
				nStrip++;
				n = 0;
				sumWidth = 0;
				continue;
			}
			if (currCol == nColumn - 1) {//последняя полоса
				n++;
				buff[nStrip - 1] = n;
			}
		}
		strips = new Strip[nStrip];
		int col = 0;
		for (int i = 0; i < nStrip; i++) {
			strips[i].nField = buff[i];
			strips[i].fieldWidth = new int[strips[i].nField];
			for (int j = 0; j < strips[i].nField; j++)
				strips[i].fieldWidth[j] = fieldW[col++];
		}
	}



	string ignoreBlanc(const string str)
	{
		string bufStr = str;
		int begStr = bufStr.find_first_not_of(' ');
		return bufStr.substr(begStr);
	}

	bool comparator(DBType type, void* obj1, Condition condition, void* obj)
	{
		switch (type) {
		case Int32:
			switch (condition) {
			case	Equal:		return *(int*)obj1 == *(int*)obj;
			case NotEqual:		return *(int*)obj1 != *(int*)obj;
			case	 Less:		return *(int*)obj1 < *(int*)obj;
			case  Greater:		return *(int*)obj1 > *(int*)obj;
			case LessOrEqual:	return *(int*)obj1 <= *(int*)obj;
			case GreaterOrEqual:	 return *(int*)obj1 >= *(int*)obj;
			default: cout << "Недопустимая операция сравнения\n" << endl;
				return false;
			}
		case Double:
			switch (condition) {
			case	Equal:		return *(double*)obj1 == *(double*)obj;
			case NotEqual:		return *(double*)obj1 != *(double*)obj;
			case	 Less:		return *(double*)obj1 < *(double*)obj;
			case  Greater:		return *(double*)obj1 > *(double*)obj;
			case LessOrEqual:	return *(double*)obj1 <= *(double*)obj;
			case GreaterOrEqual: 	return *(double*)obj1 >= *(double*)obj;
			default: cout << "Недопустимая операция сравнения\n" << endl;
				return false;
			}
		case String: //пропуск ведущих пробелов в string
			switch (condition) {
			case	Equal:		return ignoreBlanc(*(string*)obj1) == ignoreBlanc(*(string*)obj);
			case NotEqual:		return ignoreBlanc(*(string*)obj1) != ignoreBlanc(*(string*)obj);
			case	 Less:		return ignoreBlanc(*(string*)obj1) < ignoreBlanc(*(string*)obj);
			case  Greater:		return ignoreBlanc(*(string*)obj1) > ignoreBlanc(*(string*)obj);
			case LessOrEqual:	return ignoreBlanc(*(string*)obj1) <= ignoreBlanc(*(string*)obj);
			case GreaterOrEqual: 	return ignoreBlanc(*(string*)obj1) >= ignoreBlanc(*(string*)obj);
			default: cout << "Недопустимая операция сравнения\n" << endl;
				return false;
			}
			/*case Date: switch (condition) {
			case	Equal:		return *(DBDate*)obj1 == *(DBDate*)obj2;
			case NotEqual:		return *(DBDate*)obj1 != *(DBDate*)obj2;
			case	 Less:		return *(DBDate*)obj1 < *(DBDate*)obj2;
			case  Greater:		return *(DBDate*)obj1 > *(DBDate*)obj2;
			case LessOrEqual:	return *(DBDate*)obj1 <= *(DBDate*)obj2;
			case GreaterOrEqual: return *(DBDate*)obj1 >= *(DBDate*)obj2;
			default: cout << "Недопустимая операция сравнения\n" << endl;
				return false;
			}*/

		default: cout << "Недопустимый тип данных\n" << endl;
			return false;
		}
	}
}