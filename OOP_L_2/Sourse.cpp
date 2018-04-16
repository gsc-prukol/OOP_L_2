#include "Sourse.h"
#include "Data.h"
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
	surname = sourse.surname;
	phone = sourse.phone;
	date = sourse.date;
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
////////////////////////////////////////////////////////////////////////////////

QueueHousing::QueueHousing(PartyQueue * sourse, int n)
{
	for (int i = 0; i < n; i++)
	{
		data.push(sourse[i]);
	}
}

