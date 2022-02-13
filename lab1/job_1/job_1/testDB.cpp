#include <iostream>
#include <iomanip>
#include "dbmsLib_v1_1.h"
using namespace std;
int menu() {
	cout << "================= ����� ���� ===================\n";
	cout << "\t1 - ������ ������� �� �����\n";
	cout << "\t2 - ������ �������\n";
	cout << "\t3 - ������ ������� � ����\n";
	cout << "\t4 - ���������� ������ � �������\n";
	cout << "\t5 - ��������� �������� � ������ ������\n";
	cout << "\t6 - ����������� ������� ��������, StudentID �������� ����� 3\n";
	cout << "\t7 - ��������� �� 1 ���������� ����������� ���� ���� � ���������� \n";
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
	dbmsLib::DBTableTxt tab;//�������� ������ ������� ������ DBTableTxt,
		//������������� � ������������ � ������� ���������� dbmsLib
	string path = "..\\" + dbName + "\\";
	//	cout<<"������� ������� ���� dd.mm.yyyy\n";
	//��� �������� ������������ ��� ������� ��������� ������������
	string str("11.02.2020");
	//	cin>>str;
	dbmsLib::DBDate today(str);
	//	cout<<"������� ������ ������ � ��������\n";
	int screenWidth = 78;
	//	cin>>screenWidth;
	string S = "";

	while (true) {
		switch (menu()) {
		case 1: tab.ReadDBTable(path + tabName + ".txt");//������ ������ ��. 
			//�� �������� � ����� "..\\"+dbName+". 
			//��� �� ������������ ��� �� Txt, ���� ������� �� �������� � ��������� ������,
			//������ ������� �������� � ��������� ����� � ������ = <��� �������>+".txt"
			//��������� �����:
			//������ ������ ����� �������� ��� ������� � ��� ������� � ��������� ������
			//������ ������ ����� - ��������� �������
			//��� ����������� ������ - ������ �������. 
			break;
		case 2: tab.PrintTable(screenWidth);//������ ������� �� (screenWidth-������ ������)
			break;
		case 3:
			tab.WriteDBTable(path + tabName + ".txt");
			break;
		case 4:
			tab.AddRow(tab.CreateRow(), tab.GetSize());
			break;
		case 5: // ��������� �������� � ������ ������
			/*for (auto& item : tab.GetRow(0))
			{
				cout << item.first << " : " << item.second << endl;
			}*/
			for (auto& item : tab[0])
			{
				cout << item.first << " : " << item.second << endl;
			}
			for (auto& item : tab[1])
			{
				cout << item.first << " : " << item.second << endl;
			}
			for (auto& item : tab[2])
			{
				cout << item.first << " : " << item.second << endl;
			}
			cout << "---------------------" << endl;
			cout << tab.valueToString(tab[0], "Group") << endl;
			cout << dbmsLib::GetValue(S, "Group", tab.GetHeader()) << " " << S << endl;
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 10: return 0;//���������� ������
		default:cout << "������������ ��������. ��������� �����\n";
			break;
		}
	}
	return 0;
}