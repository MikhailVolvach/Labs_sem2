#include "dbmsLib5.h"

namespace dbmsLib5 {
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