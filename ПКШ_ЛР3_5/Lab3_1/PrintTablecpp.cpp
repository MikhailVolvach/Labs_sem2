#include "dbmsLib5.h"

namespace dbmsLib5 {
	void DBTableTxt::PrintTable(int screenWidth)
	{
		//cout << "Таблица " << this->GetTableName() << endl;
		//cout << fill("=") << setw(screenWidth) << endl;

		cout << "Таблица " << this->tableName << endl;
		cout << setfill('=') << setw(screenWidth - 1) << "=" << setfill(' ') << endl;
		for (size_t i = 0; i < this->data.size(); i++)
		{
			for (auto it = data[i].begin(); it != data[i].end(); ++it)
			{
				cout << &(it->second) << " ";
			}
			cout << endl;
		}
		//			  Group		  Name	    StudentID
		//			String		String			Int32	
		/*cout << "\tGroup\tName\tStudentID" << endl;
		cout << "\tString\tString\tInt32" << endl;*/
		cout << setfill('-') << setw(screenWidth - 1) << "-" << setfill(' ') << endl;
		cout << "\tДанные таблицы" << endl;
		cout << setfill('=') << setw(screenWidth - 1) << "=" << setfill(' ') << endl;
	}
}