#include "Sourse.h"
PartyQueue::PartyQueue()
{
	surname = "Surname";
	phone = "+1 202 - 456 - 1111";
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
PartyQueue::~PartyQueue()
{
	surname.~string();
	phone.~string();
	date.~Date();
}
bool PartyQueue::operator < (PartyQueue & right)
{
	return this->date < right.date;
}
////////////////////////////////////////////////////////////////////////////////
QueueHousing::QueueHousing()
{

}

