#include "Data.h"
Date & Date::SetD(int D)
{
	day = ((D-1) % 31) + 1;
	SetM((D-1)/31);
	return *this;
}
Date & Date::SetM(int M)
{
	month = ((M-1) % 12) + 1;
	year += (M-1) / 12;
	return *this;
}
Date::Date()
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	day = timeinfo->tm_mday;
	month = timeinfo->tm_mon+1;
	year = timeinfo->tm_year + 1900;
//	cout << "date()" << endl;
}
Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
//	cout << "date(int d, int m, int y)" << endl;
}
Date::Date(const Date & right)
{
	day = right.day;
	month = right.month;
	year = right.year;
//	cout << "date(date & right)" << endl;
}
ostream & operator << (ostream & left, const Date & right)
{
	left << right.day << '.' << right.month << '.' << right.year;
		return left;
}
bool Date::operator < (Date & r)
{
	return year * 12 * 31 + month * 31 + day < r.year * 12 * 31 + r.month * 31 + r.day
}
bool Date::operator == (Date & r)
{
	return (year == r.year) && (month == r.month) && (day == r.day);
}