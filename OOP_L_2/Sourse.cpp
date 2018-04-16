#include "Sourse.h"
PartyQueue::PartyQueue()
{
	surname = "Surname";
	phone = "+1202 - 456 - 1111";
}
PartyQueue::PartyQueue(string & Surname, string & Phone, Date & Date)
{
	surname = Surname;
	phone = Phone;
	date = Date;
}