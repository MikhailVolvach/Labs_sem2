#include <iostream>
#include <iomanip>
#include "dbmsLib5.h"
using namespace std;
int menu() {
	cout << "================= ����� ���� ===================\n";
	cout << "\t1 - ������ ������� �� �����\n";
	cout << "\t2 - ������ �������\n";
	/*cout << "\t3 - ������ ������� � ����\n";
	cout << "\t4 - ���������� ������ � �������\n";
	cout << "\t5 - ��������� �������� � ������ ������\n";
	cout << "\t6 - ����������� ������� ��������, StudentID �������� ����� 3\n";
	cout << "\t7 - ��������� �� 1 ���������� ����������� ���� ���� � ���������� \n";*/
	cout << "\t8 - ������������\n";
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

void testing() {
	/*string intStr("  12.3.2020   ");
	dbmsLib5::DBDate dat(intStr);
	cout << dat << endl;
	cout << "dbName=" << dbName << "  tabName=" << tabName << endl;
	string path = "..\\" + dbName + "\\";
	int screenWidth = 40;
	dbmsLib5::DBTableTxt tab;
	tab.ReadDBTable(path + tabName + ".txt");
	tab.PrintTable(screenWidth);
	string value = tab.valueToString(tab[0], "Author");
	int id;
	cout << *(string*)dbmsLib::GetValue(value, "Author", tab.GetHeader()) << endl;*/
	/*dbmsLib::Strip* strips;
	int nStrip;
	tab.CreateTableMaket(strips, nStrip,screenWidth);
	cout<<"nStrip="<<nStrip<<endl;
	for(int i=0;i<nStrip;i++){
		cout<<"strip="<<i<<endl;
		for(int j=0;j<strips[i].nField;j++)
			cout<<strips[i].fieldWidth[j]<<' ';
		cout<<endl;
	}*/
	/*string str2("  29.2.2021   ");
	dbmsLib5::DBDate5 datStr2;
	cout << "str2=" << str2 << " dat2=" << datStr2 << endl;
	cout << endl;
	dbmsLib5::DBDate5 datStr;
	cout << "str2=" << str2 << " dat2=" << datStr << endl;
	cout << endl;*/

	typedef dbmsLib5::DBDate5 Date5;

	Date5 date("29.2.2021");
	Date5 date2("09.02.2021");
	Date5 date3(29, 2, 2000);
	Date5 date4;


	date.GetDay();
	date2.GetMonth();
	date3.GetYear();

	cout << date4.GetDaysInMonth(2, 2000) << date4.GetDaysInMonth(2, 1999) << endl;
	//cout << 

}

//=================================================
int main() {
	system("chcp 1251>nul");
	//cout<<"������� ��� ��\n"; //"LibraryTxt" 
	//��� �������� ������������ ��� ������� ��������� ������������
	//string dbName("LibraryTxt");
	//cin>>dbName;
	//cout << dbName << endl;
	//cout<<"������� ��� ������� ��\n";
	//"Students" "Abonements" "Books"- ��� LibraryTxt
	//��� �������� ������������ ��� ������� ��������� ������������
	//string tabName("Students");
	//cin>>tabName;
	//dbmsLib::DBTableTxt tab;//�������� ������ ������� ������ DBTableTxt,
		//������������� � ������������ � ������� ���������� dbmsLib
	//string path = "..\\" + dbName + "\\";
	//	cout<<"������� ������� ���� dd.mm.yyyy\n";
	//��� �������� ������������ ��� ������� ��������� ������������
	//string str("11.02.2020");
	//	cin>>str;
	//dbmsLib::DBDate today(str);
	//	cout<<"������� ������ ������ � ��������\n";
	int screenWidth = 78;
	//	cin>>screenWidth;
	int ind;
	vector<int> indexes;
	while (true) {
		switch (menu()) {
		//case 1: tab.ReadDBTable(path + tabName + ".txt");//������ ������ ��. 
			//�� �������� � ����� "..\\"+dbName+". 
			//��� �� ������������ ��� �� Txt, ���� ������� �� �������� � ��������� ������,
			//������ ������� �������� � ��������� ����� � ������ = <��� �������>+".txt"
			//��������� �����:
			//������ ������ ����� �������� ��� ������� � ��� ������� � ��������� ������
			//������ ������ ����� - ��������� �������
			//��� ����������� ������ - ������ �������. 
			break;
		//case 2: tab.PrintTable(screenWidth);//������ ������� �� (screenWidth-������ ������)
			break;
		/*case 3: tab.WriteDBTable(path + tabName + ".txt");
			break;
		case 4: tab.AddRow(tab.CreateRow(), tab.GetSize());
			break;
		case 5:*(string*)tab[3]["Group"] = "IU5-24b";
			break;
		case 6: ind = 3;
			indexes = tab.IndexOfRecord(&ind, "StudentID");
			cout << *(string*)tab[indexes[0]]["Name"] << endl;
			break;
		case 7: tabName = "Books";
			tab.ReadDBTable(path + tabName + ".txt");
			for (int i = 0; i < tab.GetSize(); i++)
				(*(int*)tab[i]["Quantity"])++;
			break;*/
		case 8:testing();
			break;
		case 10: return 0;//���������� ������
		default:cout << "������������ ��������. ��������� �����\n";
			break;
		}
	}
	return 0;
}