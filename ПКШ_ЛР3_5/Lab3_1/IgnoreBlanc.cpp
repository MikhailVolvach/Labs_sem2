#include "dbmsLib5.h"

namespace dbmsLib5 {
	string ignoreBlanc(const string str)
	{
		string bufStr = str;
		int begStr = bufStr.find_first_not_of(' ');
		return bufStr.substr(begStr);
	}
}