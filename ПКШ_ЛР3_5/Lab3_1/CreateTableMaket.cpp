#include "dbmsLib5.h"

namespace dbmsLib5 {
	void DBTableTxt::CreateTableMaket(Strip*& strips, int& nStrip, int screenWidth)
	{
		Header::iterator headerIter, contHeaderIter;
		int nColumn = (int)columnHeaders.size();
		//���������� ������� ������ ����� ��� ������ ������� 
		int* fieldW = new int[nColumn];
		headerIter = columnHeaders.begin();
		for (int k = 0; k < nColumn; k++) {
			//��� ����: ��������� ��� ������?
			fieldW[k] = (headerIter->second.length > headerIter->first.size()) ?
				headerIter->second.length + 2 : headerIter->first.size() + 2;
			headerIter++;
		}
		int currCol = 0;//���������� ����� ������� � �������
		nStrip = 1;//����� ����� � ���������� �������
		int sumWidth = 0;//��������� ������ �������� � ������
		int n = 0;//����� �������� � ������
		int buff[40] = { 0 };//���������� � ��������� ������ ��� ���������� 
		//�������� ����� �������� � ������ (n<40)
		for (currCol = 0; currCol < nColumn; currCol++) {
			if (fieldW[currCol] >= screenWidth - 1) {
				cout << "������ ������� " << currCol << " ������ ������ ������\n";
				cout << "������� ������ �����������" << endl;
				nStrip = 0;
				return;
			}
			sumWidth += fieldW[currCol];
			if ((sumWidth < screenWidth - 1) && (currCol < nColumn - 1)) {
				n++;
				continue;
			}
			if ((sumWidth >= screenWidth - 1)) {//����� �� ������� ������ 
				currCol--;
				buff[nStrip - 1] = n;
				nStrip++;
				n = 0;
				sumWidth = 0;
				continue;
			}
			if (currCol == nColumn - 1) {//��������� ������
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
}