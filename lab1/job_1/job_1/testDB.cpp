#include <iostream>
#include <iomanip>
#include "dbmsLib_v1_1.h"
using namespace std;
int menu(){
	cout<<"================= МАКЕТ СУБД ===================\n";
	cout<<"\t1 - Чтение таблицы из файла\n";
	cout<<"\t2 - Печать таблицы\n";
	cout<<"\t3 - Запись таблицы в файл\n";
	cout<<"\t4 - Добавление записи в таблицу\n";
	cout<<"\t5 - Перевести студента в другую группу\n";
	cout<<"\t6 - Распечатать фамилию студента, StudentID которого равен 3\n";
	cout<<"\t7 - Увеличить на 1 количество экземпляров всех книг в библиотеке \n";
	cout<<"\t8 - Тестирование\n";
	cout<<"\t10 - Выход\n"; 
	int choice;
	cout<<"Выберите действие\n";
	cin>>choice;
	while(cin.fail()){
	cout<<"Ошибка ввода. Повторите ввод\n";	
	cin.clear();
	cin.ignore(10,'\n');
	cin>>choice;
	}
	return choice;
}

//=================================================
int main(){
	system("chcp 1251>nul");
	//cout<<"Введите имя БД\n"; //"LibraryTxt" 
	//для удобства тестирования при отладке выполняем присваивание
	string dbName("LibraryTxt");
	//cin>>dbName;
	cout<<dbName<<endl;
	//cout<<"Введите имя таблицы БД\n";
	//"Students" "Abonements" "Books"- для LibraryTxt
	//для удобства тестирования при отладке выполняем присваивание
	string tabName("Students");	
	//cin>>tabName;
	dbmsLib::DBTableTxt tab;//создание пустой таблицы класса DBTableTxt,
		//определенного в подключенной к проекту библиотеке dbmsLib
	string path="..\\"+dbName+"\\";
	//	cout<<"Введите текущую дату dd.mm.yyyy\n";
	//для удобства тестирования при отладке выполняем присваивание
	string str("11.02.2020");
	//	cin>>str;
	dbmsLib::DBDate today(str);
	//	cout<<"Введите ширину экрана в символах\n";
	int screenWidth=78;
	//	cin>>screenWidth;
	
	while(true){
		switch(menu()){
		case 1: tab.ReadDBTable(path+tabName+".txt");//Чтение таблиц БД. 
			//БД хранится в папке "..\\"+dbName+". 
			//Имя БД оканчивается или на Txt, если таблицы БД хранятся в текстовых файлах,
			//Каждая таблица хранится в отдельном файле с именем = <имя таблицы>+".txt"
			//Структура файла:
			//Первая строка файла содержит имя таблицы и имя столбца с первичным ключем
			//Вторая строка файла - заголовок таблицы
			//Все последующие строки - записи таблицы. 
				break;
			case 2: tab.PrintTable(screenWidth);//Печать таблицы БД (screenWidth-ширина экрана)
				break;
			case 3:
				break;
			case 4: 
				break;
			case 5: 
				break;
			case 6: 
				break;
			case 7: 
				break;
			case 8:
				break;
			case 10: return 0;//завершение работы
			default:cout<<"Недопустимое действие. Повторите выбор\n"; 
				break;
		}
	}
		return 0;
}