#include <ctime>
#include <iostream>

using namespace std;

class Date
{
private:
	int year, month, day;
public:
	Date();
	Date(int d, int m, int y);
	Date(Date & course);
	int GetD() { return day; }
	int GetM() { return month; }
	int GetY() { return year; }
	Date & SetD(int d);
	Date & SetM(int m);
	Date & SetY(int y) { year = y; return *this; }
	friend ostream & operator << (ostream & left, const Date & right);
	bool operator < (Date & right);
	bool operator == (Date & right);
	Date & operator = (Date & right);
};
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
Date :: Date(int d, int m, int y)
{
	year = y;
	SetM(m);
	SetD(d);
}
Date::Date(Date & right)
{
	day = right.day;
	month = right.month;
	year = right.year;
}
ostream & operator << (ostream & left, const Date & right)
{
	left << right.day << '.' << right.month << '.' << right.year;
		return left;
}
bool Date::operator < (Date & r)
{
	return year * 12 * 31 + month * 31 + day < r.year * 12 * 31 + r.month * 31 + r.day;
}
bool Date::operator == (Date & r)
{
	return (year == r.year) && (month == r.month) && (day == r.day);
}

Date & Date::operator = (Date & r)
{
	year = r.year;
	day = r.day;
	month = r.month;
	return *this;
}
