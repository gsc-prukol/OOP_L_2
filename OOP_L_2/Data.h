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
	Date(const Date & course);
	int GetD() { return day; }
	int GetM() { return month; }
	int GetY() { return year; }
//	~date() { cout << "~date()"<<endl; }
	Date & SetD(int d);
	Date & SetM(int m);
	Date & SetY(int y) { year = y; return *this; }
	friend ostream & operator << (ostream & left, const Date & right);
};
