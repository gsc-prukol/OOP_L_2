#include <iostream>
#include <queue> 
#include <ctime>

using namespace std;
class future_date {};
class not_date {};
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
	friend bool operator < (const Date & l, const Date & right);
	bool operator == (Date & right);
	Date & operator = (const Date & r);
};
Date & Date::SetD(int D)
{
	day = ((D - 1) % 31) + 1;
	return *this;
}
Date & Date::SetM(int M)
{
	month = ((M - 1) % 12) + 1;
	year += (M - 1) / 12;
	return *this;
}
Date::Date()
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	day = timeinfo->tm_mday;
	month = timeinfo->tm_mon + 1;
	year = timeinfo->tm_year + 1900;
	//	cout << "date()" << endl;
}
Date::Date(int d, int m, int y)
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
 bool operator < (const Date & l, const Date & r)
{
	return l.year * 12 * 31 + l.month * 31 + l.day < r.year * 12 * 31 + r.month * 31 + r.day;
}
bool Date::operator == (Date & r)
{
	return (year == r.year) && (month == r.month) && (day == r.day);
}
Date & Date::operator = (const Date & r)
{
	year = r.year;
	day = r.day;
	month = r.month;
	return *this;
}
class PartyQueue
{
	string surname, phone;
	Date date;
public:
	PartyQueue();
	PartyQueue(string & Surname, string & Phone, Date & Date);
	PartyQueue( const  PartyQueue &  sourse);
	Date & GetD() { return date; }
	//	~PartyQueue();
	friend bool operator < (const PartyQueue & left, const PartyQueue & right);
};
class QueueHousing
{
	priority_queue <PartyQueue> data;
public:
	QueueHousing() {};
	QueueHousing(PartyQueue * sourse, int n);
	QueueHousing( PartyQueue & sourse);
	//	~QueueHousing();
	size_t longQueue() { return data.size(); }
	void push(PartyQueue & element);// { data.push(element); }
	void pop() { data.pop(); }
	PartyQueue  top();// {return  data.top(); }
};
PartyQueue   QueueHousing::top()
{
	PartyQueue c = data.top();
	try
	{
		if (Date() < c.GetD())
			throw future_date();
	}
	catch (future_date)
	{
		cerr << "Date is in future" << endl;
	}
	return c;
}
PartyQueue::PartyQueue()
{
	surname = string("Surname");
	phone = string("+1 202 - 456 - 1111");
//	date = Date();
}
PartyQueue::PartyQueue(string & Surname, string & Phone, Date & Date)
{
	surname = Surname;
	phone = Phone;
	date = Date;
}
PartyQueue::PartyQueue(const PartyQueue &  sourse)
{
	this->surname = sourse.surname;
	this->phone = sourse.phone;
	this->date = sourse.date;
}
/*PartyQueue::~PartyQueue()
{
//	surname.~string();
//	phone.~string();
	//date.~Date();
}*/
bool operator < (const PartyQueue & left,const PartyQueue & right)
{
	return left.date < right.date;
}
QueueHousing::QueueHousing( PartyQueue * sourse, int n)
{
	for (int i = 0; i < n; i++)
	{
		data.push(sourse[i]);
	}

}
void QueueHousing::push(PartyQueue & element)
{
	try 
	{
		if (!(element.GetD() == Date()))
			throw not_date();
		data.push(element);
	}
	catch (not_date)
	{
		cerr << "Date is incorect" << endl;
	}
//	data.push(element);
}

