#include "dbmsLib5.h"

namespace dbmsLib5 {
	void DBTableTxt::PrintTable(int screenWidth)
	{
		cout << "Таблица " << this->tableName << endl;
		cout << setfill('=') << setw(screenWidth - 1) << "=" << setfill(' ') << endl;

		//for (size_t i = 0; i < this->data.size(); i++)
		//{
		//	//cout << "data.size() = " << data.size() << endl;
		//	for (auto rowIt = this->data[i].begin(); rowIt != this->data[i].end(); rowIt++)
		//	{
		//		cout << *static_cast<string*>(rowIt->second) << " | ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;


		for each (Row row in this->data)
		{
			for (auto rowIt = row.begin(); rowIt != row.end(); rowIt++)
			{
				//cout << static_cast<string*>(rowIt->second) << " | ";
				cout << rowIt->second << " | ";
			}
			cout << endl;
		}
		cout << endl;
		//			  Group		  Name	    StudentID
		//			String		String			Int32	
		/*cout << "\tGroup\tName\tStudentID" << endl;
		cout << "\tString\tString\tInt32" << endl;*/
	}
}