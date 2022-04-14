#include "dbmsLib5.h"

namespace dbmsLib5 {
	const char* DBTableTxt::TypeName(DBType type)
	{
		switch (type)
		{
		case dbmsLib5::NoType:
			return "NoType";
			break;
		case dbmsLib5::Int32:
			return "Int32";
			break;
		case dbmsLib5::Double:
			return "Double";
			break;
		case dbmsLib5::String:
			return "String";
			break;
		case dbmsLib5::Date:
			return "Date";
			break;
		default:
			return "";
			break;
		}
	}
}