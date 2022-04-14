#include "dbmsLib5.h"

using namespace std;
int menu() {
	cout << "================= ����� ���� ===================\n";
	cout << "\t1 - ������ ������� �� �����\n";
	cout << "\t2 - ������ �������\n";
	cout << "\t3 - ������ ������� � ����\n";
	cout << "\t4 - ���������� ������ � �������\n";
	//cout << "\t5 - ��������� �������� � ������ ������\n";
	cout << "\t5 - ����������� ������� ��������, StudentID �������� ����� 3\n";
	//cout << "\t6 - ��������� �� 1 ���������� ����������� ���� ���� � ���������� \n";
	cout << "\t6 - ������������\n";
	cout << "\t10 - �����\n";
	int choice;
	cout << "�������� ��������\n";
	cin >> choice;
	while (cin.fail()) {
		cout << "������ �����. ��������� ����\n";
		cin.clear();
		cin.ignore(10, '\n');
		cin >> choice;
	}
	return choice;
}

//-----------------------------------------------------------------

void testing(string dbName, string tabName) {
	//string intStr("  12.3.2020   ");
	//dbmsLib::DBDate dat(intStr);
	//cout << dat << endl;
	//cout << "dbName=" << dbName << "  tabName=" << tabName << endl;
	string path = "..\\" + dbName + "\\";
	int screenWidth = 40;
	dbmsLib5::DBTableTxt tab;
	tab.ReadDBTable(path + tabName + ".txt");
	tab.PrintTable(screenWidth);
	//tab.PrintTable(screenWidth);
	/*string value = tab.valueToString(tab[0], "Author");
	int id;
	cout << *(string*)dbmsLib5::GetValue(value, "Author", tab.GetHeader()) << endl;

	cout << "Test of CreateTableMaket" << endl;
	dbmsLib5::Strip* strips;
	int nStrip;
	tab.CreateTableMaket(strips, nStrip, screenWidth);
	cout << "nStrip = " << nStrip << endl;
	for (int i = 0; i < nStrip; i++) {
		cout << "strip = " << i << endl;
		cout << "nField = " << strips[i].nField << endl;
		for (int j = 0; j < strips[i].nField; j++)
			cout << strips[i].fieldWidth[j] << ' ';
		cout << endl;
	}*/

}

//=================================================
int main() {
	system("chcp 1251>nul");
	//cout<<"������� ��� ��\n"; //"LibraryTxt" 
	//��� �������� ������������ ��� ������� ��������� ������������
	string dbName("LibraryTxt");
	//cin>>dbName;
	cout << dbName << endl;
	//cout<<"������� ��� ������� ��\n";
	//"Students" "Abonements" "Books"- ��� LibraryTxt
	//��� �������� ������������ ��� ������� ��������� ������������
	string tabName("Students");
	//cin>>tabName;
	dbmsLib5::DBTableTxt tab;//�������� ������ ������� ������ DBTableTxt,
		//������������� � ������������ � ������� ���������� dbmsLib5
	string path = "..\\" + dbName + "\\";
	//	cout<<"������� ������� ���� dd.mm.yyyy\n";
	//��� �������� ������������ ��� ������� ��������� ������������
	string str("11.02.2020");
	//	cin>>str;
	//dbmsLib5::DBDate today(str);
	//	cout<<"������� ������ ������ � ��������\n";
	int screenWidth = 78;
	//	cin>>screenWidth;
	int ind;
	vector<int> indexes;
	while (true) {
		switch (menu()) {
		case 1: tab.ReadDBTable(path + tabName + ".txt");
			break;
		case 2: tab.PrintTable(screenWidth); 
			break;
		case 3: 
			tabName += "_copy";
			tab.WriteDBTable(path + tabName + ".txt");
			break;
		case 4: 
			tab.AddRow(tab.GetSize());
			break;
		/*case 5:
			*(string*)tab[3]["Group"] = "IU5-24b";
			break;*/
		case 5: 
			ind = 3;
			/*indexes = tab.IndexOfRecord(&ind, "StudentID");
			cout << *(string*)tab[indexes[0]]["Name"] << endl;*/
			cout << *(string*)tab.GetRow(ind - 1)["Name"] << endl;
			break;
		/*case 6: tabName = "Books";
			tab.ReadDBTable(path + tabName + ".txt");
			for (int i = 0; i < tab.GetSize(); i++)
				(*(int*)tab[i]["Quantity"])++;
			break;*/
		case 6:
			tabName = "Books";
			testing(dbName, tabName);
			break;
		case 10: return 0;//���������� ������
		default:cout << "������������ ��������. ��������� �����\n";
			break;
		}
	}
	return 0;
}